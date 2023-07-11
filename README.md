# Luhncode

Failed attempt to use AVX2 to speed up the Luhn algorithm

## Build
```shell
git clone git@github.com:xDiaym/luhncode.git
mkdir build && cd 
cmake ..
cmake --build .
```

## Benchmark
<details>
  <summary>Details</summary>
    
```
-----------------------------------------------------------------------------------
Benchmark                                         Time             CPU   Iterations
-----------------------------------------------------------------------------------
luhncode_avx_bench/iterations:1000000000      0.310 ns        0.307 ns   1000000000
luhncode_bench/iterations:1000000000          0.311 ns        0.309 ns   1000000000
```
</details>
