class Solution {
public:
    int timeRequiredToBuy(vector<int>& arr, int k) {
        int n = arr.size();
        int ind = 0;
        queue<pair<int, int>> q;
        for(auto it: arr) {
            q.push({it, ind++});
        }
        
        int t = 0;
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            int node = temp.first;
            int ind = temp.second;
            
            t+=1;
            node -= 1;
            if(ind == k && node == 0) return t;
            
            if(node > 0) {
                q.push({node, ind});
            }
        }
        
        return -1;
    }
};