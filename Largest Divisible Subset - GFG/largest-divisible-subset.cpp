//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& arr) {
        // Code here
        sort(arr.begin(), arr.end());
        vector<int> dp(n, 1);
        int maxi = 1, lastIndex = 0;
        vector<int> hash(n);
        
        for(int i=0; i<n; i++) {
            hash[i] = i;
            for(int prev=0; prev<i;prev++) {
                if(arr[i] % arr[prev] == 0 && dp[prev] +1 > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            
            if(dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        
        vector<int> lds;
        lds.push_back(arr[lastIndex]);
        while(hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            lds.push_back(arr[lastIndex]);
        }
        reverse(lds.begin(), lds.end());
        return lds;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends