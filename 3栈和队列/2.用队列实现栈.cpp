//https://programmercarl.com/0225.%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.html
//https://leetcode.cn/problems/implement-stack-using-queues/
//queue2是备份作用
class MyStack {
public:
    queue<int>que1;
    queue<int>que2;
    MyStack() {
        
    }
    
    void push(int x) {
        que1.push(x);
    }
    
    int pop() {
        int size = que1.size();
        size--;
        while(size--){
            que2.push(que1.front());
            que1.pop();
        }
        int result = que1.front();
        que1.pop();
        que1 = que2;
        while(!que2.empty()){
            que2.pop();
        }
        return result;
    }
    
    int top() {
        int size = que1.size();
        size--;
        while (size--){
            que2.push(que1.front());
            que1.pop();
        }

        int result = que1.front(); // 留下的最后一个元素就是要回返的值
        que2.push(que1.front());   // 获取值后将最后一个元素也加入que2中，保持原本的结构不变
        que1.pop();

        que1 = que2; // 再将que2赋值给que1
        while (!que2.empty()){
            que2.pop();
        }
        return result;
    }
    
    bool empty() {
        return que1.empty();
    }
};