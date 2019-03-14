// Palindrome: Implement a function to check if a linked list is a palindrome.

#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next;

    Node(int v): val(v), next(NULL) {};
};


Node* checkPalin(Node *n, int c, int l, bool &b)
{
    if (l == 0)
    {
        b = true;
        return NULL;
    }

    // cout << n->val << " " << c << " " << l << " " << b << endl;

    if (l % 2 == 0 && (c + 1) == l / 2)
    {
        b = n->val == n->next->val;
        return n->next->next;
    }
    else if(l % 2 != 0 && c == l / 2)
    {
        b = true;
        return n->next;
    }
    
    Node *x = checkPalin(n->next, c + 1, l, b);
    if (!b)
        return x->next;

    b = x->val == n->val;
    return x->next;
}

bool palindrome(Node* n)
{
    int l = 0;
    Node *h = n;
    while (h != NULL)
    {
        l += 1;
        h = h->next;
    }

    bool status = false;
    checkPalin(n, 0, l, status);
    return status;
}

Node* createList(int a[], int s)
{
    Node *head = NULL, *prev, *n;
    for (int i = 0; i < s; i++)
    {
        struct Node *n = new Node(a[i]);
        if (head == NULL)
        {
            head = n;
            prev = n;
        }
        else
        {
            prev->next = n;
            prev = n;
        }
    }

    return head;
}

int main(void)
{
    int a[] = {1, 2, 3, 2, 1};
    Node *n = createList(a, 5);
    cout << palindrome(n) << endl;

    int b[] = {1, 2, 3, 3, 2, 1};
    n = createList(b, 6);
    cout << palindrome(n) << endl;

    int c[] = {1, 2, 3, 4, 2, 1};
    n = createList(c, 6);
    cout << palindrome(n) << endl;

    int d[] = {1, 2, 3, 3, 1};
    n = createList(d, 5);
    cout << palindrome(n) << endl;

    return 0;
}