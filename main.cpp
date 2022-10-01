//Homework XX

/* 
 * Filename:        main.cpp
 * Purpose:      
 * 
 * Author:          Zachary Charles Stewart
 * Student ID:      105903414
 * Created on       April 17, 2017, 4:15 PM
 */

//Preprocessor Directives
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>

#include "unorderedLinkedList.h"
#include "searchSortAlgorithms.h"

//Namespace
using namespace std;

//--------------------------------------------------------------------------//
//
//Main Function
//
//Inputs:       int argc, char** argv
//Outputs:      int
//
//Purpose:      Main program file. Other necessary files are included here 
//              in order to be run

const int LIST_SIZE = 10000;

int main(int argc, char** argv) 
{
    
    int list1[LIST_SIZE] = {0};
    int list2[LIST_SIZE] = {0};
    int list3[LIST_SIZE] = {0};
    int list4[LIST_SIZE] = {0};
    unorderedLinkedList<int>* list5 = new unorderedLinkedList<int>;
    
    int input;
    double timeD;
    clock_t t;
    
    srand(time(NULL));
    
    for(int i = 0; i < LIST_SIZE; i++)
    {
        input = (rand() % 555555) + 15;
        
        list1[i] = input;
        list2[i] = input;
        list3[i] = input;
        list4[i] = input;
        list5->insertLast(input);
    }
    cout << scientific << setprecision(3);   
    t = clock();
    
    bubbleSort(list1, LIST_SIZE);
    
    t = clock() - t;
    timeD = (static_cast<double>(t))/CLOCKS_PER_SEC;
    cout << "Bubble Sort time:    " << timeD << " seconds." << endl;

    t = clock();
    
    selectionSort(list2, LIST_SIZE);
    
    t = clock() - t;
    timeD = (static_cast<double>(t))/CLOCKS_PER_SEC;
    cout << "Selection Sort time: " << timeD << " seconds." << endl;

    t = clock();
    
    insertionSort(list3, LIST_SIZE);
    
    t = clock() - t;
    timeD = (static_cast<double>(t))/CLOCKS_PER_SEC;
    cout << "Insertion Sort time: " 
         << timeD << " seconds." << endl;

    t = clock();
    
    quickSort(list4, LIST_SIZE);
    
    t = clock() - t;
    timeD = (static_cast<double>(t))/CLOCKS_PER_SEC;
    cout << "Quick Sort time:     " << timeD << " seconds." << endl;
    
    t = clock();
    
    list5->mergeSort();
    
    t = clock() - t;
    timeD = (static_cast<double>(t))/CLOCKS_PER_SEC;
    cout << "Merge Sort time:     " << timeD << endl;
    
            
            
    
    
    
    //Terminate program upon successful execution
    exit(EXIT_SUCCESS);
}

//--------------------------------------------------------------------------//

