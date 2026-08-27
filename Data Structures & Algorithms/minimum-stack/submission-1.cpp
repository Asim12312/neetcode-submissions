class MinStack {
public:
    vector<int> stack;
    int topVal = -1;
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push_back(val);
        topVal++;
    }
    
    void pop() {
        if(topVal < 0){
            return;
        }
        stack.pop_back();
        topVal--;
    }
    
    int top() {
            return topVal >= 0 ? stack[topVal] : -1;
    }
    
    int getMin() {
        if(stack.size() < 0 ){
            return -1;
        }
        int min = stack[0];
        for(int i = 0; i < stack.size(); i++){
            if(min > stack[i]){
                min = stack[i];
            }
        }
        return min;
    }
};
