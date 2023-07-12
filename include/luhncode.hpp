#pragma once
#include <cstddef>
#include <cstdint>
#include <span>
#include <string>
#include <type_traits>

#ifndef LUHNCODE_NO_SIMD
#include <immintrin.h>
#endif

inline const uint8_t arr[][10] = {
    {0, 2, 4, 6, 8, 1, 3, 5, 7, 9},
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
};

template<typename T>
concept CharT = std::is_same_v<T, uint8_t> || std::is_same_v<T, char>;

template<CharT T>
inline int luhncode(const T *const code) noexcept {
  int sum = 0;
  for (size_t i = 0; i < 16; ++i) {
    const uint8_t c = code[i] - '0';
    sum += arr[i & 1][c];
  }
  return sum;
}

template<CharT T>
inline int luhncode(std::span<T, 16> code) noexcept {
  return luhncode(code.data());
}

inline int luhncode(std::string s) noexcept {
  return luhncode(s.c_str());
}

#ifndef LUHNCODE_NO_SIMD

template <CharT T>
inline int luhncode_avx(const T *const code) noexcept {
  // load
  __m128i reg_ = _mm_loadu_si128((__m128i*)code);
  reg_ = _mm_sub_epi16(reg_, _mm_set1_epi8('0'));
  __m256i data = _mm256_cvtepi8_epi16(reg_);

  // Multiply
  const __m256i mul_mask = _mm256_setr_epi16(2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1);
  data = _mm256_mullo_epi16(mul_mask, data);

  // Sum digits
  const __m256i m = _mm256_set1_epi16(9);
  __m256i gt = _mm256_cmpgt_epi16(data, m);
  gt = _mm256_mullo_epi16(gt, m);
  data = _mm256_add_epi16(data, gt);

  // Sum over register
  data = _mm256_hadd_epi16(data, data);
  data = _mm256_hadd_epi16(data, data);
  data = _mm256_hadd_epi16(data, data);
  return _mm256_extract_epi16(data, 0) + _mm256_extract_epi16(data, 8);
}

template<CharT T>
inline int luhncode_avx(std::span<T, 16> code) noexcept {
  return luhncode_avx(code.data());
}

inline int luhncode_avx(std::string s) noexcept {
  return luhncode_avx(s.c_str());
}

#endif
