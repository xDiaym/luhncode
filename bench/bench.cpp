#include <luhncode.hpp>
#include <benchmark/benchmark.h>


void luhncode_avx_bench(benchmark::State& state) {
  char str[] = "1234567891011121";
  for (auto _ : state) {
    int x = luhncode_avx(str);
    benchmark::DoNotOptimize(x);
  }
}
BENCHMARK(luhncode_avx_bench)->Iterations(1'000'000'000);


void luhncode_bench(benchmark::State& state) {
  char str[] = "9101112112345678";
  for (auto _ : state) {
    int x = luhncode(str);
    benchmark::DoNotOptimize(x);
  }
}
BENCHMARK(luhncode_bench)->Iterations(1'000'000'000);


BENCHMARK_MAIN();
