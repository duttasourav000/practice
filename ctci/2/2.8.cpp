// Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the
// beginning of the loop.
// DEFINITION
// Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so
// as to make a loop in the linked list.

#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int v): val(v), next(NULL) {};
};

Node* loopDetection(Node *head)
{
    Node *p1 = head, *p2 = head->next;
    while (p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next->next;
    }

    return p1;
}

Node* createList(int a[], int n)
{
    Node *head = NULL, *prev, *x;
    for (int i = 0; i < n; i++)
    {
        // cout << a[i] << endl;
        x = new Node(a[i]);
        if (head == NULL)
        {
            head = x;
            prev = x;
        }
        else
        {
            prev->next = x;
            prev = x;
        }
        
    }

    return head;
}

void printList(Node *n)
{
    while (n != NULL)
    {
        cout << n->val << " ";
        n = n->next;
    }

    cout << endl;
}

int main(void)
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *n = createList(a, 9);

    printList(n);

    Node *p = n;
    while (p->next != NULL)
        p = p->next;

    p->next = n->next->next->next;
    Node* meet = loopDetection(n);
    meet = meet->next;

    p = n;

    while (p != meet)
    {
        p = p->next;
        meet = meet->next;
    }

    cout << meet->val << endl;
    return 0;
}