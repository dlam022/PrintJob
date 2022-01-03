#ifndef _HEAP_H
#define _HEAP_H

#include "PrintJob.h"

using namespace std;

const static int MAX_HEAP_SIZE = 10;

class Heap {
  public:
    //Initializes an empty heap
    Heap();
    //inserts a PrintJob to the heap without violating max-heap properties
    void enqueue(PrintJob* job);
    //Removes the node with highest priority from the heap. Follow the algorithm on priority-queue slides
    void dequeue();
    //returns the node with highest priority
    PrintJob* highest()const;
    //Prints the PrintJob with the highest priority in the following format:
    //Priority: priorty, Job Number: jobnum, Number of Pages: numPages (add a new line at the end)
    void print();

  private:
    PrintJob* arr_[MAX_HEAP_SIZE]; //this is an array of PrintJob pointers
    int numItems_; //current number of items in heap

    //this functions is called by dequeue function to move the new root down the heap to the appropriate location
    void trickleDown(int x);

    int parent(int i); //return parent of Arr[i]
    int left(int i); //return left child of Arr[i]
    int right(int i); //return right child of arr[i]
    //You can include additional private helper functions here
    void swap(int i, int x);
};

#endif
