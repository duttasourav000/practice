// Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.

#include <iostream>

using namespace std;

struct Node
{
    int n;
    struct Node* next;

    Node(int x): n(x) {}
};

void printList(Node* h)
{
    while (h != NULL)
    {
        cout << h->n << " ";
        h = h->next;
    }

    cout << endl;
}

Node* createList(int x[], int n)
{
    Node *head = NULL, *prev = NULL;
    for (int i = 0; i < n; i++)
    {
        Node* n = new Node(x[i]);
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

Node* kthToLast(Node* head, int k)
{
    Node* h = head;
    while (k >= 0 && h != NULL)
    {
        h = h->next;
        k--;
    }

    if (k > -1)
        return NULL;

    Node* n = head; 
    while (h != NULL)
    {
        h = h->next;
        n = n->next;
    }

    return n;
}

void printAns(Node* n)
{
    if (n == NULL)
    {
        cout << "NULL" << endl;
    }
    else
    {
        cout << n->n << endl;
    }
    
}
int main(void)
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Node* head = createList(a, 8);
    printList(head);

    printAns(kthToLast(head, 3));
    printAns(kthToLast(head, 6));
    printAns(kthToLast(head, 0));
    printAns(kthToLast(head, 7));
    printAns(kthToLast(head, 10));

    return 0;
}