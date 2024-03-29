class Solution {
private:
    bool f(int node, vector<vector<int>> &adj, vector<int> &color) {
        color[node] = 0;
        queue<int> q;
        q.push(node);
        
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            
            for(auto it: adj[node]) {
                if(color[it] == -1) {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]) return 0;
            }
        }
        
        return 1;
    }
    
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> color(n, -1);
        
        for(int i=0; i<n; i++) {
            if(color[i] == -1) {
                if(f(i, adj, color) == 0) return 0;
            }
        } 
        
        return 1;
    }
};