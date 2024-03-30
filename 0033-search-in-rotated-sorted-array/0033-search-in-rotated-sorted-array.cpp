class Solution {
public:
    int search(vector<int>& arr, int t) {
        int n = arr.size();
        int lo = 0, hi = n-1;
        
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if(arr[mid] == t) {
                return mid;
            }
            
            // if left side is sorted
            if(arr[lo] <= arr[mid]) {
                if(arr[lo] <= t && t <= arr[mid]) {
                    hi = mid-1;
                }
                else lo = mid+1;
            }
            else {
                // right side is sorted
                if(arr[mid] <= t && t <= arr[hi]) {
                    lo = mid+1;
                } 
                else hi = mid-1;
            }
        }
        
        return -1;
    }
};