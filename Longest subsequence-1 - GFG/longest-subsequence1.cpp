//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int n, int arr[])
    {
        // code here
        vector<int> dp(n, 1);
        for(int i=0;i<n;i++) {
            for(int prev=0; prev<i;prev++) {
                
                if(abs(arr[i] - arr[prev]) == 1) {
                    dp[i] = max(dp[i], 1+dp[prev]);
                }
            }
        }
        int mx=-1e9;
        for(int i=0;i<n;i++) {
            mx=max(mx, dp[i]);
        }
        return mx;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends