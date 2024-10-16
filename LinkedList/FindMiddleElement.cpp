#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
    node(int d, node *nex)
    {
        data = d;
        next = nex;
    }
};

int getMiddleElement(node *head)
{
    node *slow = head;
    node *fast = head;

    while (fast->next != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main()
{

    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = new node(40);
    head->next->next->next->next = new node(50);
    cout << "Middle Element of the Linked List is : " << getMiddleElement(head);

    return 0;
}