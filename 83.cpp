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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        head->next = deleteDuplicates(head->next);
        if (head->next->val == head->val) return head->next;
        else return head;
    }
};

int main()
{
    ListNode *l1 = new ListNode(3);
    l1 = new ListNode(3, l1);
    l1 = new ListNode(2, l1);
    l1 = new ListNode(2, l1);
    l1 = new ListNode(1, l1);
    l1 = new ListNode(1, l1);

    Solution solution;

    ListNode* numsList = solution.deleteDuplicates(l1);
    printList(numsList);

    return 0;
}