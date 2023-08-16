//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}

// } Driver Code Ends


//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
     //Your code here
     // first occ of x in s
     if(s.size() < x.size()) return -1;
     int ind = -1;
     for(int i=0; i<=(s.size()-x.size()); i++) {
         if(s.substr(i, x.size()) == x) {
             return i;
         }
     }
     
     return -1;
}