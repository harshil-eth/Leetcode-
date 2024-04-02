class Solution {
private:
    int solve(int mid, vector<int> &arr) {
        int subarrays = 1, sum = 0;
        for(int i=0; i<arr.size(); i++) {
            if(sum + arr[i] > mid) {
                subarrays += 1;
                sum = arr[i];
            }
            else sum += arr[i];
        }
        
        return subarrays;
    }
    
public:
    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();
        int lo = *max_element(arr.begin(), arr.end());
        int hi = accumulate(arr.begin(), arr.end(), 0);
        
        int ans = -1;
        while(lo <= hi) {
            int mid = lo+(hi-lo)/2;
            
            int subArrays = solve(mid, arr);
            if(subArrays <= k) {
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        
        return ans;
    }
};