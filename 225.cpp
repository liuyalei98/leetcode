#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
    int front;
public:
    /** Initialize your data structure here. */
    MyStack() {
        while (!q1.empty()) q1.pop();
        while (!q2.empty()) q2.pop();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            int x = q1.front();
            q2.push(x);
            q1.pop();
        }
        swap(q1, q2);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = q1.front();
        q1.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if (q1.empty()) return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{
    MyStack *myStack = new MyStack();
    myStack->push(1);
    myStack->push(2);
    cout << myStack->top() << endl;
    cout << myStack->pop() << endl;
    return 0;
}
