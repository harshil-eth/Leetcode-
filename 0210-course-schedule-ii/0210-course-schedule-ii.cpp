class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<int> topo;
        vector<int> adj[n];
        vector<int> ind(n, 0);
        
        for(auto it: edges) {
            adj[it[1]].push_back(it[0]);
            ind[it[0]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(ind[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            topo.push_back(node);
            
            for(auto it: adj[node]) {
                ind[it]--;
                if(ind[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        if(topo.size() != n) return {};
        else return topo;
    }
};