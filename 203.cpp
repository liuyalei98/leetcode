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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;
        head->next = removeElements(head->next, val);
        if (head->val == val) return head->next;
        else return head;
    }
};

int main()
{
    ListNode *l1 = new ListNode(6);
    l1 = new ListNode(5, l1);
    l1 = new ListNode(4, l1);
    l1 = new ListNode(6, l1);
    l1 = new ListNode(3, l1);
    l1 = new ListNode(2, l1);
    l1 = new ListNode(1, l1);

    Solution solution;

    ListNode* numsList = solution.removeElements(l1, 6);
    printList(numsList);

    return 0;
}