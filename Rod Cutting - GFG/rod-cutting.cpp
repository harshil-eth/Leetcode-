//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  private:
  
    int f(int ind,  int wt, int val[], vector<vector<int>> &dp) {
        if(ind == 0) {
            return wt*val[0];
        }
        if(dp[ind][wt] != -1)
            return dp[ind][wt];
        
        int notpick = 0 + f(ind-1, wt, val, dp);
        int pick = -1e8;
        int rod = ind+1;
        if(rod <= wt) 
            pick = val[ind] + f(ind, wt-rod, val, dp);
            
        return dp[ind][wt] = max(pick, notpick);
    }
  
  public:
    int cutRod(int val[], int n) {
        //code here
        // vector<vector<int>> dp(n, vector<int> (n+1, -1));
        // return f(n-1, n, val, dp);
        
        int wt = n;
        // vector<vector<int>> dp(n, vector<int> (n+1, 0));
        // for(int j=0;j<n+1;j++) {
        //     dp[0][j] = j*val[0];
        // }
        
        // for(int i=1;i<n;i++) {
        //     for(int j=0;j<wt+1;j++) {
        //         int notpick = 0 + dp[i-1][j];
        //         int pick = -1e8;
        //         int rod = i+1;
        //         if(rod <= j) 
        //             pick = val[i] + dp[i][j-rod];
                    
        //         dp[i][j] = max(pick, notpick);
        //     }
        // }
        
        // return dp[n-1][wt];
        
        
        vector<int> prev(wt+1, 0), curr(wt+1, 0);
        for(int j=0;j<n+1;j++) {
            prev[j] = j*val[0];
        }
        
        for(int i=1;i<n;i++) {
            for(int j=0;j<wt+1;j++) {
                int notpick = 0 + prev[j];
                int pick = -1e8;
                int rod = i+1;
                if(rod <= j) 
                    pick = val[i] + curr[j-rod];
                    
                curr[j] = max(pick, notpick);
            }
            prev = curr;
        }
        
        return prev[wt];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends