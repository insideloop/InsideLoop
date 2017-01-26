//==============================================================================
//
//                                  InsideLoop
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.txt for details.
//
//==============================================================================

#include <il/linear_algebra/dense/blas/dot.h>

int main() {
  il::StaticArray2D<double, 2, 3> A{0.0};
  il::StaticArray<double, 2> x{0.0};

  auto y = il::dot(A, il::Blas::transpose, x);

  return 0;
}
