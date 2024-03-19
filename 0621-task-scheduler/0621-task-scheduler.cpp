class Solution {
public:
    int leastInterval(vector<char>& arr, int n) {
        // int sz = arr.size();
        unordered_map<char, int> mp;
        for(auto it: arr) mp[it]++;

        priority_queue<int> pq;
        for(auto it: mp) {
            pq.push(it.second);
        }

        int ans = 0;
        while(!pq.empty()) {
            int cycle = n+1;
            vector<int> remain;

            while(cycle && !pq.empty()) {
                auto mxfrq = pq.top();
                pq.pop();

                if(mxfrq > 1) remain.push_back(mxfrq-1);

                cycle--;
                ans++;
            }

            for(auto it: remain) {
                pq.push(it);
            }

            if(pq.empty()) break;

            ans += cycle;
        }

        return ans;
    }
};