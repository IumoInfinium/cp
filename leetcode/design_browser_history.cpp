class BrowserHistory {
public:
    stack<string> undoHistory, redoHistory;

    // this implementation works on always keeping the current website 
    // at top of the undoHistory stack;
    BrowserHistory(string homepage) {
        undoHistory.push(homepage);
        redoHistory= stack<string>();    
    }
    
    void visit(string url) {
        undoHistory.push(url);
        redoHistory = stack<string>();
    }
    
    string back(int steps) {
        while(steps && undoHistory.size() > 1){
            redoHistory.push(undoHistory.top());
            undoHistory.pop();
            steps--;
        }
        return undoHistory.top();
    }
    
    string forward(int steps) {
        while(steps && redoHistory.size()){
            undoHistory.push(redoHistory.top());
            redoHistory.pop();
            steps--;
        }
        return undoHistory.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
