//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:

//     int f(int ind, int w, int val[], int wt[], vector<vector<int>> &dp) {
//     if(ind == 0) {
//         if(wt[0] <= w) return ((w/wt[0])*(val[0]));
//         return 0;
//     }

//     if(dp[ind][w] != -1)
//         return dp[ind][w]; 

//     int notpick = 0 + f(ind-1, w, val, wt, dp);
//     int pick = -1e9;
//     if(wt[ind] <= w) 
//         pick = val[ind] + f(ind, w-wt[ind], val, wt, dp);

//     return dp[ind][w] = max(pick, notpick);
// }

public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        // vector<vector<int>> dp(n, vector<int> (w+1, -1));
        // return f(n-1, w, val, wt, dp);
    
        vector<vector<int>> dp(n, vector<int> (w+1, 0));
        for(int j=wt[0];j<w+1;j++) {
            dp[0][j] = ((j/wt[0])*(val[0]));
        }
        
        for(int i=1;i<n;i++) {
            for(int j=0;j<w+1;j++) {
                int notpick = 0 + dp[i-1][j];
                int pick = -1e9;
                if(wt[i] <= j) 
                    pick = val[i] + dp[i][j-wt[i]];
                    
                dp[i][j] = max(pick, notpick);
            }
        }
        
        return dp[n-1][w];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends