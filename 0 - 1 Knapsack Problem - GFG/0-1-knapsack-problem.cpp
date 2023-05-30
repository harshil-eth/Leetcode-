//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    
    int f(int ind, int W, int wt[], int val[], vector<vector<int>> &dp) {
        if(ind == 0) {
            if(wt[0] <= W) return val[0];
            else return 0;
        }
        
        if(dp[ind][W] != -1) 
            return dp[ind][W];
        
        int notpick = 0 + f(ind-1, W, wt, val, dp);
        int pick = INT_MIN;
        if(wt[ind] <= W) {
            pick = val[ind] + f(ind-1, W-wt[ind], wt, val, dp);
        }
        return dp[ind][W] = max(pick, notpick);
    }
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
    //   vector<vector<int>> dp(n, vector<int> (W+1, -1));
    //   return f(n-1, W, wt, val, dp);
    
    // vector<vector<int>> dp(n, vector<int> (W+1, 0));
    // for(int j=wt[0]; j<W+1;j++) dp[0][j] = val[0];
    
    // for(int i=1;i<n;i++) {
    //     for(int j=0;j<=W;j++) {
    //         int notpick = 0 + dp[i-1][j];
    //         int pick = INT_MIN;
    //         if(wt[i] <= j) 
    //             pick = val[i] + dp[i-1][j-wt[i]];
                
    //         dp[i][j] = max(pick, notpick);
    //     } 
    // }
    
    // return dp[n-1][W];
    
    // vector<vector<int>> dp(n, vector<int> (W+1, 0));
    vector<int> prev(W+1, 0), curr(W+1, 0);
    for(int j=wt[0]; j<W+1;j++) prev[j] = val[0];
    
    for(int i=1;i<n;i++) {
        for(int j=0;j<=W;j++) {
            int notpick = 0 + prev[j];
            int pick = INT_MIN;
            if(wt[i] <= j) 
                pick = val[i] + prev[j-wt[i]];
                
            curr[j] = max(pick, notpick);
        } 
        prev = curr;
    }
    
    return prev[W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends