//https://programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html
//https://leetcode.cn/problems/linked-list-cycle-ii/description/
//1.判断是否有环2.返回入环的第一个结点
class Solution {
public://快指针每次相对于慢指针走一个结点
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while(index1!=index2){
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;
            }
        }
        return NULL;
    }
};