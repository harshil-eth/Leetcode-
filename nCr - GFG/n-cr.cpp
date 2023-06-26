//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
vector<vector<int>> dp;
    int M = 1e9 + 7;
    int solver(int n, int r) {
        if(r==0) return 1;
        if(n==0) return 0;
        if(dp[n][r]!=-1) return dp[n][r];
        return dp[n][r] = (solver(n-1, r)%M + solver(n-1, r-1)%M)%M;
    }
    int nCr(int n, int r){
        dp.resize(n+1, vector<int> (r+1, -1));
        return solver(n, r);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends