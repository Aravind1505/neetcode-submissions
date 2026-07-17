class MinStack {

    stack<pair<int, int>> sck;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (sck.empty()) sck.push({val, val});
        else sck.push({val, min(val, sck.top().second)});
    }
    
    void pop() {
        sck.pop();
    }
    
    int top() {
        return sck.top().first;
    }
    
    int getMin() {
        return sck.top().second;
    }
};
