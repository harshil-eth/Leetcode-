class Solution {
private:
    bool check(int speed, vector<int> &arr, int h) {
        long long hrs = 0;
        for(int i=0; i<arr.size(); i++) {
            hrs += ceil(arr[i]*1.0 / speed*1.0);
        }
        
        return hrs <= h;
    }
    
public:
    int minEatingSpeed(vector<int>& arr, int h) {
        int n = arr.size();
        
        int lo = 1;
        int hi = *max_element(arr.begin(), arr.end());
        int ans = -1;
        
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            
            if(check(mid, arr, h)) {
                ans = mid;
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        
        return ans;
    }
};