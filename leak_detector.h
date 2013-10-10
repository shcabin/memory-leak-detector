#ifndef  LEAK_DETECTOR_H
#define  LEAK_DETECTOR_H
void * xrealloc (void *str,int size,const char *file,unsigned int line);
void * xmalloc(unsigned int size, const char * file, unsigned int line);
void * xcalloc(unsigned int elements, unsigned int size, const char * file, unsigned int line);
char * xstrdup (const char *str, const char * file, unsigned int line);
void xfree(void * mem_ref);

#define  realloc(str,size)			xrealloc(str,size, __FILE__, __LINE__)
#define  strdup(str)				xstrdup(str, __FILE__, __LINE__)
#define  malloc(size)				xmalloc(size, __FILE__, __LINE__)
#define  calloc(elements, size)		xcalloc(elements, size, __FILE__, __LINE__)
#define  free(mem_ref)				xfree(mem_ref)

void report_mem_leak(void);

#endif

