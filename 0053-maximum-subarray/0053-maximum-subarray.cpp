class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
        int sum = 0, maxi = -1e9;
        for(int i=0; i<n; i++) {
            sum += arr[i];
            maxi = max(maxi, sum);
            if(sum < 0) sum = 0;
        }
        
        return maxi;
    }
};