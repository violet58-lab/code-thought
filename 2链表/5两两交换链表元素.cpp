//https://programmercarl.com/0024.%E4%B8%A4%E4%B8%A4%E4%BA%A4%E6%8D%A2%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
//https://leetcode.cn/problems/swap-nodes-in-pairs/description/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* cur = dummyhead;
        while(cur->next != nullptr && cur->next->next != nullptr){
            ListNode* tmp = cur->next;
            ListNode* tmp1 = cur->next->next->next;//暂存结点

            cur->next = cur->next->next;
            cur->next->next = tmp;
            cur->next->next->next = tmp1;//3个步骤

            cur = cur->next->next;//后移，为了下次交换
        }
        ListNode* result = dummyhead->next;//不能用cur，cur变了！
        delete dummyhead;
        return result;
    }
};