class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        dist[0][0] = 0;
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        pq.push({0, {0, 0}});
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            if(r == n-1 && c == m-1) return diff;
            
            int dr[] = {0,1,0,-1};
            int dc[] = {1,0,-1,0};
            
            for(int i=0; i<4; i++) {
                int nr = r+dr[i];
                int nc = c+dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m) {
                    int max_effort = max(diff, abs(grid[nr][nc] - grid[r][c]));
                    if(max_effort < dist[nr][nc]) {
                        dist[nr][nc] = max_effort;
                        pq.push({max_effort, {nr, nc}});
                    }
                }
            }
        }
        
        return -1;
    }
};