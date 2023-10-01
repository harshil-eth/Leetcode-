//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string Reduced_String(int k,string s){
        // Your code goes here
        int n = s.size();
        stack<pair<char, int>> st;
        if(k == 1) return "";
        
        for(int i=0; i<n; i++) {
            if(st.empty() || st.top().first != s[i]) {
                st.push({s[i], 1});
            }
            else {
                st.top().second += 1;
                
                if(st.top().second == k) {
                    st.pop();
                }
            }
        }
        
        string ans = "";
        while(!st.empty()) {
            auto it = st.top();
            st.pop();
            char ch = it.first;
            int c = it.second;
            
            while(c--) {
                ans.push_back(ch);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }


};

//{ Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}
// } Driver Code Ends