# High Performance Convolutions

## Acknowledgements

Hardware: Testing hardware supplied Colfax
Software: Some of code is adapted from Intel Examples

## What it Does

The application takes an input of large PNG image, reads it, apply various filters. Initially the performance statistics of the edge detection are presented in this readme.

## How it Works

The programme is built and executed with 8 various configurations as to explore various system/architecture/microarchitecture features. 

1: Simple naive approach
2: SIMD
3: Threads/OpenMP
4: MCDRAM
5: Memkind
6: Non-temporal
7: pngByte
8: MPI

## Hardware

Intel Xeon Phi 7210 processor
64 Cores, 4 way hyper-threading => 64x4=256 cores

## Software

*   "Intel(R) C++ Intel(R) 64 Compiler for applications running on Intel(R) 64, Version 17.0.2.174 Build 20170213"
*   Intel Xeon Phi process with AVX512 support
  
        
## Performance Measurements

|Edge Detection|Time/ms|GB/s|GFLOP/s|
|---|---|---|---|
|1:Naive|477.8|0.6|1.4|
|2:SIMD|40.4|7.1|16.0|
|3:Threads|7.5|38.7|87.1|
|4:MCDRAM|1.3|222.0|499.5|
|5:Memkind|1.2|235.7|530.4|
|6:Non-temporal|0.9|312.6|703.4|
|7:pngByte|0.6|112.8|1014.8|
|8:MPI|0.4|171.1|1539.7|