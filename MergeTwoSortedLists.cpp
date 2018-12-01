#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}  /**/
};
/*start*/
ListNode * mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == NULL && l2 != NULL) return l2;
    if (l1 != NULL && l2 == NULL) return l1;
    if (l1 ==NULL && l2 == NULL) return {};
    
    ListNode *l3(NULL), *l4(NULL);          //指针可以用NULL初始化！
    if (l1->val <= l2->val) {
        l3 = l4 = l1;
        l1 = l1->next;
    }
    else if (l1->val > l2->val) {
        l3 = l4 = l2;
        l2 = l2->next;
    }
    
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            l4->next = l1;
            l4 = l4->next;
            l1 = l1->next;
        }
        else if (l1->val > l2->val) {
            l4->next = l2;
            l4 = l4->next;
            l2 = l2->next;
        }
    }
    if (l1 != NULL && l2 == NULL)
        l4->next = l1;
    else if (l1 == NULL && l2!= NULL)
        l4->next = l2;
    return l3;
}
/*end*/
int main() {
    auto l1 = new ListNode(1);
    auto node1 = new ListNode(2);
    l1->next = node1;
    auto node2 = new ListNode(4);
    node1->next = node2;

    auto l2 = new ListNode(1);
    auto node3 = new ListNode(3);
    l2->next = node3;
    auto node4 = new ListNode(4);
    node3->next = node4;

    ListNode *l3 = mergeTwoLists(l1, l2);
    while (l3 != NULL) {
        cout << l3->val << ' ';
        l3 = l3->next;  /**/
    }
    return 0;
}
