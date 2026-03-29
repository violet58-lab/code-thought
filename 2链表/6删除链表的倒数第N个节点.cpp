//https://programmercarl.com/0019.%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B9.html
//https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {//用快慢指针实现
    ListNode* dummyhead = new ListNode(0);
    dummyhead->next = head;
    ListNode* fast = dummyhead;
    ListNode* slow = dummyhead;
    while(n-- && fast!=nullptr){
        fast = fast->next;
    }
    fast = fast->next;
    while(fast != nullptr){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummyhead->next;//不能返回head，因为头结点可能被删
    }
};