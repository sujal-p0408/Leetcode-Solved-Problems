class MinStack {
public:
    stack<int> st;
    stack<int> Minst;
    MinStack() {
        Minst.push(INT_MAX);
    } 
    
    void push(int val) {
       st.push(val); 
    //    Minst.push(min(val,Minst.top()));
    if(val <= Minst.top()) Minst.push(val);
    }
    
    void pop() {
        if(st.top()==Minst.top()) Minst.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        int ans=Minst.top();
        // if(Minst.top()==st.top()) st.pop();
        // Minst.pop();
        return ans;

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