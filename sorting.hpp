/// @author: Carlos L. Cuenca
/// @date: 1/20/2018
/// @file: Sorting.hpp
/// @description: Template library for rudimentary
/// and common sorting algorithms.
/// These functions are written as generic as possible
/// to facilitate use across different types

#ifndef SORTING_HPP
#define SORTING_HPP

namespace Sorting {

    // ----------
    // Interface

    template <typename Type, typename Index>
    Type* bubbleSort    (Type* const, Index);

    template <typename Type, typename Index>
    Type* selectionSort (Type* const, Index);

    template <typename Type, typename Index>
    Type* insertionSort (Type* const, Index);

    template <typename Type, typename Index>
    Type* combSort      (Type* const, Index);

    template <typename Type, typename Index>
    Type* quickSort     (Type* const, Index);

    template <typename Type, typename Index>
    Type* mergeSort     (Type* const, Index);

    // ------------------
    // Utility Functions

    namespace Utility{

        template <typename Type, typename Index>
        inline void  swap        (Type* const, Index, Index);

        template <typename Type, typename Index>
        inline Type* reverse     (Type* const, Index);

        template <typename Type, typename Index>
        inline Type* innerQuick  (Type* const, Index, Index);

        template <typename Type, typename Index>
        inline Type* innerMerge  (Type* const, Index, Index);

        template <typename Type, typename Index>
        inline void  merge       (Type* const, Index, Index, Index);

    }

}

/// ========================
/// Implementation Functions

// ------------------------------------------
// Bubble Sort
// Time Complexity: O(n^2)
// Parameters: Type - set of elements of the Type,
// Elements - amount of elements in the array
// Return: pointer to the sorted array
template <typename Type, typename Index>
Type* Sorting::bubbleSort
(Type* const set, Index elements){

    // Swap Flag
    bool swapped = false;

    // Loop while we swapped
    while(swapped){

	// Reset the swap flag
	swapped = false;

        // Begin the nth loop
        for(Index index = 0;
            index < elements - 1; index++){

            // If the adjacent elements are out of place
            if(set[index] > set[index + 1]){

                // Swap the elements in the set
                Sorting::Utility::swap<Type, Index>(set, index, index + 1);

                // Flip the swap flag
                swapped = true;

            }
        }
    }

    // Finally, return the sorted set
    return set;

}

// ------------------------------------------
// Selection Sort
// Time Complexity: O(n^2)
// Parameters: Type - set of elements of the Type,
// Elements - amount of elements in the array
// Return: pointer to the sorted array
template <typename Type, typename Index>
Type* Sorting::selectionSort (Type* const set, Index elements){

    // Local
    Index lowestIndex;

    // Go through the entire array
    for(Index minIndex = 0; minIndex < elements; minIndex++){

        // Contextually the lowest
        lowestIndex = minIndex;

        // We're going to try to find the lowest index
        for(Index index = minIndex; index < elements; index++){

            // Contextually, the lowest index
            if(set[index] < set[lowestIndex]) lowestIndex = index;

        }

        // Swap the elements from the given point
        Sorting::Utility::swap<Type, Index>(set, minIndex, lowestIndex);

    }

    // Finally, return the sorted set
    return set;
}

// ------------------------------------------
// Insertion Sort
// Time Complexity: O(n^2)
// Parameters: Type - set of elements of the Type,
// Elements - amount of elements in the array
// Return: pointer to the sorted array
template <typename Type, typename Index>
Type* Sorting::insertionSort (Type* const set, Index elements){

    // Start looping at the second index
    for(Index index = 1; index < elements; index++){

        // Swap when the current index is greater than zero
        for(Index current = index;
            current && set[current] < set[current - 1]; current--){

            // Swap
            Sorting::Utility::swap<Type, Index>(set, current, current - 1);

        }

    }

    // Finally, return the sorted set
    return set;
}

// ------------------------------------------
// Comb Sort
// Time Complexity: O(nlog(n))
// Parameters: Type - set of elements of the Type,
// Elements - amount of elements in the array
// Return: pointer to the sorted array
template <typename Type, typename Index>
Type* Sorting::combSort      (Type* const set, Index elements){

    // Locals
    Index  gap    = elements ;
    double shrink = 1.3      ;
    bool   sorted = false    ;

    while(!sorted){

        // Update the gap value for a next comb
        // Make round it down (Truncated)
        gap /= shrink;

        // If the gap isn't one
        if(gap > 1) sorted = false;
        else{

            // Set the gap to one, and enable the falg
            gap    = 1    ;
            sorted = true ;

        }

        // We're going to look for elements to swap
        for(Index index = 0; index + gap < elements; index++){

            // If there's a proper condition
            if(set[index] > set[index + gap]){

                // Swap
                Sorting::Utility::swap<Type, Index>(set, index, index + gap);
                sorted = false;
            }

        }

    }

    return set;
}

// ------------------------------------------
// Quick Sort
// Time Complexity: O(nlog(n))
// Parameters: Type - set of elements of the Type,
// Elements - amount of elements in the array
// Return: pointer to the sorted array
template <typename Type, typename Index>
Type* Sorting::quickSort     (Type* const set, Index elements){

    // Since we want a uniform interface
    return Sorting::Utility::innerQuick<Type, Index>(set, 0, elements - 1);

}

