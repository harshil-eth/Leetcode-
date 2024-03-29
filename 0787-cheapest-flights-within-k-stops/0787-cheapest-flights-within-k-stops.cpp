class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(auto it: edges) {
            adj[it[0]].push_back({it[1], it[2]});   
        }
        
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, src}}); // {stops, {dis, node}};
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int dis = it.second.first;
            int node = it.second.second;
            
            if(stops > k) continue;
            
            for(auto it: adj[node]) {
                int adjnode = it.first;
                int edgew = it.second;
                
                if(stops <= k && dis + edgew < dist[adjnode]) {
                    dist[adjnode] = dis + edgew;
                    q.push({stops+1, {dis+edgew, adjnode}});
                }
            }
        }
        
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};