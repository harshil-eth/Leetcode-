//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:

    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        int n=grid.size();
        int m=grid[0].size();
        
        if(i<0 || i>=n || j<0 || j>=m) return -1e9;
        if(j == m-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        
        int ru = grid[i][j] + f(i-1, j+1, grid, dp);
        int r = grid[i][j] + f(i, j+1, grid, dp);
        int rd = grid[i][j] + f(i+1, j+1, grid, dp);
        return dp[i][j] = max(ru, max(r, rd));
    }

public:
    int maxGold(int n, int m, vector<vector<int>> grid)
    {
        // code here
        int mx = -1e9;  
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        for(int i=0;i<n;i++) {
            mx = max(mx, f(i, 0, grid, dp));
        }
        return mx;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends