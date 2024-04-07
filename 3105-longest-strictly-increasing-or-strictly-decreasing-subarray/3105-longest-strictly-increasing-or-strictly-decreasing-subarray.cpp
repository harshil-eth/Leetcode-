class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        int n = arr.size();
        int ans = 1;
        int curr = 1;
        for(int i=0; i<n-1; i++) {
            if(arr[i] < arr[i+1]) {
                curr += 1;
            }
            else {
                ans = max(ans, curr);
                curr = 1;
            }
        }
        ans = max(ans, curr);
        
        curr = 1;
        for(int i=0; i<n-1; i++) {
            if(arr[i] > arr[i+1]) {
                curr += 1;
            }
            else {
                ans = max(ans, curr);
                curr = 1;
            }
        }
        ans = max(ans, curr);
        
        return ans;
    }
};