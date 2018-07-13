
#ifndef DETECTBIRDS_H
#define DETECTBIRDS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

#include "fft.h"

// FIXME: actually include emtrees
//#include <emtrees.h>
typedef struct {} EmtreesModel;
int32_t
emtrees_predict(EmtreesModel *m, float *f, int32_t l) {
    return 0;
}
EmtreesModel *birddetect_model = NULL;


typedef struct _EmGoertzel {
    float sine;
    float cosine;
} EmGoertzel;

EmGoertzel
emgoertzel_coefficients(int frequency, int n_samples, int sr)
{
    const float samples = (float)n_samples;
    const float k = (int)(0.5 + ((samples * frequency) / sr));
    const float omega = (2.0 * M_PI * k) / samples;
    const EmGoertzel c  = { sin(omega), cos(omega) }; 
    return c;
}


float
emgoertzel_run(EmGoertzel c, const float* data, int n_samples)
{
    const float coeff = 2.0 * c.cosine;
    float q0=0;
    float q1=0;
    float q2=0;

    for(int i=0; i<n_samples; i++) {
        q0 = coeff * q1 - q2 + data[i];
        q2 = q1;
        q1 = q0;
    }
 
    const float scale = n_samples / 2.0;
    const float real = (q1 - q2 * c.cosine) / scale;
    const float imag = (q2 * c.sine) / scale;

    const float magnitude = sqrtf(real*real + imag*imag);
    return magnitude;
}

// emaudio.h
typedef struct {
    float *data;
    size_t length;
} EmVector;

// Double buffering
typedef struct _EmAudioBufferer {
    int buffer_length;
    float *buffer1;
    float *buffer2;

    float *write_buffer;
    float *read_buffer;
    int write_offset;
} EmAudioBufferer;

void
emaudio_bufferer_reset(EmAudioBufferer *self) {
    self->write_buffer = self->buffer1;
    self->read_buffer = NULL;
    self->write_offset = 0;
}

int
emaudio_bufferer_add(EmAudioBufferer *self, int16_t s) {

    self->write_buffer[self->write_offset++] = (float)s/INT16_MAX; 

    if (self->write_offset == self->buffer_length) {
        // FIXME: error if read_buffer has not been cleared
        self->write_offset = 0;
        self->read_buffer = self->write_buffer;
        self->write_buffer = (self->read_buffer == self->buffer1) ? self->buffer2 : self->buffer1;
        return 1;
    } else {
        return 0;
    }
}

int
emvector_shift(EmVector a, int amount)
{
    if (abs(amount) >= a.length) {
        return -2; // non-sensical
    }

    if (amount == 0) {
        return 0;
    } else if (amount > 0) {
        return -1; // TODO: implement
    } else {
        for (int i=a.length+amount; i<a.length; i++) {  
            a.data[i+amount] = a.data[i];
        }
        return 0;
    }
}

int
emvector_set(EmVector dest, EmVector source, int location) {
    const int final_dest = source.length+location;
    if (final_dest > dest.length) {
        return -1;
    }
    if (location < 0) {
        return -2;
    }

    for (int i=location; i<final_dest; i++) {
        dest.data[i] = source.data[i-location]; 
    }
    return 0;
}


#define EMAUDIO_FFT_LENGTH 1024
#define FFT_TABLE_SIZE EMAUDIO_FFT_LENGTH/2

int
emaudio_rfft(EmVector audio, EmVector bins) {  

    // FIXME: change to floats
    double real[EMAUDIO_FFT_LENGTH];
    double imag[EMAUDIO_FFT_LENGTH];

    // FIXME: change to floats, pass in from outside
	double fft_cos[FFT_TABLE_SIZE];
	double fft_sin[FFT_TABLE_SIZE];
    FFTTable fft = { FFT_TABLE_SIZE, fft_cos, fft_sin };
    fft_table_fill(fft, EMAUDIO_FFT_LENGTH);

    if (audio.length != EMAUDIO_FFT_LENGTH) {
        return -1;
    }
    if (bins.length != EMAUDIO_FFT_LENGTH) {
        return -2;
    }

    for (int i=0; i<EMAUDIO_FFT_LENGTH; i++) {
        real[i] = audio.data[i];
        imag[i] = 0.0;
    }

    fft_table_transform(fft, real, imag, EMAUDIO_FFT_LENGTH);

    for (int i=0; i<EMAUDIO_FFT_LENGTH; i++) {
        bins.data[i] = real[i];
    }

    return 0;
}

void
emaudio_melspec(EmVector audio, EmVector mels) {
    // FIXME: implement triangular filters
}



// birddetector.h
typedef struct _BirdDetector {
    int n_frames;
    EmVector features;
    EmtreesModel *model;
} BirdDetector;

bool birddetector_classify_frame(BirdDetector *self, EmVector audio) {
    const int mels_length = 128;
    float mels_data[mels_length];
    EmVector mels = { mels_data, mels_length };

    // FIXME: need to consider SFT and the overlapping windows
    // for instance use 2 consecutive audio frames and use midpoint as center of window

    //emaudio_sft(audio, bins);
    //emaudio_melspec(bins, mels);

    // FIXME: summarize frames into features

    //emaudio_shift_features(features, frame_features);

    const int32_t cl = emtrees_predict(self->model, self->features.data, self->features.length);
    return cl == 1;
}

#ifdef __cplusplus
} // extern "C"
#endif

#endif // DETECTBIRDS_H

