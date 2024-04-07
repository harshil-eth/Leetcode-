class Solution {
public:
    #define ll long long
    long long minOperationsToMakeMedianK(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        ll ans = abs(arr[n/2]-k);
        
        for(int i=n/2-1; i>=0; i--) {
            int d = arr[i] - k;
            if(d >= 0) {
                ans += d;
            }
        }
        
        for(int i=n/2+1; i<n; i++) {
            int d = k -arr[i];
            if(d > 0) {
                ans += d;
            }
        }
        
        return ans;
    }
};