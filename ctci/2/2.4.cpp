// Partition: Write code to partition a linked list around a value x, such that all nodes less than x come
// before all nodes greater than or equal to x. If x is contained within the list, the values of x only need
// to be after the elements less than x (see below). The partition element x can appear anywhere in the
// "right partition"; it does not need to appear between the left and right partitions.

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int n;
    struct Node *next;

    Node(int x): n(x) {};
};

Node* partition(Node *head, int n)
{
    vector < Node* > before;
    vector < Node* > after;

    Node *h = head;
    while (h != NULL)
    {
        if (h->n < n)
            before.push_back(h);
        else
            after.push_back(h);

        h = h->next;
    }

    Node *nh = NULL, *prev;
    for (int i = 0; i < before.size(); i++)
    {
        if (nh == NULL)
            nh = before[i];
        else
            prev->next = before[i];

        prev = before[i];
    }

    for (int i = 0; i < after.size(); i++)
    {
        if (nh == NULL)
            nh = after[i];
        else
            prev->next = after[i];

        prev = after[i];
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
            head = n;
        else
            prev->next = n;

        prev = n;
    }

    return head;
}

int main(void)
{
    int a[] = {1, 10, 9, 5, 3, 2, 5, 1, 15, 20};
    Node *head = createList(a, 10);
    printList(head);
    printList(partition(head, 5));

    return 0;
}