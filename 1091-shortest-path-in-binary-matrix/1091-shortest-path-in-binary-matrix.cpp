class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        dist[0][0] = 0;
        
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            if(r == n-1 && c == m-1) return dis;
            
            int dr[] = {0,1,1,1,0,-1,-1,-1};
            int dc[] = {1,1,0,-1,-1,-1,0,1};
            
            for(int i=0; i<8; i++) {
                int nr = r+dr[i];
                int nc = c+dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] != 1) {
                    if(1 + dis < dist[nr][nc]) {
                        dist[nr][nc] = 1 + dis;
                        q.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }
        
        return -1;
    }
};