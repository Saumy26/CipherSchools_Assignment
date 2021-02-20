#include<bits/stdc++.h> 
using namespace std;   
stack<char> st; 
string s; 
  
char insertbottom(char x) { 
    if(st.size() == 0) { 
        st.push(x); 
    }
    else { 
        char p = st.top(); 
        st.pop(); 
        insertbottom(x); 
        st.push(p); 
    } 
} 
  
char reverse() { 
    if(st.size()>0){ 
        char x = st.top(); 
        st.pop(); 
        reverse();  
        insertbottom(x); 
    } 
} 
  
int main()
{ 
    st.push('10'); 
    st.push('20'); 
    st.push('30'); 
    st.push('40');
    st.push('50');
    reverse(); 
    while(!st.empty()) { 
        char q=st.top(); 
        st.pop(); 
        s+=q; 
    } 
    cout<<"[";
    for(int i=s.size()-1; i>=0; i--) {
        cout<<s[i]<<", ";
    }
    cout<<"]";
    return 0; 
}
