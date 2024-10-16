/*

Given a linked list where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to the head side, 2s at the end of the linked list, and 1s in the middle of 0s and 2s.

Input: LinkedList: 1->2->2->1->2->0->2->2
Output: 0->1->1->2->2->2->2->2
Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.

*/

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

node *sortLinkedList(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    node *zeroHead = new node(-1);
    node *oneHead = new node(-1);
    node *twoHead = new node(-1);
    node *zero = zeroHead;
    node *one = oneHead;
    node *two = twoHead;
    node *temp = head;
    while (temp)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }

    zero->next = (oneHead->next != NULL) ? oneHead->next : two->next;
    one->next = twoHead->next;
    two->next = NULL;

    node *newHead = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return newHead;
}

int main()
{
    vector<int> arr = {1, 2, 2, 1, 2, 0, 2, 2};
    node *head = convertarr2LL(arr);
    printLL(head);
    head = sortLinkedList(head);
    printLL(head);

    return 0;
}
