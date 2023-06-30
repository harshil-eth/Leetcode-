class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int, int>> adj[n];
        for(auto it:redEdges) {
            adj[it[0]].push_back({it[1], 0}); // red
        }
        for(auto it:blueEdges) {
            adj[it[0]].push_back({it[1], 1}); // blue
        }
        
        vector<int> dist(n, -1);
        dist[0] = 0;
        vector<vector<int>> vis(n, vector<int> (2, 0));
        vis[0][0] = 1, vis[0][1] = 1;
        
        queue<vector<int>> q;
        q.push({0, 0, -1}); // node, steps, color
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int node = it[0], steps = it[1], prevColor = it[2];
            
            for(auto it:adj[node]) {
                int adjNode = it.first;
                int color = it.second;
                
                if(!vis[adjNode][color] && color != prevColor) {
                    vis[adjNode][color] = 1;
                    q.push({adjNode, steps+1, color});
                    if(dist[adjNode] == -1) {
                        dist[adjNode] = steps + 1;
                    }
                }
            }
        }
        
        return dist;
    }
};