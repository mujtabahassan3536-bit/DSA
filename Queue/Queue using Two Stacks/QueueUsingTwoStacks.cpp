#include <iostream>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int> s1, s2;

public:
    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop() {
        if (s1.empty()) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Deleted: " << s1.top() << endl;
        s1.pop();
    }

    void front() {
        if (s1.empty()) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Front: " << s1.top() << endl;
    }

    void display() {
        if (s1.empty()) {
            cout << "Queue is Empty\n";
            return;
        }

        stack<int> temp = s1;

        cout << "Queue: ";
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.display(); 
    q.pop();
    q.display();
    q.push(40);
    q.display();
    q.front();

    return 0;
}
