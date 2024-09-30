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

node *convertarr2LL(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return nullptr;

    node *head = new node(arr[0]);
    node *mover = head;
    for (int i = 1; i < n; i++)
    {
        node *temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

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

int lengthOfLL(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int cnt = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int checkifPresent(node *head, int val)
{
    node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == val)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

node *insertAtHead(node *head, int val)
{
    node *temp = new node(val);
    temp->next = head;
    head = temp;
    return head;
}

node *insertAtTail(node *head, int val)
{
    if (head == NULL)
    {
        node *newnode = new node(val);
        return newnode;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *newnode = new node(val);
    temp->next = newnode;
    return head;
}

node *deleteAtHead(node *head)
{
    if (head == NULL)
    {
        cout << "List is already empty." << endl;
        return NULL;
    }
    node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

node *deleteAtTail(node *head)
{
    if (head == NULL)
    {
        cout << "List is already empty." << endl;
        return NULL;
    }
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

node *deleteByValue(node *head, int val)
{
    if (head == NULL)
    {
        cout << "List is already empty." << endl;
        return NULL;
    }

    if (head->data == val)
    {
        node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    node *temp = head;
    while (temp->next != NULL && temp->next->data != val)
    {
        temp = temp->next;
    }

    if (temp->next != NULL)
    {
        node *nodeTodelete = temp->next;
        temp->next = temp->next->next;
        delete nodeTodelete;
    }
    else
    {
        cout << "Value " << val << " not found in the list." << endl;
    }

    return head;
}

node *deleteAtPosition(node *head, int pos)
{
    if (head == NULL)
    {
        cout << "The list is already empty" << endl;
        return NULL;
    }

    if (pos == 1)
    {
        node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    node *temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        cout << "Position " << pos << " is out of range" << endl;
        return head;
    }

    node *nodeTodelete = temp->next;
    temp->next = temp->next->next;
    delete nodeTodelete;

    return head;
}

node *insertAtPosition(node *head, int val, int pos)
{
    if (pos < 1)
    {
        cout << "Position should be 1 or greater." << endl;
        return head;
    }
    if (pos == 1)
    {
        return insertAtHead(head, val);
    }
    node *temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Position is out of range." << endl;
        return head;
    }
    node *newnode = new node(val);
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

int main()
{
    vector<int> arr = {12, 13, 14, 15};
    node *head = convertarr2LL(arr);
    printLL(head);
    cout << "Length of the Linked List: " << lengthOfLL(head) << endl;
    cout << "Checking if 33 is present: " << checkifPresent(head, 33) << endl;
    head = insertAtHead(head, 11);
    printLL(head);
    head = insertAtTail(head, 16);
    printLL(head);
    head = deleteAtHead(head);
    printLL(head);
    head = deleteAtTail(head);
    printLL(head);
    cout << "Delete By Position: ";
    head = deleteAtPosition(head, 4);
    printLL(head);
    cout << "Delete By Value: ";
    head = deleteByValue(head, 14);
    printLL(head);
    cout << "Insert Value By Position: ";
    head = insertAtPosition(head, 14, 3);
    printLL(head);

    return 0;
}
