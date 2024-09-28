#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = nullptr;
    }
};

void print(node *head)
{
    node *temp = head;
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node *insertAtHead(node *&head, int val)
{
    node *temp = new node(val);
    temp->next = head;
    head = temp;
    return head;
}

node *insertAtTail(node *&tail, int val)
{
    node *newNode = new node(val);
    tail->next = newNode;
    tail = newNode;
    return tail;
}
node *insertAtPosition(node *&head, node *&tail, int val, int position)
{
    if (position == 1)
    {
        insertAtHead(head, val);
    }
    node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next = NULL)
    {
        insertAtTail(tail, val);
    }
    node *insertNode = new node(val);
    insertNode->next = temp->next;
    temp->next = insertNode;
}
int main()
{
    // Creating the initial linked list
    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;

    // Adding more nodes to the list
    tail = insertAtTail(tail, 20);
    tail = insertAtTail(tail, 30);

    // Print the list after initialization
    print(head);

    // Insert at head
    head = insertAtHead(head, 1);
    print(head);

    // Insert at tail
    tail = insertAtTail(tail, 99);
    print(head);

    head = insertAtPosition(head, tail, 22, 3);
    print(head);

    return 0;
}
