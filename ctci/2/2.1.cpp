// R�mov� Dups! Write code to remove duplicates from an unsorted linked list.

#include <iostream>
#include <unordered_set>

using namespace std;

struct Node
{
    int n;
    struct Node* next;

    Node(int x): n(x), next(NULL) {}
};


Node* removeDups(Node* head)
{
    unordered_set < int > s;
    Node* c = head;
    Node *prev = NULL;
    while (c != NULL)
    {
        if (s.find(c->n) == s.end())
        {
            s.insert(c->n);
            prev = c;
        }
        else
        {
            prev->next = c->next;
        }

        c = c->next;
    }

    return head;
}

void printList(Node* h)
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
    Node* head = NULL;
    Node* prev = NULL;
    for (int i = 0; i < n; i++)
    {
        Node* n = new Node(a[i]);
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
    int a[8] = {1, 2, 3, 2, 4, 5, 1, 8};
    Node* head = createList(a, 8);
    printList(head);
    printList(removeDups(head));
    
    int b[8] = {1, 1, 1, 1};
    head = createList(b, 4);
    printList(head);
    printList(removeDups(head));

    int c[8] = {1, 2, 3, 4};
    head = createList(c, 4);
    printList(head);
    printList(removeDups(head));

    return 0;
}