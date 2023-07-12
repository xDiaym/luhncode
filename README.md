# Luhncode

Attempt to use AVX2 to speed up the Luhn algorithm

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
luhncode_avx_bench/1048576/iterations:10    4098808 ns      4089387 ns           10
luhncode_bench/1048576/iterations:10        5723602 ns      5711503 ns           10

```
</details>
