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
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return f(n-1, n, val, dp);
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