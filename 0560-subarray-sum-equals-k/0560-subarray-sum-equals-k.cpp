class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int ans  = 0;
        vector<int> pre(n, 0);
        pre[0] = arr[0];
        for(int i=1; i<n; i++) {
            pre[i] = pre[i-1] + arr[i];
        }
        
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            if(pre[i] == k) ans++;
            
            if(mp.find(pre[i] - k) != mp.end()) {
                ans += mp[pre[i] - k];
            }
            
            mp[pre[i]]++;
        }
        
        return ans;
    }
};