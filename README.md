# Sorting

Implementation of various rudimentary sorting algorithms in C++ found throughout the internet and assignments using template functions.

## Design Philosophy

* **Implement Algorithms in such a way that can be used by any type and support any binary width for indexing**
* **Leverage use of C/C++'s operator overloading to support user-defined types**
* **No dependencies**
* **Readability**

## Implementation

* **Bubble Sort**
* **Selection Sort**
* **Insertion Sort**
* **Comb Sort**
* **Quick Sort**
* **Merge Sort**

## Documentation

Currently, there is no "formal" documentation for the library. Additionally, the source will follow the following comment 
template:

### Headers/Implementation Files

```C++
// Author(s)
// Date
// Files
// Notes
```

### Functions

```C++
// Algorithm Name - Variant
// Time Complexity
// Parameters
// Return Value
```

## Sample Usage

Place the header wherever in your project folder

```C++
#include "Sorting.hpp"

int main(int argc, char*[] argv){

        //....Some Code here ....

        // Sample array
        int array[32] = {0,3,5,6,3,2,2,2,0,1,9,23,45,32,234,34,34,
        45,45,223,434,234,642,63234,112233,63234,632422,33,22,9,3,4};

        // Call quicksort
        Sorting::quickSort<int, int>(array, 32);

        // Finished sorting
        //....More Code here ....

        return 0;
}

```

## Compilation 

Sorting has currently been compiled on:

*Debian* 9.3 using *clang++* 
```shell
user@machine: clang++ -Werror -Weverything -Wall -pedantic -pedantic-errors -std=c++11 -o3 <source>
```
*Debian* 9.3 using *g++* 
```shell
user@machine: g++ -Werror -Wall -pedantic -pedantic-errors -std=c++11 -o3 <source>
```

## Benchmarks & Performance

At the time of writing, there was a simple main that was written to test for bugs. However, the functions themselves have not been performance tested, or checked for memory leaks. There will be, hopefully, a report coming soon

## Additional Notes

There was plenty of time poured into making this as readable as possible, as well as worthy for practical use. Understandably, there are other libraries out there that include better implementations for sorting; this was more of a test-run of 'production' code and a thought exercise. This by no means is a definitive list of sorting algorithms, or authority on performance or implementation. 

Comments, Questions, Concerns etc.. are welcomed.

## Author(s)

 **Carlos L. Cuenca - 2018**
