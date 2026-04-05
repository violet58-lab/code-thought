//https://programmercarl.com/0150.%E9%80%86%E6%B3%A2%E5%85%B0%E8%A1%A8%E8%BE%BE%E5%BC%8F%E6%B1%82%E5%80%BC.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
//https://leetcode.cn/problems/evaluate-reverse-polish-notation/description/
//逆波兰表达式主要有以下两个优点：
//1.去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + * 也可以依据次序计算出正确结果。
//2.适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中
//逆波兰表达式相当于二叉树中的后序遍历
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){//注意要把单引号改成双引号，单引号是字符，双引号是字符串
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if(tokens[i]=="+")st.push(num2+num1);
                if(tokens[i]=="-")st.push(num2-num1);
                if(tokens[i]=="*")st.push(num2*num1);
                if(tokens[i]=="/")st.push(num2/num1);
            }
            else st.push(stoll(tokens[i]));//stoll是把字符串转换成 long long 类型的整数。（C++内置的）
        }
        long long result = st.top();
        st.pop();
        return result;
    }
};