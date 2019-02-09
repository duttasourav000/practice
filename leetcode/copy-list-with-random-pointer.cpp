/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

#include <iostream>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution
{
  public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        RandomListNode *nh = NULL;
        if (head == NULL)
            return nh;

        RandomListNode *r = head;
        while (r != NULL)
        {
            RandomListNode *n = new RandomListNode(r->label);
            n->next = r->random;
            r->random = n;
            r = r->next;
        }

        r = head;
        while (r != NULL)
        {
            r->random->random = r->random->next == NULL ? NULL : r->random->next->random;
            r = r->next;
        }

        r = head;
        nh = r->random;
        RandomListNode *t = NULL;
        while (r != NULL)
        {
            t = r->random->next;
            r->random->next = r->next == NULL ? NULL : r->next->random;
            r->random = t;
            r = r->next;
        }

        return nh;
    };
};

void printList(RandomListNode *root)
{
    while (root != NULL)
    {
        cout << root->label << " " << root->next << " " << (root->random == NULL ? -1 : root->random->label) << endl;
        root = root->next;
    }
}

int main(void)
{
    RandomListNode* nodes[10];
    for (int i = 0; i < 10; i++)
    {
        nodes[i] = new RandomListNode(i + 1);
    }

    for (int i = 0; i < 10; i++)
    {
        nodes[i]->next = i == 9 ? NULL : nodes[i + 1];
        nodes[i]->random = nodes[(i + 3) % 10];
    }

    cout << "Original list -->" << endl;
    printList(nodes[0]);

    Solution s;
    RandomListNode *nh = s.copyRandomList(nodes[0]);
    
    cout << "Original list -->" << endl;
    printList(nodes[0]);

    for (int i = 0; i < 10; i++)
        delete nodes[i];

    cout << "New list -->" << endl;
    printList(nh);

    return 0;
}