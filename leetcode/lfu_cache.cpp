struct Node{
    int key;
    int value;
    int freq;
    list<int> :: const_iterator it;
};

class LFUCache {
private:
    int capacity;
    int minFreq;
    unordered_map<int,Node> keyToNode;
    unordered_map<int,list<int>> freqToList;

    void touch(Node & node){
        // update cooresponding frequency
        const int preqFreq = node.freq;
        const int newFreq = ++node.freq;

        // remove the iterator for prev. freq. list
        freqToList[preqFreq].erase(node.it);
        if(freqToList[preqFreq].empty()){
            freqToList.erase(preqFreq);

            // updating minfreq if is not the least currently (or something like that)
            if(preqFreq == minFreq) ++minFreq;
        }
        // insert the key to front of newFreq's list
        freqToList[newFreq].push_front(node.key);
        node.it = cbegin(freqToList[newFreq]);
    }

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0 ){}
    
    int get(int key) {
        if(!keyToNode.count(key)) return -1;

        Node& node = keyToNode[key];
        touch(node);
        return node.value;
    }
    
    void put(int key, int value) {
        if(!capacity) return;

        if(keyToNode.count(key)){
            Node& node = keyToNode[key];
            node.value = value;
            touch(node);
            return;
        }
        if(keyToNode.size() == capacity){
            const int keyToEvict = freqToList[minFreq].back();
            freqToList[minFreq].pop_back();
            keyToNode.erase(keyToEvict);
        }
        minFreq=1;
        freqToList[1].push_front(key);
        keyToNode[key] = {key,value,1,cbegin(freqToList[1])};
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
