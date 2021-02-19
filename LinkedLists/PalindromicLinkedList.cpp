#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

bool isPalindrome(Node *head);

int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

bool isPalindrome(Node *head)
{
    Node* slow= head; 
    stack <int> s; 
    while(slow != NULL)
    { 
        s.push(slow->data); 
        slow = slow->next; 
    } 

    while(head != NULL )
    { 
        int i=s.top(); 
        s.pop(); 
        if(head -> data != i)
        { 
            return false; 
        } 
        head=head->next; 
    } 
    return true; 
}
