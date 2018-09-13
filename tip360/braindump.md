## Scope
The application area focus is monitoring of domestic animals in farming,
and monitoring of wildlife.

Technical focus is primarily Passive Acoustic sensors,
where each sensor works indepdendently with one or a few microphones.

 and no active transducer.
Multichannel audio is within scope, but multi-sensor microphone fusion. 

Several aspects of the design may be transferrable to other medium-bandwidth sensor technologies,
such as vibration/accelerometer data or low-resolution imaging (visible,infrared).
This is generaly out-of-scope, but it may be relevant to comment briefly on this in the report.


## Terms

* Wireless Sensor Network.
* Wireless acoustic sensor networks.
* Wireless multimedia sensor networks.

## Topics

* Data compression.
* Compressive sensing.
* On-edge machine learning.
* Audio coding.
* Network topology. Mesh,Star. Routing, Flooding

## Literature


### Wireless Sensor Networks

[The Evolution of Wireless Sensor Networks](). Silicon Labs. Whitepaper.
Shows how using a star/mesh network can decrease the transmission power per device, and total power.


[The Design Space of Wireless Sensor Networks](http://www.vs.inf.ethz.ch/publ/papers/wsn-designspace.pdf). Römer. 2004.

[Wireless sensor network survey](https://www.sciencedirect.com/science/article/pii/S1389128608001254). Yick, 2008. !!

### Energy efficiency in Wireless Sensor Networks

[Energy harvesting in wireless sensor networks: A comprehensive review](https://www.sciencedirect.com/science/article/pii/S1364032115012629). 2015. Comprehensive taxonomy of the various energy harvesting sources. Energy prediction models. Challenges.

[Energy conservation in wireless sensor networks: A survey](https://www.sciencedirect.com/science/article/pii/S1570870508000954). Giuseppe Anastasi, 2009. 

[Energy efficiency in wireless sensor networks: A top-down survey](https://www.sciencedirect.com/science/article/pii/S1389128614001418). TifennRault, 2014. Taxonomy of WSN applications. !!

[Survey of image compression algorithms in wireless sensor networks](https://ieeexplore.ieee.org/abstract/document/4631875/). 2008.
A review on eight popular image compression algorithms.
Found that Set-Partitioning in Hierarchical Trees (SPIHT) wavelet-based image compression best.
High compression efficiency and its simplicity in coding


### Wireless Acoustic Sensor Networks

[MEMS microphones for wireless applications](https://www.sciencedirect.com/science/article/pii/B9780081004494000087).


[Audio coding in wireless acoustic sensor networks](https://dl.acm.org/citation.cfm?id=2802336). Zahedi, 2015. ACM, Signal Processing. !!
Combining the measurement and received message at each node instead of forwarding the received messages and separate encoding.
Propose to use the measurement as side information and thereby form a distributed source coding (DSC) problem.


[Development of high performance wireless sensor node for Acoustic application](www.academia.edu/download/44284004/Development_of_high_.pdf). Arul Prabahar A, 2013. !!

### Applied to environmental monitoring of animals

[Compressive Sensing for Efficiently Collecting Wildlife Sounds with Wireless Sensor Networks](https://ieeexplore.ieee.org/abstract/document/6289298/). 2012. !!
Determine a sparse base that best represents the audio information used for identifying the target species. As a proof-of-concept, we focus on anuran (frogs and toads). 98% classification rate can be achieved by using as little as 10% of the original data.

[On the effect of compression on the complexity characteristics of wireless acoustic sensor network signals](https://www.sciencedirect.com/science/article/pii/S0165168414003752). Tatlas, 2015. Wireless acoustic sensor network for environmental monitoring is considered.

[Evaluation of MPEG-7-Based Audio Descriptors for Animal Voice Recognition over Wireless Acoustic Sensor Networks](http://www.mdpi.com/1424-8220/16/5/717/htm). Joaquín Luque. Use of generic descriptors based on an MPEG-7 standard. Demonstrate it to be suitable to be used in the recognition of different patterns

[Compressive sensing in wireless sensor network for poultry acoustic monitoring](http://www.ijabe.org/index.php/ijabe/article/view/2148). 2017.
Zigbee based network.

[Wireless sensor networks for environmental research: A survey on limitations and challenges](https://ieeexplore.ieee.org/abstract/document/6624996/). 2013.

### Machine learning in WSNs

[Machine Learning in Wireless Sensor Networks: Algorithms, Strategies, and Applications](https://ieeexplore.ieee.org/abstract/document/6805162/). 2014. 120 citations. Likely many relevant for #embeddedml. !!
Extensive literature review over the period 2002-2013 machine learning methods that were used to address common issues in WSNs.
Provide a comparative guide to aid WSN designers in developing suitable machine learning solutions for their specific application challenges.

[Outlier Detection Techniques for Wireless Sensor Networks: A Survey]()

[Learning from data streams](https://link.springer.com/book/10.1007%2F3-540-73679-4). Book.

[Machine Learning Techniques Applied to Wireless Ad-Hoc Networks: Guide and Survey](https://ieeexplore.ieee.org/abstract/document/4496871/). 2007.

### Data compression

[Compressive sensing meets time–frequency: An overview of recent advances in time–frequency processing of sparse signals](https://www.sciencedirect.com/science/article/pii/S1051200417301665). 2018

[Energy-Aware Data Compression for Wireless Sensor Networks](https://ieeexplore.ieee.org/document/4217341/). Puthenpurayil, 2007.
Explores energy consumption tradeoffs associated with data compression, particularly lossless compression for acoustic signals.

[Data Compression in Wireless Sensor Network: A Survey](http://www.rroij.com/open-access/data-compression-in-wireless-sensornetwork-a-survey-.php?aid=47412). Chetna Bharat Mudgule. Mentions different approaches:

* Data aggregation (clustering,tree-based,chain,sector)
* Distributed Coding
* Predictive Coding. Linear Predictive coding.
* Transform-based Coding
DCT: Discrete Cosine Transform,
DWT: Discrete Wavelet Transform,
DKTL: Discrete  Karhunen-Loeve Transform,
Distributed Wavelet Transform-based Lifting (DWT-lifting),
Distributed Wavelet Transform-based Harr (DWT-Harr),
* Compressed Sensing.

[](https://www.scribd.com/document/74166695/A-Survey-on-Data-Compression-in-Wireless-Sensor-Networks).
In terms of power consumption, operation of a wireless sensor node can be dividedinto three parts:
sensing, processing, and transmission.
Among those three operations, it is known that the most power consuming task is data transmission.
Approximately, 80% of power consumed in each sensor node is used for data transmission.
Tested standard lossless compression algorithms, showing gain. But not enough memory on WSN nodes.
bzip2 (BWT algorithm), compress (LZE algorithm), LZO (LZ77), PPMd(PPM), and zlib (LZ77).
Coding by Ordering. Pipelined In-Network Compression. Distributed Compression

[A survey on data compression in wireless sensor networks](https://ieeexplore.ieee.org/document/1425113/). Kimura, 2005.
Coding by ordering, pipelined in-network compression, low-complexity video compression, and distributed compression

[DATA COMPRESSION FOR INFERENCE TASKS IN WIRELESS SENSOR NETWORKS](http://www.ws.binghamton.edu/fowler/Fowler%20Personal%20Page/Publications_files/PhD_Dissertation_Mo_Chen.pdf). Mo Chen, 2006. PhD thesis. !!
"using data compression methods as a tool for accomplishing the optimal trade-off between rate, energy, and accuracy in a sensor network"
"a primary task of multi-sensor systems is to make statistical inferences based on the data collected and shared throughout the sensor system
in the viewpoint of rate, energy, and accuracy, it is important to design data compression methods that enable rapid and low-energy
consumption sharing while causing only minimal degradation of the quantity of these inferences"

[Practical data compression in wireless sensor networks: A survey](https://www.sciencedirect.com/science/article/pii/S1084804511000555). TossapornSrisooksai, 2011.

[Linear Prediction for data compression and recovery enhancement in Wireless Sensors Networks](https://ieeexplore.ieee.org/document/7577156/).
Zakia Jellali, 2016. Linear Prediction Coding (LPC) as a sparsifying transform. Orthogonal Matching Pursuit (OMP) CS algorithm is used for original data recovery.

[Introduction to Compressed Sensing](http://www.dfg-spp1324.de/download/preprints/preprint093.pdf). !!

[Compressive Sensing](https://link.springer.com/referenceworkentry/10.1007%2F978-0-387-92920-0_6). 2011.
Introduction and overview on both theoretical and numerical aspects of compressive sensing

[Compressive Sensing by Random Convolution](https://epubs.siam.org/doi/abs/10.1137/08072975X). 2009. !!
Demonstrates that convolution with random waveform followed by random time-domain subsampling is a universally efficient compressive sensing strategy. 

[Distributed Compressive Sensing](https://arxiv.org/abs/0901.3403). 2009.

[Sparse Representations, Compressive Sensing and dictionaries for pattern recognition](https://ieeexplore.ieee.org/abstract/document/6166711/).
2011, Vishal M. Patel. !!
Compressive Sensing (CS), Sparse Representation (SR) and Dictionary Learning (DL). 
Recent works in SR and CS have shown that if sparsity in the recognition problem is properly harnessed then the choice of features is less critical. What becomes critical, however, is the number of features and the sparsity of representation

### Audio compression 

[The undersampled wireless acoustic sensor network scenario: Some preliminary results and open research issues](https://ieeexplore.ieee.org/abstract/document/5291252/). Sommer, 2009. Sampling at under the Nyquist rate. Transparent Acoustic Communication (TAC).
Ad-hoc network of microphones, called Distributed Portable Acoustic Sensor (DPAS) network.

[An energy efficient audio compression scheme using wavelet with dynamic difference detection technique in wireless sensor network](https://dl.acm.org/citation.cfm?id=2345456). 2012.
Energy-saving audio data compression technique for WMSN combining wavelet lifting with a newly proposed difference detection technique.

[An energy saving audio compression scheme for wireless multimedia sensor networks using spatio-temporal partial discrete wavelet transform](https://www.sciencedirect.com/science/article/pii/S004579061500316X). Partial discrete wavelet transform (PDWT). Exploit both spatial and temporal correlation of data together. Tree-based routing.

[Effect of downsampling and compressive sensing on audio-based continuous cough monitoring](https://ieeexplore.ieee.org/abstract/document/7319816/). 2015. 98% at full rate. Undersampling to 400Hz 90%. Sampling with compressive sensing at 100Hz also 90%.

[Compressive Sensing in Acoustic Imaging](https://link.springer.com/chapter/10.1007/978-3-319-16042-9_6). Part of book Compressed Sensing and its Applications. Covers Nearfield acoustic holography (NAH), Active sonar, medical ultrasound imaging.

[A compressive beamforming method](https://ieeexplore.ieee.org/abstract/document/4518185/). Direction of Arrival estimation.

## Hardware

NRF52832 only supports BLE5.0 with 1Mpbs.
NRF51 supports lower rates on Enhanced ShockBurst.
NRF52840 supports BLE5.0 long range at 125kbps. Up to 1km range.
[bt832x](http://www.fanstel.com/bt832x-bluetooth-5-module) NRF52832 board with 1km range.

https://www.digikey.no/product-detail/en/nordic-semiconductor-asa/NRF6936/1490-1061-ND/7175577