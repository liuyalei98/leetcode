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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = new ListNode(0, head);
        ListNode* fast = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        ListNode* low = head;
        while (fast->next != nullptr) {
            fast = fast->next;
            low = low->next;
        }
        low->next = low->next->next;
        return head->next;
    }
};

int main()
{
    ListNode *l1 = new ListNode(6);

    Solution solution;

    ListNode* numsList = solution.removeNthFromEnd(l1, 1);
    printList(numsList);

    return 0;
}