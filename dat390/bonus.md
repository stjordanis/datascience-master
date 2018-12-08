
* `melspec-skm-rf`: Spherical k-means convolution kernels learning 


delta, lag/lead frames

Bag-of-Frames. Temporal ordering is ignored.
Inspired by Bag-of-Words success in text analysis / Natural Language Processing.

## Introduction to sound

- Overview. Sound processing systems.
Aquisition. Storage. Processing. Output.
Online versus offline.

Digital sound pipeline




- Acoustics

- audio mixtures

## Sources of sound

Biotropy
Anthrophy

- Source characteristics

Models of sound production

- Biological models sound production in animals.
Formants
- (Acoustic models of instruments)

Rotary motor. Very beneficial to know the number of rounds per revolution

Intra-class versus inter-class variation


- Environment characteristics
Noise. Stationary, quasi-stationary
Non-class sounds.
Distance to source(s). Changing level of target sound.
Reverberation.
Microphonics,vibrations.


- Receiver characteristics.
Frequency response.
Noise.



# Data augmentation

Respects invariants/properties of features. Modelling particular challenges.

- noise addition
- volume change
- frequency response change


* Random pitch shifting
* Time-shifting
* Time reversal
* Noise additions

# Machine Learning models

- Gaussian Mixtures, Hidden Markov Model

### Criterias for good features
Keep relevant info, remove irrelevant.
Robust against variations

What is needed for good audio classification?

* Volume independent
* Robust to mixtures of other sounds
* Handles intra-class variations. Different birdsong
* Can exploit frequency patterns
* Can exploit temporal patterns


Exact traits wanted is somewhat problem/sound dependent.

* Compact. Little redundancy
* Easy to learn from
* Computationally cheap

### Open-ended classification
Classification problems often formulated as a closed-set. 
But in reality this might be too limiting.
Previously unseen birds may migrate into an area.
New musical genres are invented all the time.
Challenge: Creating a taxonomy, or consistent ontology

## Psychoacoustics
(Brief)
Non-linearities.
Log-ish frequency. notes. mel scale, gammatone
False pitch
Shepherds tone. Octave repetition
Missing fundamental
Reflection pitch

Log-ish power. desibel. 
Loudness. Stevens power law.
sones.
phones, equal loudness contours

Critical bandwidth. Loudness in mixes dependent on distances in frequency
Masking. One sound can hide another.
Simultaneous masking. Loud High tone can mask low tone.
forward masking. tensof ms

Temporal compression

Binaural hearing.

Function of sound.
Speech. "point the eyes"
Audio event. what,where

Cocktail party problem. Source separation, multi-source attention



## Case study

Add feature representations

* low-level
* MFCC
* add delta frames
