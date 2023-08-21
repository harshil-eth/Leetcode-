//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &grid, int &cnt) {
        int n = grid.size();
        int m = grid[0].size();
        
        vis[r][c] = 1;
        cnt += 1;
        
        int dr[] = {0,1,1,1,0,-1,-1,-1};
        int dc[] = {1,1,0,-1,-1,-1,0,1};
        
        for(int i=0; i<8; i++) {
            int nr = r+dr[i];
            int nc= c+dc[i];
            
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc] == 1) {
                dfs(nr, nc, vis, grid, cnt);
            }
        }
    }
    
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    
                    int c = 0;
                    dfs(i, j, vis, grid, c);
                    ans = max(ans, c);
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends