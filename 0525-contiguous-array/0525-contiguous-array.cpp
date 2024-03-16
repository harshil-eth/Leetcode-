class Solution {
public:
    int findMaxLength(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i<n; i++) {
            if(arr[i] == 0) arr[i] = -1; 
        }

        int sum = 0;
        unordered_map<int, int> mp;
        int mxlen = 0;

        for(int i=0; i<n; i++) {
            sum += arr[i];
            if(sum == 0) mxlen = i+1;

            if(mp.find(sum) != mp.end()) {
                mxlen = max(mxlen, i - mp[sum]);
            }
            else {
                mp[sum] = i;
            }
        }

        return mxlen;
    }
};