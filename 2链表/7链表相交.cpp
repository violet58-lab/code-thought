//https://programmercarl.com/%E9%9D%A2%E8%AF%95%E9%A2%9802.07.%E9%93%BE%E8%A1%A8%E7%9B%B8%E4%BA%A4.html
//https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/
//双指针法
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA=0,lenB=0;
        while(curA){
            lenA++;
            curA = curA->next;
        }
        while(curB){
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        if(lenA<lenB){
            swap(lenA,lenB);
            swap(curA,curB);
        }
        int gap = lenA - lenB;
        while(gap--){
            curA = curA->next;
        }
        while(curA){//本题是看当前结点是否相等
            if(curA == curB)return curA;//指针相等就是值相等了
            else{
                curA = curA->next;
                curB = curB->next;
            }
        }
        return NULL;
    }
};