# Dynamic Tables

Dynamic tables as defined by my Algorithms course, are arrays that automatically resizes itself (doubles) if it gets full. 
This is a simple implementation that is supposed to show the difference in performance between a dynamic table/array and an
array that simply increases in size by one everytime it gets full.

Build the project by using

```bash
mkdir build
cd build
cmake ..
make
```
you should obtain the executable named `dynamicTable` in the `build` directory. All the testing is in the main of this
executable and should show the timing between the normal and dynamic array.
