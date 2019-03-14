// Intersection: Given two (singly) linked lists, determine if the two lists intersect. Return the inter­
// secting node. Note that the intersection is defined based on reference, not value. That is, if the kth
// node of the first linked list is the exact same node (by reference) as the jth node of the second
// linked list, then they are intersecting.

#include <iostream>

using namespace std;

struct Node 
{
    int val;
    Node *next;
    Node(int v): val(v), next(NULL) {};
};

Node* intersection(Node *a, Node *b)
{
    int l1 = 0, l2 = 0;
    Node *x1, *x2;
    
    x1 = a;
    while (x1 != NULL)
    {
        l1 += 1;
        x1 = x1->next;
    }

    x2 = b;
    while (x2 != NULL)
    {
        l2 += 1;
        x2 = x2->next;
    }

    x1 = a;
    x2 = b;

    if (l2 > l1)
    {
        for (int i = 0; i < l2 - l1; i++)
            x2 = x2->next;
    }
    else
    {
        for (int i = 0; i < l1 - l2; i++)
            x1 = x1->next;
    }
    
    while (x1 != NULL && x2 != NULL && x1 != x2)
    {
        x1 = x1->next;
        x2 = x2->next;
    }

    return x1;
}

Node* createList(int a[], int n)
{
    Node *head = NULL, *prev, *x;
    for (int i = 0; i < n; i++)
    {
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

int main(void)
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int arr2[] = {-1, -2};
    Node *a = createList(arr1, 8);
    Node *b = createList(arr2, 2);
    b->next->next = a->next->next->next->next;

    cout << intersection(a, b)->val << endl;
    return 0;
}