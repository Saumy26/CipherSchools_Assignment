#include<iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node* sortedMerge(struct Node* a, struct Node* b);

void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main()
{
    int T,i,n1,n2,l,k;
    cin>>T;
    while(T--)
    {
        struct Node *head1 = NULL,  *tail1 = NULL;
        struct Node *head2 = NULL,  *tail2 = NULL;

        cin>>n1>>n2;
        int d1 , d2 , temp;
        cin>>d1;
        head1 = new Node(d1);
        tail1 = head1;
        for(i=1; i<n1; i++)
        {
            cin>>temp;
            tail1->next = new Node(temp);
            tail1 = tail1->next;
        }
        cin>>d2;
        head2 = new Node(d2);
        tail2 = head2;
        for(i=1; i<n2; i++)
        {
            cin>>temp;
            tail2->next = new Node(temp);
            tail2 = tail2->next;
        }
        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

Node* sortedMerge(Node* head1,   Node* head2)
{
    Node* res = NULL;  
      
    if (head1 == NULL)  
        return(head2);  
    else if (head2 == NULL)  
        return(head1);  
     
    if (head1->data <= head2->data)  
    {  
        res = head1;  
        res->next = sortedMerge(head1->next, head2);  
    }  
    else
    {  
        res = head2;  
        res->next = sortedMerge(head1, head2->next);  
    }  
    return(res);
}
