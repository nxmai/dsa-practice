#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:
        vector<int>qu;
        int front = -1;
        int rear = -1;
        int n = 0;
        int num;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        for(int i=0;i<k;i++){
            qu.push_back(-1);
        }
        num=k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(n == 0){
            qu[0]=value;
            rear = 0;
            front = 0;
            n++;
            return true;
        }
        else if(n < num){
            rear = (rear+1) % num;
            qu[rear] = value;
            n++;
            return true;
        }
        else 
            return false;
        
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(n==0)
            return false;
        else{
            front = (front + 1)%num;
            n--;
            return true;
        }
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(n==0)
            return -1;
        else
            return qu[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(n==0)
            return -1;
        else
            return qu[rear];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(n==0)
            return true;
        else
            return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if(n==num)
            return true;
        else
            return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */