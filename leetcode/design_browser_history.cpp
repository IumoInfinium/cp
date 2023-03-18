// class BrowserHistory {
// public:
//     stack<string> undoHistory, redoHistory;

//     // this implementation works on always keeping the current website 
//     // at top of the undoHistory stack;
//     BrowserHistory(string homepage) {
//         undoHistory.push(homepage);
//         redoHistory= stack<string>();    
//     }
    
//     void visit(string url) {
//         undoHistory.push(url);
//         redoHistory = stack<string>();
//     }
    
//     string back(int steps) {
//         while(steps && undoHistory.size() > 1){
//             redoHistory.push(undoHistory.top());
//             undoHistory.pop();
//             steps--;
//         }
//         return undoHistory.top();
//     }
    
//     string forward(int steps) {
//         while(steps && redoHistory.size()){
//             undoHistory.push(redoHistory.top());
//             redoHistory.pop();
//             steps--;
//         }
//         return undoHistory.top();
//     }
// };

class Node{
public:
    string url;
    Node* prev;
    Node* next;
    Node(string url){
        this->url = url;
        prev=NULL;
        next=NULL;
    }
};
class BrowserHistory {
public:
    Node* curr;
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        Node* tmp = new Node(url);
        tmp->prev = curr;
        curr->next = tmp;
        curr = tmp; 
    }
    
    string back(int steps) {
        while(steps--){
            if(!curr->prev) return curr->url;
            curr = curr->prev;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(steps--){
            if(!curr->next) return curr->url;
            curr = curr->next;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
