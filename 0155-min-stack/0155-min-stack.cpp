class MinStack {
public:
stack<int> st;
stack<int> minst;

    MinStack() {
        minst.push(INT_MAX);
    }
    
    void push(int val) {
        if(val<=minst.top())  minst.push(val);
        st.push(val);
    }
    
    void pop() {
        if(st.top()==minst.top()) minst.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */