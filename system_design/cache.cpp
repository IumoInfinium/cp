/*
Problem 
Have to design a cache. In which a user can insert, fetch, remove data and can also select the eviction policy during runtime. (eviction policy - protocol by which cache remove the key value pair. eg - LRU (Least Recently Used) - will remove the least used key first, TimeEviction - based upon certain time the cache will remove the key. etc)
*/

#include <bits/stdc++.h>

using namespace std;

class LinkedList{
public:
    int val;
    int key;
    LinkedList *prev;
    LinkedList *next;

    LinkedList(){
        val = 0;
        key = -1;
        prev = next = nullptr; 
    }

    LinkedList(int val, int key){
        this->key = key;
        this->val = val;
        prev = next = nullptr;
    }
};

class Cache{

private:
    std::unordered_map<int,int> mp;
    std::unordered_map<int, std::pair<LinkedList*,LinkedList*>> timer;
    LinkedList *countDummy, *headCount, *tailCount;
    LinkedList *timeDummy,*headTime, *tailTime;
    int time;
    int cache_size;
    int capacity;
    /*
    eviction policy types :
        0 = LRU (least used first)
        1 = Time Eviction (remove from cache upon certain time)
    */
    int eviction_policy;
public:
    Cache(){}
    Cache(int capacity){
        this->time = 0;
        this->cache_size = 0;
        this->eviction_policy = 0;
        this->capacity = capacity;

        headCount = tailCount = nullptr;
        this->countDummy = new LinkedList(INT_MAX, -1); 
        countDummy->next = headCount;

        headTime = tailTime = nullptr;
        this->timeDummy = new LinkedList(INT_MAX, -1); 
        timeDummy->next = headTime;
    }

    int getCacheSize(){
        return this->cache_size;
    }

    int insert(int key, int value){
        if(this->cache_size >= this->capacity) this->remove();

        if(mp.count(key)){
            this->update(key, value);
        }
        else{
            // add a new key, if already does not exists
            mp[key] = value;

            LinkedList *currCount = new LinkedList(1, key);
            if(this->cache_size == 0){
                countDummy->next = currCount;
                currCount->prev = countDummy;
                headCount = currCount;
            }
            else{
                tailCount->next = currCount;
                currCount->prev  = tailCount;
            }
            
            this->tailCount = currCount;  // update linked list edges
            LinkedList *currTime = new LinkedList(this->time++, key);

            if(this->cache_size == 0){
                timeDummy->next = currTime;
                currTime->prev = timeDummy;
                tailTime = currTime;
            }
            else{
                currTime->next = headTime;
                currTime->prev = timeDummy;
                headTime->prev = currTime;
                timeDummy->next = currTime; 
            }

            this->headTime = currTime;        // update linked list edges
            timer[key] = {currCount, currTime};

            cache_size++;
        }

        return cache_size;
    }
    
    void update(int key, int value){
        mp[key] = value;

        LinkedList *currCount, *currTime;

        currCount = timer[key].first;
        currTime = timer[key].second;
        
        // update time linked list
        currTime->val = this->time++;
        currTime->prev->next = currTime->next == nullptr ? nullptr : currTime->next;
        if(currTime->next != nullptr){
            currTime->next->prev = currTime->prev;
        }
        currTime->prev = timeDummy;
        
        if(currTime != timeDummy->next){
            currTime->next = timeDummy->next;
            timeDummy->next->prev = currTime;
        }
        timeDummy->next = currTime;

        headTime = currTime;

        // update count linked list
        currCount->val++;
        if(headCount == currCount && currCount == tailCount) return;
        else{
            while(currCount->prev && currCount->prev->val < currCount->val){
                currCount->prev->val = currCount->val ^ currCount->prev->val;
                currCount->val = currCount->prev->val ^ currCount->val;
                currCount->prev->val = currCount->val ^ currCount->prev->val;

                currCount = currCount->prev;
            }
            if(tailCount == timer[key].second){
                tailCount = currCount->prev;
            }
        }
    }

    int fetch(int key){

        if(!mp.count(key)) return 0;

        LinkedList *currCount = timer[key].first;
        LinkedList *currTime = timer[key].second;

        currCount->val++;

        LinkedList *tmp= currCount;
        while(tmp->prev && tmp->prev->val < tmp->val){
            swap(tmp->prev->val, tmp->val);
            swap(tmp->prev->key, tmp->key);
            tmp = tmp->prev;
        }

        currTime->val = time++;
        // if(currTime->prev == timeDummy) return mp[key];

        LinkedList *prevTime = currTime->prev;
        prevTime->next = currTime->next;
        
        currTime->next = timeDummy->next;
        currTime->prev = timeDummy;
        timeDummy->prev = currTime;
        timeDummy->next = currTime;

        headTime = currTime;
        if(prevTime->next == nullptr) tailTime = prevTime;
        if(currTime->next == nullptr) tailTime = currTime;
        cout << "(" << tailCount->key << ", " << tailCount->val << ") ";
        return mp[key];
    }

    void countList(){
        if(headCount == nullptr) return;
        cout <<"---xxx---\n";
        LinkedList *curr = headCount;
        while(curr != nullptr){
            cout << "(" << curr->key << ", " << curr->val << ") ";
            curr = curr->next;
        }
        cout << "\n";
        return;
    }
    void timeList(){
        if(headTime == nullptr) return;
        LinkedList *curr = headTime;
        while(curr != nullptr){
            cout << "(" << curr->key << ", " << curr->val << ") ";
            curr = curr->next;
        }
        cout << "\n";
        return;
    }
    
    int getCount(int key){
        if(!mp.count(key)) return 0;

        return timer[key].first->val;
    }

