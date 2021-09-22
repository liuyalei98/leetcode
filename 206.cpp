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
    // 迭代
    // ListNode* reverseList(ListNode* head) {
    //     ListNode *curr = head;
    //     head = nullptr;
    //     while (curr != nullptr) {
    //         head = new ListNode(curr->val, head);
    //         curr = curr->next;
    //     }
    //     return head;
    // }
    
    // 递归
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};

int main()
{
    ListNode *l1 = new ListNode(5);
    l1 = new ListNode(4, l1);
    l1 = new ListNode(3, l1);
    l1 = new ListNode(2, l1);
    l1 = new ListNode(1, l1);

    Solution solution;

    ListNode* numsList = solution.reverseList(l1);
    printList(numsList);

    return 0;
}