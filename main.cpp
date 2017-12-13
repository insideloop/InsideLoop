//==============================================================================
//
// Copyright 2017 The InsideLoop Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//==============================================================================

#include <il/algorithmArray.h>

int main() {
  il::Array<double> v{il::value,
                      {-1.0, 1.0, 2.0, 3.0, -12, 1000.0, 10.0, 100.0}};

  const double x0 = il::min(v);
  const double x1 = il::max(v);
  const il::int_t i = il::findMin(v);
  const il::int_t j = il::findMax(v);

  return 0;
}
