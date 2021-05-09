#include <stdlib.h>

// This macro must be only define in a translation unit
// containing maib
#define DEFINE_MEM_LEAK_DETECTOR_VARIABLES
#include "leak_detector.h"

extern void spew_leak(void);

int main(){
  atexit(report_mem_leak);
  free((void*)12345);
  int *p;
  for (int i = 0; i < 3; i++) p = malloc(sizeof(int)*(i+1));
  spew_leak();
  return 0;
}
