//https://programmercarl.com/0541.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2II.html
//https://leetcode.cn/problems/reverse-string-ii/description/
//用C++中的reverse函数（reverse(起始迭代器, 结束迭代器);）reverse(s.begin(),s.end());
//begin：从哪里开始翻转，end：到哪里结束翻转（但不包含这个位置本身）
//法一：用内置的reverse函数
class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0;i<s.size();i += (2*k)){
            if(i+k <= s.size())
                reverse(s.begin()+i,s.begin()+i+k);
            else
                reverse(s.begin()+i,s.end());//s.end()是最后字符的下一个位置
        }
        return s;
    }
};
//法二：自己实现reverse函数左闭右闭
class Solution {
public:
    void reverse(string& s,int start,int end){//string& 是引用
        for(int i=start,j=end;i<j;i++,j--){
            swap(s[i],s[j]);
        }
    }
    string reverseStr(string s, int k) {
        for(int i=0;i<s.size();i+=(2*k)){
            if(i+k<=s.size()){
                reverse(s,i,i+k-1);
                continue;//可以不需要写
            }
            else
                reverse(s,i,s.size()-1);
        }
        return s;
    }
};
//法三：另一种写法的思路
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size(),pos = 0;
        while(pos < n){
            //剩余字符串大于等于k的情况
            if(pos + k < n) reverse(s.begin() + pos, s.begin() + pos + k);
            //剩余字符串不足k的情况 
            else reverse(s.begin() + pos,s.end());
            pos += 2 * k;
        }
        return s;
    }
};