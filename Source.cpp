//#include "Header.h"
#include <unordered_map>
#include <string>
#include <iostream>

class heap {
public:
    std::vector<int> bi_heap;
    int size;

    heap(int s) {
        bi_heap.push_back(s);
        size = 1;
    }

    void print() {
        for(auto s:bi_heap){
            std::cout << s << "\n";
        }
    }

    void heapify_rec(int i) {
        int largest = i;
        if (2 * i < size && bi_heap[2*i] > bi_heap[i]) {
            largest = 2;
        }
        if (2 * i + 1 < size && bi_heap[2 * i + 1] > bi_heap[i]) {
            largest = 2 * i + 1;
        }
        if (largest != i) {
            int tmp = bi_heap[largest];
            bi_heap[largest] = bi_heap[i];
            bi_heap[i] = tmp;
            heapify_rec(largest);
        }
        
    }

    void insert(int s) {
        bi_heap.push_back(s);
        return;
    }

};




int main(void) {
    heap *h = new heap(1);
    std::vector<int> bi_heap;
    h->insert(2);
    //bi_heap.push_back(1);
    //std::cout << bi_heap[0] << "\n";
    h->print();
}


