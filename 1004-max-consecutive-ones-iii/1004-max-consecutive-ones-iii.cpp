class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int i=0, j=0;
        int ans = 0, c0 = 0;

        while(j < n) {
            if(arr[j] == 0) c0++;

            if(c0 <= k) {
                ans = max(ans, j-i+1);
                j++;
            }
            else if(c0 > k) {
                while(c0 > k) {
                    c0 -= arr[i] == 0;
                    i++;
                }
                j++;
            }
        }

        return ans;
    }
};