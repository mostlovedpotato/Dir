#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class MyQueue {
public:
    stack<int> s;
    MyQueue() {

    }

    void push(int x) {
        pushHelp(x);
    }

    void pushHelp(int x) {
        if (s.size() == 0) {
            s.push(x);
            return;
        }
        int data;
        data = s.top();
        s.pop();
        pushHelp(x);
        s.push(data);
        return;
    }

    int pop() {
        int x = s.top();
        s.pop();
        return x;
    }

    int peek() {
        return s.top();
    }

    bool empty() {
        return s.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */