class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        int maxp = 1, minp = 1;
        int ans = -1e9;
        
        for(int i=0; i<n; i++) {
            if(arr[i] < 0) swap(maxp, minp);
            maxp = max(maxp*arr[i], arr[i]);
            minp = min(minp*arr[i], arr[i]);
            
            ans = max(ans, maxp);
        }
        
        return ans;
    }
};