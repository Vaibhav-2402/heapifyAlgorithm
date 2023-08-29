// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class heap {
    public:
    int arr[100];
    int size;
    
    heap() {
        arr[0] = -1;
        size = 0;
    }
    
    void insert(int d) {
        size++;
        int index = size;
        arr[index] = d;
        
        while(index > 1) {
            int parent = index/2;
            
            if(arr[index] > arr[parent]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }
    
    void deleteFromHeap() {
        if(size == 0) {
            cout << "Heap is already Empty !!! " << endl;
            return;
        }
        //step 1 : swap the root node with last node
        arr[1] = arr[size];
        
        //step 2 : delete the last node
        size--;
        
        //step 3 : take the node to the correct place
        
        int i = 1;
        while(i < size) {
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;
            
            if(leftIndex < size && arr[leftIndex] > arr[i]) {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            
            else if(rightIndex < size && arr[rightIndex] > arr[i]) {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else 
                return;
        }
        
    }
    
    
    void print() {
        for(int i = 1; i <= size; i++) {
            cout << arr[i] << "  ";
        }
        cout << endl;
    }
};

void heapify(int *arr, int n, int i) {
    
    int largest = i;
    
    int left = 2*i;
    int right = 2*i + 1;
    
    if(left < n && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]) {
        largest = right;
    }
    
    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

/* Heapify function for min heap

void heapify(vector<int> &arr, int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[smallest] > arr[left])
        smallest = left;

    if(right < n && arr[smallest] > arr[right])
        smallest = right;

    if(smallest != i) {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}
*/

int main() {
    heap h1;
    
    h1.insert(12);
    h1.insert(10);
    h1.insert(13);
    h1.insert(14);
    h1.insert(15);
    
    h1.print();
    
    h1.deleteFromHeap();
    
    h1.print();
    
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    
    for(int i = n/2; i > 0; i--) {
        heapify(arr, n, i);
    }
    
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
    

    return 0;
}