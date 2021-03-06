/*
 * Copyright 2020 The TensorFlow Runtime Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//===- common.h -------------------------------------------------*- C++ -*-===//
//
// Unit test helpers for GPU wrapper tests.
//
//===----------------------------------------------------------------------===//
#ifndef THIRD_PARTY_TF_RUNTIME_CPP_TESTS_GPU_STREAM_COMMON_H_
#define THIRD_PARTY_TF_RUNTIME_CPP_TESTS_GPU_STREAM_COMMON_H_

#include <ostream>
#include <string>

#include "gtest/gtest.h"
#include "llvm/Support/Error.h"
#include "llvm/Support/raw_os_ostream.h"
#include "tfrt/cpp_tests/error_util.h"
#include "tfrt/gpu/stream/stream_wrapper.h"

namespace tfrt {
namespace gpu {
namespace stream {

// Google Test outputs to std::ostream. Provide ADL'able overloads.
template <typename T>
std::ostream& operator<<(std::ostream& os, T item) {
  llvm::raw_os_ostream raw_os(os);
  raw_os << item;
  return os;
}

class Test : public testing::TestWithParam<Platform> {};

}  // namespace stream
}  // namespace gpu
}  // namespace tfrt

#endif  // THIRD_PARTY_TF_RUNTIME_CPP_TESTS_GPU_STREAM_COMMON_H_
