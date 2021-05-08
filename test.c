#include <stdlib.h>
#include "leak_detector.h"

int main(){
  atexit(report_mem_leak);
  free((void*)12345);
  int *p;
  for (int i = 0; i < 3; i++) p = malloc(sizeof(int)*(i+1));
  return 0;
}
