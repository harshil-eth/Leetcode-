class Solution {
private:
    bool isposs(int div, vector<int> &arr, int th) {
        int cnt = 0;
        for(int i=0; i<arr.size(); i++) {
            int temp = ceil(arr[i]*1.0 / div*1.0);
            cnt += temp;
        }
        
        return cnt <= th;
    }
    
public:
    int smallestDivisor(vector<int>& arr, int th) {
        int n = arr.size();
        int lo = 1;
        int hi = *max_element(arr.begin(), arr.end());
        
        int ans = -1;
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if(isposs(mid, arr, th)) {
                ans = mid;
                hi = mid-1;
            } else lo = mid+1;
        }
        
        return ans;
    }
};