class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int maxi = 0, buy = arr[0];
        for(int i=1; i<n; i++) {
            int p = arr[i] - buy;
            maxi = max(maxi, p);
            buy = min(buy, arr[i]);
        }
        
        return maxi;
    }
};