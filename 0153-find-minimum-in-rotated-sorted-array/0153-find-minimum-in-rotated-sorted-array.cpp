class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int lo = 0, hi = n-1;
        int ans = 1e9;
        
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            
            if(arr[lo] <= arr[hi]) {
                ans = min(ans, arr[lo]);
                break;
            }
            
            if(arr[lo] <= arr[mid]) {
                //left side sorted
                ans = min(ans, arr[lo]);
                lo = mid+1;
            }
            else {
                ans = min(ans, arr[mid]);
                hi = mid-1;
            }
        }
        
        return ans;
    }
};