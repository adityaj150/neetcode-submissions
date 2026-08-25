class MinStack {
private:
    stack<int>s;
    stack<int>minstack;

public:
    MinStack() {}
    
    void push(int val) {
        s.push(val);
        val = min(val, minstack.empty() ? val : minstack.top());
        minstack.push(val);
    }
    
    void pop() {
        s.pop();
        minstack.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
