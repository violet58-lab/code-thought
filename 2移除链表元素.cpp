//https://programmercarl.com/0203.%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0.html
//https://leetcode.cn/problems/remove-linked-list-elements/
//自己写
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)return head;
        while(head != nullptr && head->val == val)//必须加上这句，访问空指针不合法
        {head = head->next;}
        ListNode* newhead = head;
        if(!newhead)return newhead;
        while(newhead->next){
            if(newhead->next->val==val){
                ListNode* tmp = newhead->next;
                newhead->next = newhead->next->next;
                delete tmp;//C++用法
            }else{newhead = newhead->next;}
        }
        return head;
    }
};
//答案解法一
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 删除头结点
        while (head != NULL && head->val == val) { // 注意这里不是if
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }

        // 删除非头结点
        ListNode* cur = head;
        while (cur != NULL && cur->next!= NULL) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
//答案解法二（虚拟头结点）
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
        dummyHead->next = head; // 将虚拟头结点指向head，这样方便后面做删除操作
        ListNode* cur = dummyHead;
        while (cur->next != NULL) {
            if(cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};
//答案解法三（递归）
//递归思想：如果头结点是val，则删，答案即为头结点后面的结点递归的结果；
//反之，答案即为头结点与后面节点递归的结果
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)return head;
        if(head->val == val){
            ListNode* newhead = removeElements(head->next, val);
            delete head;
            return newhead;
        }
        else{
            head->next = removeElements(head->next,val);
            return head;
        }
    }
};