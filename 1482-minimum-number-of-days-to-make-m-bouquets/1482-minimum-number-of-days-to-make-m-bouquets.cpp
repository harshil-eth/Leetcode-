class Solution {
private:
    bool isposs(int days, vector<int> &arr, int m, int k) {
        int n = arr.size();
        int bloomed = 0;
        int c = 0;
        
        for(int i=0; i<n; i++) {
            if(arr[i] <= days) {
                c++;
            }
            else {
                // got a non bloomed flower
                bloomed += (c/k);
                c = 0;
            }
        }
        bloomed += (c/k);
        return bloomed >= m;
    }
    
public:
    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size();
        
        long long cond = 1LL * m * 1LL * k;
        if(cond > n) return -1;
        
        int lo = *min_element(arr.begin(), arr.end());
        int hi = *max_element(arr.begin(), arr.end());
        
        int ans = -1;
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            
            if(isposs(mid, arr, m, k)) {
                ans = mid;
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        
        return ans;
    }
};