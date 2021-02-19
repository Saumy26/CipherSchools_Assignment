#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

Node *rearrangeEvenOdd(Node *head);

int main()
{
    int T,i,n,l;
    cin>>T;
    while(T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;

            if (head == NULL)
            {   
                head = temp = new Node(l); 
                
            }
            else
            {  temp->next = new Node(l);
               temp = temp->next;
            }
        }

        head = rearrangeEvenOdd(head);
        while(head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}

Node *rearrangeEvenOdd(Node *head)
{
   Node *p = head;
   Node *q = head->next;
   Node  *temp = q;
   while(1){
       if(!p || !q || !q->next){
            p->next = temp;
            break;
        }
       p->next = p->next->next;
       p = p->next;
       if(!p->next){
           q->next = NULL;
           p->next = temp;
           break;
       }
       q->next = q->next->next;
       q=q->next;
   }
  return head;
}
