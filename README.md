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

## Recommended Interface(s)

Sorting requires certain operators to be overloaded for compilation.
In this context, Type refers to the Type in the set, and Index refers
to the Indexing type.

### Type Requirements

This interface should be implemented when designing a user-defined type; 
class or struct.

```c++

Type& operator=  (const Type& rightHandSide);
bool  operator== (const Type& rightHandSide);
bool  operator<  (const Type& rightHandSide);
bool  operator>  (const Type& rightHandSide);
bool  operator<= (const Type& rightHandSide);

```

### Index Requirements

This interface should be implemented when designing a user-defined indexing
type if one wishes to do so; 
class or struct.

```c++
Index& operator= (const Index& rightHandSize);
Index& operator= (const <Integral Type>& rightHandSide);

bool operator== (const Index& rightHandSide);
bool operator<  (const Index& rightHandSide);
bool operator>  (const Index& rightHandSide);
bool operator<= (const Index& rightHandSide);
bool operator>= (const Index& rightHandSide);

Index operator+ (const Index& rightHandSide);
Index operator- (const Index& rightHandSide);
Index operator+ (const <Integral Type>& rightHandSide);
Index operator- (const <Integral Type>& rightHandSide);

Index& operator-- ();
Index& operator++ ();

Type& operator[] (const Index& rightHandSide);
Type& operator[] (const <Integral Type>& rightHandSide);

const Type& operator[] (const Index& rightHandSide);
const Type& operator[] (const <Integral Type>& rightHandSide);

```

Alternatively, one can use c++'s primitives or fixed-width integer types.

```c++

// Standard
unsigned short ;
unsigned int   ; 
unsigned long  ;

signed short ;
signed int   ;
signed long  ;

// Fixed-Width
uint16_t;
uint32_t;
uint64_t;

int16_t;
int32_t;
int64_t;

```

## Additional Notes

There was plenty of time poured into making this as readable as possible, as well as worthy for practical use.This by no means is a definitive list of sorting algorithms, or authority on performance or implementation. 

Comments, Questions, Concerns etc.. are welcomed.

## Author(s)

 **Carlos L. Cuenca - 2018**
