class Solution {
public:
    int n,m;
    
    void bfs(int r, int c, vector<vector<char>> &grid, vector<vector<int>> &vis) {
        queue<pair<int, int>> q;
        q.push({r, c});
        vis[r][c] = 1;
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            
            int dr[] = {0,1,0,-1};
            int dc[] = {1,0,-1,0};
            for(int i=0; i<4; i++) {
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == '1' && !vis[nr][nc]) {
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    ans += 1;
                    bfs(i, j, grid, vis);
                }
            }
        }
        
        return ans;
    }
};