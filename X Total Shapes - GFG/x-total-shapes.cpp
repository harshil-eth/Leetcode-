//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    private:
    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vis[r][c] = 1;
        
        int dr[] = {0,1,0,-1};
        int dc[] = {1,0,-1,0};
        
        for(int i=0; i<4; i++) {
            int nr = r+dr[i];
            int nc= c+dc[i];
            
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc] == 'X') {
                dfs(nr, nc, vis, grid);
            }
        }
    }
    
    public:
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j] == 'X') {
    
                    dfs(i, j, vis, grid);
                    ans += 1;
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
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends