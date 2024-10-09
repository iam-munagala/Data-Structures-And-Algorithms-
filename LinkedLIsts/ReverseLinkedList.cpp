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

void printLL(node *&head)
{
    if (head == NULL)
        return;
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node *reverseLinkedList(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    node *prev = NULL;
    node *curr = head;
    node *nextp;

    while (curr)
    {
        nextp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextp;
    }
    head = prev;
    return head;
}

int main()
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = new node(40);

    printLL(head);
    head = reverseLinkedList(head);
    printLL(head);
    return 0;
}