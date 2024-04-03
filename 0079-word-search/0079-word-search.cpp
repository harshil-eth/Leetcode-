class Solution {
private:
    bool func(int r, int c, int ind, vector<vector<char>> &grid, string &word, vector<vector<int>> &vis, int n, int m) {
        
        if(ind >= word.size()) 
            return 1;
        
        int dr[] = {0,1,0,-1};
        int dc[] = {1,0,-1,0};
        for(int i=0; i<4; i++) {
            int nr=r+dr[i];
            int nc=c+dc[i];
            
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc] == word[ind]) {
                vis[nr][nc] = 1;
                if(func(nr, nc, ind+1, grid, word, vis, n, m) == true) return 1;
                vis[nr][nc] = 0;
            }
        }
        
        return 0;
    }
    
public:
    bool exist(vector<vector<char>>& grid, string word) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                
                if(!vis[i][j] && grid[i][j] == word[0]) {
                    vis[i][j] = 1;
                    if(func(i, j, 1, grid, word, vis, n, m) == true) return 1;
                    vis[i][j] = 0;
                }
            }
        }
        
        return 0;
    }
};