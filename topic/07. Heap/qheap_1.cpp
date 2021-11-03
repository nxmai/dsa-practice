//hackerrank
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int>heap;

void heapFilterUp(int index){
    if(index == 0)
        return;
    int parent = (index - 1)/2;
    if(heap[parent] > heap[index]){
        swap(heap[parent], heap[index]);
        heapFilterUp(parent);
    }
}

void heapFilterDown(int index){
    if(index >= heap.size()){
        return;
    }

    int left_child = 2*index + 1;
    int right_child = 2*index + 2;
  
    if(left_child >= heap.size()){
        return;
    }

    if(right_child < heap.size()){
        if(heap[index] < heap[left_child] && heap[index] < heap[right_child]){
            return;
        } else {
            if(heap[left_child] < heap[right_child]){
                swap(heap[left_child], heap[index]);
                heapFilterDown(left_child);
            } else{
                swap(heap[right_child], heap[index]);
                heapFilterDown(right_child);
            }
        }
    } else{
        if(heap[index] < heap[left_child]){
            return;
        } else{
            swap(heap[index], heap[left_child]);
            heapFilterDown(left_child);
        }
    }

}

void insertValue(int val){
    heap.push_back(val);
    heapFilterUp(heap.size() - 1);
}

// int deleteIndex;
int findIndex (int val, int i){
   
    for(int i = 0; i < heap.size(); i++){
        if(heap[i] == val){
            return i;
        }
    }
    return -1;
}

void deleteValue(int val){
    int index = findIndex(val, 0);
    
    swap(heap[index], heap[heap.size() - 1]);
    heap.pop_back();

    if(heap[index] < heap[(index - 1)/2]){
        heapFilterUp(index);
    } else{
        heapFilterDown(index);
    }
}


int main() {
    int n;
    int num, v;

    cin >> n;

    while(n!=0){
        cin >> num;
        if(num == 1){
            cin >> v;
            insertValue(v);
        } else if(num == 2){
            cin >> v;
            deleteValue(v);
        } else{
            cout << heap[0] << endl;
        }

        n--;
    }

    
    return 0;
}
