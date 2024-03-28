class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        
        // 0 to n-1
        // link from bi to ai

        vector<int> adj[n];
        vector<int> ind(n, 0);

        for(auto it: edges) {
            adj[it[1]].push_back(it[0]);
            ind[it[0]]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++) {
            if(ind[i] == 0) q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            topo.push_back(node);
            for(auto it: adj[node]) {
                ind[it]--;
                if(ind[it] == 0) q.push(it);
            }
        }

        return topo.size() == n;
    }
};