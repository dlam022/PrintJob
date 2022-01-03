#include "PrintJob.h"
#include "Heap.h"
#include <iostream>

using namespace std;

Heap::Heap() {
    numItems_ = 0;
}

void Heap::enqueue(PrintJob* job) {
    if(numItems_ < MAX_HEAP_SIZE) {
        arr_[numItems_] = job; 
        int temp = numItems_;
        numItems_++;
        while(temp != 0 && arr_[parent(temp)]->getPriority() < arr_[temp]->getPriority()) {
            swap(parent(temp), temp);
            temp = parent(temp);
        }
    }

}

void Heap::dequeue() { //removes the node with the highest priority from the heap
    if(numItems_ > 0) {
        PrintJob* job = arr_[0];
        arr_[0] = arr_[numItems_ - 1];
        numItems_--;
        delete(job);
        trickleDown(0);
    }
}

PrintJob* Heap::highest() const {
    if(numItems_ > 0) {
        return arr_[0];
    }
    else{
        return nullptr;
    }
}

void Heap::print() {
    cout << "Priority: " << arr_[0]->getPriority() << ", Job Number: " << arr_[0]->getJobNumber() << ", Number of Pages: " << arr_[0]->getPages() << endl;
}

int Heap::parent(int i) {
    return ((i-1) / 2);
}

int Heap::left(int i) {
    return (2 * i + 1);
}

int Heap::right(int i) {
    return (2 * i + 2);
}

void Heap::trickleDown(int x) {
    int r = right(x);
    int l = left(x);

    int largest = x;
    if(r < numItems_ && arr_[r]->getPriority() > arr_[largest]->getPriority()) {
        largest = r;
    }
    if(l < numItems_ && arr_[l]->getPriority() > arr_[largest]->getPriority()) {
        largest = l;
    }
    if(x != largest) {
        swap(x, largest);
        trickleDown(largest);
    }
    
}
void Heap::swap(int i, int x) {
    PrintJob* temp = arr_[i];
    arr_[i] = arr_[x];
    arr_[x] = temp;
}