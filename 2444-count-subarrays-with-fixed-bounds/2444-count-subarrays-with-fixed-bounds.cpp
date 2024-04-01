class Solution {
public:
    long long countSubarrays(vector<int>& arr, int minK, int maxK) {
        long long ans = 0;
        int i=0;
        int n = arr.size();

        long long maxi = LONG_MIN;
        long long mini = LONG_MAX;

        int imax = 0, imin = 0;

        for(int j=0; j<n; j++) {

            if(arr[j] >= maxi) {
                maxi = arr[j];
                imax = j;
            }
            if(arr[j] <= mini) {
                mini = arr[j];
                imin = j;
            }

            if(maxi == maxK && mini == minK) {
                ans += min(imax, imin) - i +1;
            }

            else if(maxi > maxK || mini < minK) {
                mini = LONG_MAX;
                maxi = LONG_MIN;
                i = j+1;
            }
        }

        return ans;
    }
};