#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *back;
    node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->back = nullptr;
    }
    node(int data, node *prev, node *next)
    {
        this->data = data;
        this->next = next;
        this->back = prev;
    }
};
node *convertarr2DLL(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;
    node *head = new node(arr[0]);
    node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        node *temp = new node(arr[i], prev, nullptr);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void printDLL(node *head)
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
node *deleteAtHead(node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return NULL;
    node *prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}
node *deleteAtTail(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    node *prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}
node *deleteKthElement(node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    int cnt = 0;
    node *Knode = head;
    while (Knode->next != NULL)
    {
        cnt++;
        if (cnt == k)
            break;
        Knode = Knode->next;
    }
    node *prev = Knode->back;
    node *front = Knode->next;
    if (prev == NULL && front == NULL)
    {
        return NULL;
    }
    else if (prev == NULL)
    {
        head = deleteAtHead(head);
    }
    else if (front == NULL)
    {
        head = deleteAtTail(head);
    }
    else
    {
        prev->next = front;
        front->back = prev;
        Knode->back = nullptr;
        Knode->next = nullptr;
        delete Knode;
    }
    return head;
}
node *insertBeforeHead(node *head, int k)
{
    node *prev = head;
    node *temp = new node(k, nullptr, prev);
    head = temp;
    return head;
}
node *insertAtEnd(node *head, int k)
{
    node *tail = head;
    if (head == NULL)
    {
        node *temp = new node(k, nullptr, nullptr);
        return temp;
    }
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    node *newnode = new node(k, tail, nullptr);
    tail->next = newnode;
    return head;
}
node *insertBeforeKthElement(node *head, int k, int val)
{
    if (k == 1)
    {
        return insertBeforeHead(head, val);
    }
    node *temp = head;
    int cnt = 0;
    while (temp->next != NULL)
    {
        cnt++;
        if (cnt == k)
            break;
        temp = temp->next;
    }
    node* prev = temp->back;
    node * newnode = new node(val,prev,temp);
    prev->next = newnode;
    temp->back = newnode;
    return head;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    node *head = convertarr2DLL(arr);
    head = insertBeforeKthElement(head, 3, 8);
    printDLL(head);
    return 0;
}
