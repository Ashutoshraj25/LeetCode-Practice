class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int> st;
    stack<int> st2;

    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while(st2.empty()){
            while(!st.empty()){
                st2.push(st.top());
                st.pop();
            }
        }
        int x = st2.top();
        st2.pop();
        return x;
    }
    
    int peek() {
        if (st2.empty()) {
            while (!st.empty()) {
                st2.push(st.top());
                st.pop();
            }
        }

        return st2.top();
    }

    
    bool empty() {
        return st.empty() && st2.empty();
    }
};