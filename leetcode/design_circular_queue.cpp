class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        q.resize(k);
        maxSize=k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        r = (r+1)%maxSize;
        q[r]=value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(f==r) f=0, r=-1;
        else f=(f+1)%maxSize;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[f];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return q[r];
    }
    
    bool isEmpty() {
        if(r==-1) return true;
        return false;
    }
    
    bool isFull() {
        if(!isEmpty() && (r+1)%maxSize==f) return true;
        return false;
    }
private:
    vector<int> q;
    int maxSize,f=0,r=-1;
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
