// Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but
// the first and last node, not necessarily the exact middle) of a singly linked list, given only access to
// that node.

#include <iostream>

using namespace std;

struct Node
{
    int n;
    struct Node *next;

    Node(int x): n(x) {};
};

Node* deleteMiddleNode(Node* head, Node* n)
{
    Node *h = head;
    while (h != NULL && h != n)
    {
        h = h->next;
    }

    if (h == NULL)
        return head;

    Node *prev = head;
    while (prev->next != h)
        prev = prev->next;

    prev->next = h->next;
    delete h;

    return head;
}

void printList(Node *h)
{
    Node *hc = h;
    while (hc != NULL)
    {
        cout << hc->n << " ";
        hc = hc->next;
    }

    cout << endl;
}

Node* createList(int x[], int n)
{
    Node *head = NULL, *prev = NULL;
    for (int i = 0; i < n; i++)
    {
        Node *n = new Node(x[i]);
        if (head == NULL)
            head = n;
        else
            prev->next = n;

        prev = n;
    }

    return head;
}
int main(void)
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Node *head = createList(a, 8);
    printList(head);

    head = deleteMiddleNode(head, head->next);
    printList(head);

    head = deleteMiddleNode(head, head->next->next);
    printList(head);

    head = deleteMiddleNode(head, head->next->next->next->next);
    printList(head);

    return 0;
}