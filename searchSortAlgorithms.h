//Homework 34

/*
 * Filename:        searchSortAlgorithms.h
 * Purpose:         Definition and Implementation of linkedListType
 *                  class
 *
 * Author:          Zachary Charles Stewart
 * Student ID:      105903414
 * Created on       April 17, 2017, 4:16 PM
 */


//Preprocessor Directives
#ifndef SEARCHSORTALGORITHMS_H
#define SEARCHSORTALGORITHMS_H

#include <iostream>
#include <cstdlib>

using namespace std;

//--------------------------------------------------------------------------//

// Searching Algorithms

template <class elemType>
int seqSearch(const elemType list[], int length,  const elemType &item);

template <class elemType>
int binarySearch(const elemType list[], int length, const elemType &item);
// Sorting Algorithms

template <class elemType>
void bubbleSort(elemType list[], int length);

template <class elemType>
void selectionSort(elemType list[], int length);

template <class elemType>
void insertionSort(elemType list[], int length);

template <class elemType>
void quickSort(elemType list[], int length);
// Functions that Support the Sorting Algorithms

template <class elemType>
void swap(elemType list[], int first, int second);

template <class elemType>
int minLocation(elemType list[], int first, int last);

template <class elemType>
void recQuickSort(elemType list[], int first, int last);

template <class elemType>
int partition(elemType list[], int first, int last);

//--------------------------------------------------------------------------//
//Function Definitions

//Function:     seqSearch(const elemType list[], int length,  const elemType &item)
//
//Inputs:       const elemType list[], int length,  const elemType &item
//Outputs:      Return type int

template <class elemType>
int seqSearch(const elemType list[], int length,  const elemType &item)
{
    bool found = false;
    int temp = -1;
    int i = 0;
    while(!found && i < length)
    {
        if(list[i] == item)
        {
            found = true;
            temp = i;

        }
        i++;
    }
    return temp;
}

//Function:     binarySearch(const elemType list[], int length, const elemType &item)
//
//Inputs:       const elemType list[], int length, const elemType &item
//Outputs:      Return type int

template <class elemType>
int binarySearch(const elemType list[], int length, const elemType &item)
{
    int first = 0;
    int last = length - 1;
    int mid;
    bool found = false;

    while(first <= last && !found)
    {
        mid = (first + last) / 2;
        if(list[mid] == item)
        {
            found = true;
        }
        else if(list[mid] > item)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
        if(found)
        {
            return mid;
        }
        else
        {
            return -1;
        }
    }
}

//Function:     bubbleSort(elemType list[], int length)
//
//Inputs:       elemType list[], int length
//Outputs:      Return type void

template <class elemType>
void bubbleSort(elemType list[], int length)
{
    for(int iteration = 1; iteration < length; iteration++)
    {
        for(int index = 0; index < length - iteration; index++)
        {
            if(list[index] > list[index + 1])
            {
                elemType temp = list[index];
                list[index] = list[index + 1];
                list[index + 1] = temp;
            }
        }
    }
}

//Function:     selectionSort(elemType list[], int length)
//
//Inputs:       elemType list[], int length
//Outputs:      Return type void

template <class elemType>
void selectionSort(elemType list[], int length)
{
    int loc, minIndex;
    for(loc = 0; loc < length; loc++)
    {
        minIndex = minLocation(list, loc, length - 1);
        swap(list, loc, minIndex);
    }
}

//Function:     insertionSort(elemType list[], int length)
//
//Inputs:       int firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++
//Outputs:      Return type void

template <class elemType>
void insertionSort(elemType list[], int length)
{
    for (int firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++)
    {
        if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
        {
            elemType temp = list[firstOutOfOrder];
            int location = firstOutOfOrder;
            do
            {
                list[location] = list[location - 1];
                location--;
            }while (location > 0 && list[location - 1] > temp);
            list[location] = temp;
        }
    }

}

//--------------------------------------------------------------------------//

//Function:     quickSort(elemType list[], int length)
//
//Inputs:       elemType list[], int length
//Outputs:      Return type void

template <class elemType>
void quickSort(elemType list[], int length)
{
    recQuickSort(list, 0, length - 1);
}
// Functions that Support the Sorting Algorithms

//Function:     swap(elemType list[], int first, int second)
//
//Inputs:       elemType list[], int first, int second
//Outputs:      Return type void
//Purpose:
template <class elemType>
void swap(elemType list[], int first, int second)
{
    elemType temp;

    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
}

//Function:     minLocation(elemType list[], int first, int last)
//
//Inputs:       elemType list[], int first, int last
//Outputs:      Return type int

template <class elemType>
int minLocation(elemType list[], int first, int last)
{
    int loc, minIndex;
    minIndex = first;
    for(loc = first + 1; loc <= last; loc++)
    {
        if(list[loc] < list[minIndex])
        {
            minIndex = loc;
        }
    }
    return minIndex;
}

//Function:     recQuickSort(elemType list[], int first, int last)
//
//Inputs:       elemType list[], int first, int last
//Outputs:      Return type void

template <class elemType>
void recQuickSort(elemType list[], int first, int last)
{
    int pivotLocation;
    if(first < last)
    {
        pivotLocation = partition(list, first, last);
        recQuickSort(list, first, pivotLocation - 1);
        recQuickSort(list, pivotLocation + 1, last);
    }
}

//Function:     partition(elemType list[], int first, int last)
//
//Inputs:       elemType list[], int first, int last
//Outputs:      Return type int

template <class elemType>
int partition(elemType list[], int first, int last)
{
    elemType pivot;
    int index, smallIndex;
    swap(list, first, (first + last)/2);

    pivot = list[first];
    smallIndex = first;
    for(index = first + 1; index <= last; index++)
    {
        if(list[index] < pivot)
        {
            smallIndex++;
            swap(list, smallIndex, index);
        }
    }
    swap(list, first, smallIndex);
    return smallIndex;
}

//--------------------------------------------------------------------------//

#endif /* SEARCHSORTALGORITHMS_H */

