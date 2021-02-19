#include<bits/stdc++.h>
using namespace std;

struct node *reverse (struct node *head, int k);

struct node
{
    int data;
    struct node* next;
    node(int x){
        data = x;
        next = NULL;
    }  
};

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        int k;
        cin>>k;
        head = reverse(head, k);
        printList(head);
    }
     
    return(0);
}

struct node *reverse (struct node *head, int k)
{ 
    node *cur=head;
    node* next = NULL;  
    node* prev = NULL;
    int cnt=0;
    while(cur!=NULL & cnt<k){
        next=cur->next;
        cur-> next =prev;
        prev=cur;
        cur=next;
        cnt++;
    }    
    if (next != NULL)  
    head->next = reverse(next, k);
    return prev;
}
