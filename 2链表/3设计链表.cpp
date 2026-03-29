//https://programmercarl.com/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
//https://leetcode.cn/problems/design-linked-list/description/
//1.自己写
class MyLinkedList {
public:
//定义结构体
    struct LinkedNode{
        int val;
        struct LinkedNode *next;
        LinkedNode(int val):val(val),next(nullptr){}
    };
    LinkedNode* _dummyhead;//这两个定义在外面
    int _size;
    MyLinkedList() {
        _dummyhead = new LinkedNode(0);//创建虚拟头结点
        _size = 0;//链表长度设为0
    }
    
    int get(int index) {
        if(index<0 || index>(_size-1))return -1;//下标有效性判断
        LinkedNode* cur = _dummyhead->next;//定义临时指针遍历，不去改头结点
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyhead->next;
        _dummyhead->next = newNode;
        _size++;
    }
    
    void addAtTail(int val) {
        LinkedNode* cur = _dummyhead;
        while(cur->next){cur = cur->next;}//找尾部结点，next为空
        LinkedNode* newNode = new LinkedNode(val);
        cur->next = newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) { 
        if(index > _size) return;
        if(index < 0) index = 0;
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyhead;
        while(index){
            cur = cur->next;
            index--;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>(_size-1))return;
        LinkedNode* cur = _dummyhead;
        while(index--) {
            cur = cur ->next;
        }
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }
};