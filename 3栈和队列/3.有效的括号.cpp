//https://programmercarl.com/0020.%E6%9C%89%E6%95%88%E7%9A%84%E6%8B%AC%E5%8F%B7.html
//https://leetcode.cn/problems/valid-parentheses/description/
//括号不匹配有3种类型。匹配左括号时，右括号入栈，与栈顶元素比较，全遍历完后栈为空
class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2 != 0)return 0;
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(')st.push(')');
            else if(s[i] == '{')st.push('}');
            else if(s[i] == '[')st.push(']');
            else if(st.empty() || s[i] != st.top())return false;//栈空或右括号与栈顶不匹配
            else st.pop();
        }
        return st.empty();//全遍历完栈要为空
    }
};