    int getTime(int key){
        if(!mp.count(key)) return 0;

        return timer[key].second->val;
    }

    void remove(int key){
        // if(mp.count(key)){
        //     mp.erase(key);
        //     timer.erase(key);
        // }
        // return;
        cout <<"GOT " << key << " key to remove" << endl;
        if(!mp.count(key)) return;

        cout << "Removing " << key << " ..." << endl;

        LinkedList *currCount = timer[key].first;
        LinkedList *currTime = timer[key].second;

        mp.erase(key);
        timer.erase(key);

        // remove nodes from count linked list
        if(currCount->prev && currCount->next){
            currCount->prev->next = currCount->next;
            currCount->next->prev = currCount->prev;
            if(headCount == currCount){
                headCount = currCount->next;
            }
        }
        else{
            // linked list edges
            if(currCount->next == nullptr){
                currCount->prev->next = nullptr;
                tailCount = nullptr;
                headCount = nullptr;
            }
            

        }
        currCount = currCount->prev = currCount->next = nullptr;
        delete currCount;

        // remove nodes from time linked list
        if(currTime->prev && currTime->next){
            currTime->prev->next = currTime->next;
            currTime->next->prev = currTime->prev;

            if(currTime == headTime){
                headTime = currTime->next;
            }
        }
        else{
            // linked list edges
            if(currTime->next == nullptr){
                currTime->prev->next = nullptr;
                tailTime = nullptr;
                headTime = nullptr;
            }
        }
        currTime = currTime->prev = currTime->next = nullptr;
        delete currTime;

        this->cache_size--;

        if(tailCount) 
            cout << tailCount->val << "<- count's tails"<< endl;
        return;
    }

    void remove(){
        switch (eviction_policy) {
            case 0:
                LRUDelete();
                break;
            
            case 1:
                timeEvictionDelete();
                break;
            default:
                break;
        }
        return;
    }

    void LRUDelete(){
        remove(tailCount->key);
        return;
    }

    void timeEvictionDelete(){
        remove(tailTime->key);
        return;
    }

    void setEvictionPolicy(int num){
        switch (num){
            case 0:
                std::cout << "setting eviction policy to LRU" << std::endl;
                this->eviction_policy = 0;
                break;
            case 1:
                std::cout << "setting eviction policy to time based" << std::endl;
                this->eviction_policy = 1;
                break;
            default:
                std::cout << "failed to do modify eviction policy" << std::endl; 
                break;
        }
        return;
    }
};


int main(){
    Cache collection = Cache(5);

    collection.setEvictionPolicy(3);

    collection.insert(1, 10);
    collection.insert(2, 20);
    collection.insert(3, 30);
    collection.insert(4, 50);
    // std::cout << collection.fetch(2) << std::endl;  
    // std::cout << collection.fetch(1) << std::endl;  
    // std::cout << collection.fetch(4) << std::endl;

    cout << "Current Eviction policy is LRU \n";
    cout << "Set eviction policy policy by (0/1) (LRU/TimeEviction) using 'policy <n>' \n";

    string s;
    while(true){
        cout << "> ";
        getline(cin, s);
        string cmd= "";
        string tmp = "";
        if(s.size() == 0)  break;

        int n = s.size();
        int idx = 0;
        while(idx < n && s[idx] != ' ') cmd+= s[idx++];
        idx++;

        // cout << cmd << "-- ";
        int value1  = -1;
        while(idx < n && s[idx] != ' ') tmp += s[idx++];
        try{
            if(tmp != "") value1 = stoi(tmp);
        }
        catch(int ex) {
            cout << "key failed" << value1 << "xx" << endl;
            exit(1);
        }
        tmp = "";
        // cout << value1 << "-- ";
        idx++;
        int value2 = -1;
        while(idx < n && s[idx] != ' ') tmp += s[idx++];
        try{
            if(tmp != "") value2 = stoi(tmp);
        }
        catch(int ex) {
            cout << "value failed" << value2 << "xx" << endl;
            exit(1);
        }
        
        
        // cout << value2 << "-- ";
        if(cmd == "insert"){
            cout << collection.insert(value1, value2) << endl;
        }
        else if(cmd == "fetch"){
            cout << collection.fetch(value1) << endl;
        }
        else if(cmd == "size"){
            cout <<collection.getCacheSize() << endl;
        }
        else if(cmd == "count"){
            cout <<collection.getCount(value1) << endl;
        }
        else if(cmd == "time"){
            cout <<collection.getTime(value1) << endl;
        }
        else if(cmd == "remove"){
            collection.remove(value1);
        }
        else if(cmd == "policy"){
            collection.setEvictionPolicy(value1);
        }
        else if(cmd == "timelist"){
            collection.timeList();
        }
        else if(cmd == "countlist"){
            collection.countList();
        }
        else if(cmd == "exit"){
            break;
        }
        else if(cmd == "help"){
            cout << "- 'insert <key> <value>' : Inserts a value in cache\n";
            cout << "- 'fetch <key>' : Fetchs a value from cache\n";
            cout << "- 'remove <key>' : Removes a value from cache\n";
            cout << "- 'size' : Current cache size\n";
            cout << "- 'count <key>' : Number of times key used\n";
            cout << "- 'time <key>' : Last time where key was used\n";
            cout << "- 'policy <value>' : Which cache eviction policy to use (0 : LRU, 1: TimeEviction)\n";
            cout << "- 'timelist' : List of the cache values from highest to lowest time\n";
            cout << "- 'countlist' : List of the cache values from highest to lowest usage\n";
            cout << "- 'exit' : exit cache\n";
            break;
        }
        else{
            cout << "command does not exists...\n";
        }
        s = "";
    }  
    return 0;   
}