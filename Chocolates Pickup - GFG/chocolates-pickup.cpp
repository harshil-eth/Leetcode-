//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
  
    // int f(int i, int j1, int j2, vector<vector<int>> &grid, int n, int m, vector<vector<vector<int>>> dp) {
        
    //     if(j1<0 || j1>=m || j2<0 || j2>=m) 
    //         return -1e8;
        
    //     if(i == n-1) {
    //         if(j1 == j2) return grid[i][j1];
    //         else return grid[i][j1] + grid[i][j2];
    //     }
        
    //     if(dp[i][j1][j2] != -1)
    //         return dp[i][j1][j2];
        
    //     int mx=-1;
    //     for(int dj1=-1; dj1<=1; dj1++) {
    //         for(int dj2=-1; dj2<=1; dj2++) {
                
    //             int value = 0;
    //             if(j1 == j2) value = grid[i][j1];
    //             else value = grid[i][j1] + grid[i][j2];
                
    //             value += f(i+1, j1+dj1, j2+dj2, grid, n, m, dp);
    //             mx = max(mx, value);
    //         }
    //     }
        
    //     return dp[i][j1][j2] = mx;
        
    // }
  
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        // vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (m, -1)));
        // return f(0, 0, m-1, grid, n, m, dp);
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, 0)));
        // base case
        for(int j1=0;j1<m;j1++) {
            for(int j2=0;j2<m;j2++) {
                if(j1 == j2) dp[n-1][j1][j2] = grid[n-1][j1];
                else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        for(int i=n-2;i>=0;i--) {
            for(int j1=0;j1<m;j1++) {
                for(int j2=0;j2<m;j2++) {
                    int mx=-1e8;
                    for(int dj1=-1; dj1<=1; dj1++) {
                        for(int dj2=-1; dj2<=1; dj2++) {
                            int value=0;
                            if(j1==j2) value = grid[i][j1];
                            else value = grid[i][j1] + grid[i][j2];

                            if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m)
                                value += dp[i+1][j1+dj1][j2+dj2];
                            else 
                                value = -1e8;
                            mx = max(mx, value);
                        }   
                    }
                    dp[i][j1][j2] = mx;
                }
            }
        }
        return dp[0][0][m-1];
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends