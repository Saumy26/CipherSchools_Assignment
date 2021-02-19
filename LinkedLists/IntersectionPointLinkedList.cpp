#include<iostream>
#include<stdio.h>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

int intersectPoint(struct Node* head1, struct Node* head2);

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
int main()
{
    int T,i,n1, n2, n3,l,k;
    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }

        if (tail1 != NULL)
        tail1->next = head3;
        if (tail2 != NULL)
        tail2->next = head3;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}
   
int getCount(Node* head) 
{ 
    Node* cur = head; 
    int cnt = 0; 
    while (cur != NULL){ 
        cnt++; 
        cur = cur->next; 
    } 
    return cnt; 
} 

int getIntesection(int d, Node* head1, Node* head2) 
{ 
    Node* cur1 = head1; 
    Node* cur2 = head2; 
    for (int i = 0; i < d; i++){ 
        if (cur1 == NULL){ 
            return -1; 
        } 
        cur1 = cur1->next; 
    } 
    while (cur1 != NULL && cur2 != NULL){ 
        if (cur1 == cur2){ 
            return cur1->data; 
        }
        cur1 = cur1->next; 
        cur2 = cur2->next; 
    } 
    return -1; 
} 
   
int intersectPoint(Node* head1, Node* head2)
{
    int c1 = getCount(head1); 
    int c2 = getCount(head2); 
    int d; 
    if (c1 > c2){ 
        d = c1 - c2; 
        return getIntesection(d, head1, head2); 
    } 
    else{ 
        d = c2 - c1; 
        return getIntesection(d, head2, head1); 
    } 
}
