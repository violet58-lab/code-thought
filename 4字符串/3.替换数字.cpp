//https://programmercarl.com/kamacoder/0054.%E6%9B%BF%E6%8D%A2%E6%95%B0%E5%AD%97.html
//https://kamacoder.com/problempage.php?pid=1064
//很多数组类问题都是先预先给数组扩容到填充后的大小，然后从后向前操作
//字符用单引号，字符串用双引号
#include<iostream>
using namespace std;
int main(){
    string s;
    while(cin>>s){
        int soldindex = s.size()-1;
        int count = 0;
        for(int i=0;i < s.size();i++){
            if(s[i]>='0' && s[i]<='9')
                count++;
        }
    
    int snewindex = s.size() + (5*count)-1;
    s.resize(s.size()+(5*count));
    while(soldindex>=0){
        if(s[soldindex]>='0' && s[soldindex]<='9'){
            s[snewindex--] = 'r';
            s[snewindex--] = 'e';
            s[snewindex--] = 'b';
            s[snewindex--] = 'm';
            s[snewindex--] = 'u';
            s[snewindex--] = 'n';
        }
        else s[snewindex--] = s[soldindex];
        soldindex--;
    }
    cout<<s<<endl;
    }
}