class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<pair<int, int>> q;
        int prev = grid[sr][sc];
        q.push({sr, sc});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            
            grid[r][c] = color;
            
            int dr[] = {0,1,0,-1};
            int dc[] = {1,0,-1,0};
            
            for(int i=0; i<4; i++) {
                int nr=r+dr[i];
                int nc=c+dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc] == prev) {
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }
        
        return grid;
    }
};