//https://programmercarl.com/1047.%E5%88%A0%E9%99%A4%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E6%89%80%E6%9C%89%E7%9B%B8%E9%82%BB%E9%87%8D%E5%A4%8D%E9%A1%B9.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
//https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/
//自己写
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && s[i]==st.top())st.pop();
            else st.push(s[i]);
        }
        string ans(st.size(),' ');//创建长度为st.size()的字符串，每个元素为空格
        for(int j=st.size()-1;j>=0;j--){
            ans[j] = st.top();
            st.pop();
        }
        //s[size] = '\0';不是C++的写法！！！
        return ans;
    }
};
//答案
class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        for (char s : S) {
            if (st.empty() || s != st.top()) {
                st.push(s);
            } else {
                st.pop(); // s 与 st.top()相等的情况
            }
        }
        string result = "";//创建字符串变量，初始值为空
        while (!st.empty()) { // 将栈中元素放到result字符串汇总
            result += st.top();
            st.pop();
        }
        reverse (result.begin(), result.end()); // 此时字符串需要反转一下（在C++头文件<algorithm>里）
        return result;

    }
};