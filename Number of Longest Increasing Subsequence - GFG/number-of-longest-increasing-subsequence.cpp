//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int NumberofLIS(int n, vector<int>&arr) {
        // Code here
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        int maxi = 1;
        
        for(int i=0; i<n; i++) {
            for(int prev=0; prev<i; prev++) {
                if(arr[i] > arr[prev] && 1+dp[prev] > dp[i]) {
                    dp[i] = 1+dp[prev];
                    count[i] = count[prev];
                }
                else if(arr[i] > arr[prev] && 1+dp[prev] == dp[i]) {
                    count[i] += count[prev];
                }
            }
            
            maxi = max(maxi, dp[i]);
        }
        
        int c=0;
        for(int i=0; i<n; i++) {
            if(dp[i] == maxi) {
                c+=count[i];
            }
        }
        return c;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.NumberofLIS(n, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends