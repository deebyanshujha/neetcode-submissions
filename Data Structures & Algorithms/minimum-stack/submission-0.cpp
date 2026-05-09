class MinStack {
    int minimum_value;
    stack<int> st;
    stack<int> prefix;
public:
    MinStack() {
        this->minimum_value = INT_MAX;
    }
    
    void push(int val) {
        st.push(val);
        prefix.push(minimum_value);
        minimum_value = min(minimum_value,val);
    }
    
    void pop() {
        st.pop();
        minimum_value = prefix.top();
        prefix.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minimum_value;
    }
};
