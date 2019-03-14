// Sum Lists: You have two numbers represented by a linked list, where each node contains a single
// digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a
// function that adds the two numbers and returns the sum as a linked list.

#include <iostream>

using namespace std;

struct Node
{
    int n;
    struct Node *next;

    Node(int x): n(x), next(NULL) {};
};

Node* sumList(Node *a, Node *b)
{
    Node *nh = NULL, *prev;
    int rem = 0;
    while (a != NULL && b != NULL)
    {
        int s = a->n + b->n + rem;
        rem = s / 10;
        Node *n = new Node(s % 10);
        if (nh == NULL)
            nh = n;
        else
            prev->next = n;
        prev = n;
        a = a->next;
        b = b->next;
    }

    while (a != NULL)
    {
        int s = a->n + rem;
        rem = s / 10;
        Node *n = new Node(s % 10);
        if (nh == NULL)
            nh = n;
        else
            prev->next = n;
        prev = n;
        a = a->next;
    }

    while (b != NULL)
    {
        int s = b->n + rem;
        rem = s / 10;
        Node *n = new Node(s % 10);
        if (nh == NULL)
            nh = n;
        else
            prev->next = n;
        prev = n;
        b = b->next;
    }

    while (rem > 0)
    {
        Node *n = new Node(rem % 10);
        rem = rem / 10;
        if (nh == NULL)
            nh = n;
        else
            prev->next = n;
        prev = n;
    }

    return nh;
}

void printList(Node *h)
{
    while (h != NULL)
    {
        cout << h->n << " ";
        h = h->next;
    }

    cout << endl;
}

Node* createList(int a[], int n)
{
    Node *head = NULL, *prev;
    for (int i = 0; i < n; i++)
    {
        Node *n = new Node(a[i]);
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            prev->next = n;
        }

        prev = n;
    }

    return head;
}

int main(void)
{
    int a[] = {1, 2, 9};
    int b[] = {9, 2, 8, 9};
    Node *n1 = createList(a, 3);
    Node *n2 = createList(b, 4);

    printList(n1);
    printList(n2);
    printList(sumList(n1, n2));

    return 0;
}