//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string s){
        // code here
        int n= s.size();
        stack<char> st;
        stack<int> index;
        index.push(-1);
        
        int maxi = 0;
        
        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                st.push(s[i]);
                index.push(i);
            }
            else {
                if(!st.empty() && st.top() == '(') {
                    st.pop();
                    index.pop();
                    maxi = max(maxi, i - index.top());
                }
                else {
                    index.push(i);
                }
            }
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends