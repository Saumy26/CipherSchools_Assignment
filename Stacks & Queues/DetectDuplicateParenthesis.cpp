#include <bits/stdc++.h> 
using namespace std; 
  
bool isDuplicate(string s)
{     
    stack<char> Stack; 
    for(char ch : s) { 
        if(ch == ')') { 
            char top = Stack.top(); 
            Stack.pop(); 
            int elementsIn = 0; 
            while(top != '(') { 
                elementsIn++; 
                top = Stack.top(); 
                Stack.pop(); 
            } 
            if(elementsIn < 1) { 
                return 1; 
            } 
        } 
        else {
            Stack.push(ch); 
        }    
    } 
    return false; 
} 
  
int main()
{ 
    string s = "(((a+(b))+(c+d)))";     
    if(isDuplicate(s)) { 
        cout<<"Duplicate Parenthesis";
    }    
    else {
        cout<<"No Duplicate Parenthesis"; 
    }    
    return 0; 
}
