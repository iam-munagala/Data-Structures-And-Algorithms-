#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
    node(int val, node *add)
    {
        this->data = val;
        this->next = add;
    }
};

void printLL(node *head)
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node *segregateOddsEven(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *odd = head;
    node *even = head->next;
    node *temp = even;

    while (even != NULL && even->next != nullptr)
    {
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = even->next->next;
        even = even->next;
    }
    odd->next = temp;
    return head;
}

int main()
{
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    printLL(head);
    head = segregateOddsEven(head);
    printLL(head);
    return 0;
}