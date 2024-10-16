#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int maxSize;
    int *arr;
    int topIndex;

    Stack()
    {
        topIndex = -1;
        maxSize = 1000;
        arr = new int[maxSize];
    }

    void push(int x)
    {
        topIndex++;
        arr[topIndex] = x;
    }
    int pop()
    {
        int x = arr[topIndex];
        topIndex--;
        return x;
    }
    int top()
    {
        return arr[topIndex];
    }
    int size()
    {
        return topIndex + 1;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Top element: " << s.top() << endl;
    cout << "Current size: " << s.size() << endl;

    return 0;
}
