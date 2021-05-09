#include <stdlib.h>
#include "leak_detector.h"

void spew_leak(){
  malloc(4);
}
