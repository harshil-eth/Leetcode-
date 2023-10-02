//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
  #define ll long long
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        
        vector<ll> ans;
        stack<ll> st;
        
        for(ll i=n-1; i>=0; i--) {
            if(st.size() == 0) ans.push_back(-1);
            else if(!st.empty() && st.top() > arr[i]) ans.push_back(st.top());
            else if(!st.empty() && st.top() <= arr[i]) {
                while(!st.empty() && st.top() <= arr[i]) {
                    st.pop();
                }
                
                if(st.size() == 0) ans.push_back(-1);
                else ans.push_back(st.top());
            }
            
            st.push(arr[i]);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends