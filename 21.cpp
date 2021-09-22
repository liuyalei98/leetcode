#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *p)
{
    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode *l = nullptr;
        if (l1->val <= l2->val)
        {
            l = l1;
            l->next = mergeTwoLists(l->next, l2);
        }else {
            l = l2;
            l->next = mergeTwoLists(l->next, l1);
        }
        return l;
    }
};

int main()
{
    ListNode *l1 = new ListNode(4);
    l1 = new ListNode(2, l1);
    l1 = new ListNode(1, l1);
    ListNode *l2 = new ListNode(4);
    l2 = new ListNode(3, l2);
    l2 = new ListNode(1, l2);

    Solution solution;

    ListNode* numsList = solution.mergeTwoLists(l1, l2);
    printList(numsList);

    return 0;
}