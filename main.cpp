//==============================================================================
//
//                                  InsideLoop
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.txt for details.
//
//==============================================================================


#include <iostream>

#include <il/container/info/Info.h>

int main() {
  il::Info info{};
  info.set("line", il::int_t{30});
  info.set("inside", 3.14159);

  il::int_t line;
  il::int_t i = info.search("line");
  if (info.found(i) && info.is_integer(i)) {
    line = info.to_integer(i);
  }
  double inside;
  i = info.search("inside");
  if (info.found(i) && info.is_double(i)) {
    inside = info.to_double(i);
  }

  IL_UNUSED(line);
  IL_UNUSED(inside);

  return 0;
}