// ------------------------------------------
// Merge Sort
// Time Complexity: O(nlogn)
// Parameters: Type - set of elements of the Type,
// Elements - amount of elements in the array
// Return: Pointer to the sorted array
template <typename Type, typename Index>
Type* Sorting::mergeSort     (Type* const set, Index elements){

    // Since we want a uniform interface
    return Sorting::Utility::innerMerge<Type, Index>(set, 0, elements - 1);

}

/// =================
/// Utility Functions

// ---------------------------------------------------------
// Swap
// Basic Swap function implemented using template arguements
template <typename Type, typename Index>
inline void Sorting::Utility::swap(Type* const set, Index alpha, Index beta){

    // Set the buffer
    Type buffer = set[alpha];

    // Swap the first
    set[alpha]  = set[beta];

    // Then the second
    set[beta]   = buffer;

}

// ------------------------------------------
// Quicksort inner function
// Note: we keep this to preserve a uniform interface
// with the rest of the library
template <typename Type, typename Index>
inline Type* Sorting::Utility::innerQuick(Type* const set, Index lower, Index upper){

    // We want to set the call fram here
    // Pivot was calculated as such on purpose
    Index first = lower;
    Index last  = upper;
    Type  pivot = set[(first + last + 1)/2];

    while(first <= last){

        // If the value at the left most index is less than the pivot
        // increase the index value, until you get a proper condition
        while(set[first] < pivot) first++;

        // If the value at the rightmost index is greater than the pivot,
        // Decrease the value, until you get a proper condition
        while(set[last] > pivot) last--;

        // if the leftmost index value hasn't met the right most,
        // Swap the numbers
        if(first <= last){

            Sorting::Utility::swap<Type, Index>(set, first, last);
            first++;
            last--;

        }

    }

    // Call the function again, the lower bound,
    // is the argument for this call, and the upper bound has been
    // decremented past the pivot into the leftmost partition
    if(last  > lower) Sorting::Utility::innerQuick<Type, Index>(set, lower, last);


    // Call the function again, the first index is
    // the lower bound of the right most partition, and
    // the upper is the last element
    if(first < upper) Sorting::Utility::innerQuick<Type, Index>(set, first, upper);

    // Finally, return the set
    return set;
}



// --------------------------------------------------
// Mergesort inner function
// Note: we keep this to preserve a uniform interface
template <typename Type, typename Index>
inline Type* Sorting::Utility::innerMerge(Type* const set, Index left, Index right){

    // Exit condition
    if(left >= right) return set;

    // Calculate the midpoint
    Index midpoint = (left + right)/2;

    // Recursively call on both halves
    Sorting::Utility::innerMerge<Type, Index>(set, left, midpoint);
    Sorting::Utility::innerMerge<Type, Index>(set, midpoint + 1, right);

    // And then.. merge them
    Sorting::Utility::merge<Type, Index>(set, left, midpoint, right);

    // Finally, return the set
    return set;
}

// --------------------------------
// Merge Function
// Pointer variant
template <typename Type, typename Index>
inline void Sorting::Utility::merge(Type* const set, Index left, Index middle, Index right){

    // We want to set the call frame here
    Index leftIndex  = 0                 ;
    Index rightIndex = 0                 ;
    Index merged     = left              ;
    Index leftCalc   = middle - left + 1 ;
    Index rightCalc  = right - middle    ;

    // Create the buffers
    // Type leftArray  [leftCalc  ];
    // Type rightArray [rightCalc ];

    // Create the buffers
    // TODO: This is terrible form for various reasons
    // Look into VLA on the stack to replace this
    Type* leftArray  = new Type[leftCalc]  ;
    Type* rightArray = new Type[rightCalc] ;

    // Drop the elements into the left
    for(Index index = 0; index < middle - left + 1; index++)
        leftArray[index]  = set[left + index];

    // Drop the elements into the right
    for(Index index = 0; index < right - middle; index++)
        rightArray[index] = set[middle + index + 1];

    // We loop as long as both indices coincide with the number
    // of elements pertaining to each subset
    while(leftIndex < leftCalc && rightIndex < rightCalc){

        // If the left is greater or equal to the right
        if(leftArray[leftIndex] <= rightArray[rightIndex]){

            // Start setting the elements in the set
            // and update the index
            set[merged] = leftArray[leftIndex];
            leftIndex++;

            // Otherwise
        }else{

            // Drop the elements in the set from the right
            set[merged] = rightArray[rightIndex];
            rightIndex++;

        }

        // Update the current index
        merged++;

    }

    // Drop the remaining elements from the left
    while(leftIndex < leftCalc){
        set[merged] = leftArray[leftIndex];
        leftIndex++;
        merged++;
    }

    // Drop the remaining elements from the right
    while(rightIndex < rightCalc){
        set[merged] = rightArray[rightIndex];
        rightIndex++;
        merged++;
    }

    // Finally, clean up the mess
    delete[] leftArray;
    delete[] rightArray;

}

template<typename Type, typename Index>
inline Type* Sorting::Utility::reverse(Type* const set, Index elements){

    // Setting the call frame
    Index midpoint = elements / 2 ; // Calculate the midpoint
    Index last     = elements - 1 ; // Set the last index

    // Loop through and swap
    for(Index index = 0; index < midpoint; index++)
        Sorting::Utility::swap<Type, Index>(set, index, last - index);

    // Finally, return the set
    return set;

}


#endif
