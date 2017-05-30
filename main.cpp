//==============================================================================
//
//                                  InsideLoop
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.txt for details.
//
//==============================================================================

#include <iostream>

#include <il/String.h>
#include <il/unicode.h>

int main() {
  il::String string{};
  string.append(10, il::Unicode::smiling_face_with_horns);

  std::cout << string.c_string() << std::endl;

  return 0;
}