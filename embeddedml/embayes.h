
#ifndef EMBAYES_H
#define EMBAYES_H

#include <stdint.h>
#include <math.h>


// TODO: use fixed-point
typedef struct _BayesSummary {
    float mean;
    float std;
} BayesSummary;

typedef struct _BayesModel {
   int32_t n_classes;
   int32_t n_features;
   BayesSummary *summaries;
} BayesModel;

// C.S. Turner, "A Fast Binary Logarithm Algorithm"
// https://stackoverflow.com/questions/4657468/fast-fixed-point-pow-log-exp-and-sqrt
static inline
int32_t embayes_log2fix (uint32_t x, size_t precision)
{
    int32_t b = 1U << (precision - 1);
    int32_t y = 0;

    if (precision < 1 || precision > 31) {
        //errno = EINVAL;
        return INT32_MAX; // indicates an error
    }

    if (x == 0) {
        return INT32_MIN; // represents negative infinity
    }

    while (x < 1U << precision) {
        x <<= 1;
        y -= 1U << precision;
    }

    while (x >= 2U << precision) {
        x >>= 1;
        y += 1U << precision;
    }

    uint64_t z = x;

    for (size_t i = 0; i < precision; i++) {
        z = z * z >> precision;
        if (z >= 2U << precision) {
            z >>= 1;
            y += b;
        }
        b >>= 1;
    }

    return y;
}

// log2 of normpdf
// approximated by a quadratic function
static val_t
embayes_logpdf_std(val_t x)
{
    const val_t a = VAL_FROMFLOAT(-0.7213475204444817);
    const val_t b = VAL_FROMFLOAT(-1.0005845727355313e-15);
    const val_t c = VAL_FROMFLOAT(-1.3257480647361592);

    const val_t axx = VAL_MUL(a, VAL_MUL(x, x));
    const val_t bx = VAL_MUL(b, x);
    const val_t y = axx + bx + c;
    return y;
}

// log2 of normal probability density function PDF
// using a scaled/translated standard distribution
static val_t
embayes_logpdf(val_t x, val_t mean, val_t std, val_t stdlog2)
{
   const val_t xm = val_div((x - mean), std);
   const val_t xx = (xm > 0) ? xm : -xm;
   const val_t p = embayes_logpdf_std(xx) - stdlog2;
   return p; 
}


int32_t
embayes_predict(BayesModel *model, float values[], int32_t values_length) {
   //printf("predict(%d), classes=%d features=%d\n",
   //      values_length, model->n_classes, model->n_features);

   const int MAX_CLASSES = 10;
   val_t class_probabilities[MAX_CLASSES] = {0,};

   for (int class_idx = 0; class_idx<model->n_classes; class_idx++) {

      val_t class_p = 0;
      for (int value_idx = 0; value_idx<values_length; value_idx++) {
         const int32_t summary_idx = class_idx*model->n_features + value_idx;
         BayesSummary summary = model->summaries[summary_idx];
         const float v = values[value_idx];

         const val_t stdlog2 = VAL_ONE; // FIXME: get from model parameters
         const val_t plog = embayes_logpdf(VAL_FROMFLOAT(v), VAL_FROMFLOAT(summary.mean), VAL_FROMFLOAT(summary.std), stdlog2);

         if ((class_p + plog) > 0) {
            // FIXME: underflows for more than -126
            // const float flog = log(VAL_TOFLOAT(pv));
            //printf("ERR %d=%f s=(%f, %f) : %f == %f | %f\n",
            //   value_idx, v, summary.mean, summary.std, flog, VAL_TOFLOAT(plog), VAL_TOFLOAT(class_p));
         } else {
            class_p += plog;
         }

      }
      class_probabilities[class_idx] = class_p;
      //printf("class %d : %f\n", class_idx, p);
   }

   val_t highest_prob = class_probabilities[0];
   int32_t highest_idx = 0;
   for (int class_idx = 1; class_idx<model->n_classes; class_idx++) {
      const val_t p = class_probabilities[class_idx]; 
      if (p > highest_prob) {
         highest_prob = p;
         highest_idx = class_idx;
      }
   }
   return highest_idx;
}

#endif // EMBAYES_H