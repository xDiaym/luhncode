#include <memory>
#include <vector>
#include <cstdlib>
#include <luhncode.hpp>
#include <benchmark/benchmark.h>


std::vector<char[16]> generate(size_t n) {
  srand(0);
  std::vector<char[16]> v(n);
  for (auto& i : v)
    for (auto& c : i)
      c = rand() % 10 + '0';
  return v;
}


void luhncode_avx_bench(benchmark::State& state) {
  auto v = generate(state.range(0));
  for (auto _ : state) {
    for (auto&& str : v) {
      int x = luhncode_avx(str);
      benchmark::DoNotOptimize(x);
    }
  }
}
BENCHMARK(luhncode_avx_bench)
    ->Iterations(10)
    ->Arg(1 << 20);


void luhncode_bench(benchmark::State& state) {
  auto v = generate(state.range(0));
  for (auto _ : state) {
    for (auto&& str : v) {
      int x = luhncode(str);
      benchmark::DoNotOptimize(x);
    }
  }
}
BENCHMARK(luhncode_bench)
    ->Iterations(10)
    ->Arg(1 << 20);


BENCHMARK_MAIN();
