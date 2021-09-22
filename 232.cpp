#include <iostream>
#include <string.h>
#include <algorithm>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
    int front;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        while (!s1.empty()) s1.pop();
        while (!s2.empty()) s2.pop();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (s1.empty()) front = x;
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x;
        if (s2.empty()) {
            while (!s1.empty()) {
                x = s1.top();
                s2.push(x);
                s1.pop();
            }
        }
        x = s2.top();
        s2.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        if (!s2.empty()) return s2.top();
        else return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if (s1.empty() && s2.empty()) return true;
        else return false;
    }
};

int main()
{
    MyQueue myQueue;
    myQueue.push(1);
    cout << myQueue.peek() << endl;
    cout << myQueue.pop() << endl;
    return 0;
}
