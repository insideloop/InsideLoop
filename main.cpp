//==============================================================================
//
//                                  InsideLoop
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.txt for details.
//
//==============================================================================


#include <il/StaticArray2D.h>
#include <il/StaticArray.h>

#include <il/linear_algebra.h>

int main() {
 il::StaticArray2D<double, 2, 2> A{};
 il::StaticArray<double, 2> x{};

 auto y = il::dot(A, x);
 (void)y;

  return 0;
}
