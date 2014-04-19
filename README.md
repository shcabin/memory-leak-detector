memory-leak-detector
====================

This is a simple memory leak detector for c.


This tool can only be used to detect memory leaks which allocated by c functions such as malloc() and alloc() etc.

The memory that allocated by c++ keywords, will not be tracked!
