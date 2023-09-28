//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    
    void dfs(int row, int col, vector<vector<int> > &grid, vector<vector<int> > &vis) {
        vis[row][col] = 1;
        int n=grid.size();
        int m=grid[0].size();

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        for(int i=0;i<4;i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, grid, vis);
            }
        }
    }
    
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> > vis(n, vector<int> (m,0));
        
        //travaerse firsr and last row
        for(int j=0; j<m; j++) {
            if(!vis[0][j] && grid[0][j] == 1) {
                dfs(0,j,grid,vis);
            } 

            if(!vis[n-1][j] && grid[n-1][j] == 1) {
                dfs(n-1,j,grid,vis);
            }
        }

        //travserse first and last col
        for(int i=0;i<n;i++) {
            if(!vis[i][0] && grid[i][0] == 1) {
                dfs(i,0,grid,vis);
            }

            if(!vis[i][m-1] && grid[i][m-1] == 1) {
                dfs(i,m-1,grid,vis);
            }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        
        return cnt;

    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends