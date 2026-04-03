class MyQueue {
public:
    stack<int>stIn;
    stack<int>stOut;
    MyQueue() {
        
    }
    
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        if(stOut.empty()){
            while(!stIn.empty()){
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();//C++里pop()返回void,所以不能直接弹出
        stOut.pop();
        return result;
    }
    
    int peek() {
        int pos = this->pop();//调用当前对象自己的成员函数，也就是上面那个
        stOut.push(pos);//因为调用已经把pos删了，所以要添加上
        return pos;
    }
    
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};