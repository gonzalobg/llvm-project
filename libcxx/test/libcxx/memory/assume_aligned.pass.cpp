//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//

// <memory>
// UNSUPPORTED: c++03, c++11, c++14, c++17

// template<std::size_t N, typename T>
// [[nodiscard]] T* assume_aligned(T*);

#include <memory>

constexpr int test() {
  int a;
  int* b = std::assume_aligned<4>(&a);
  return sizeof(int);
}

int main(int, char**)
{
  constexpr int N = test();
  int* a = (int*)malloc(N);
  int* b = std::assume_aligned<4>(a);

  return 0;
}
