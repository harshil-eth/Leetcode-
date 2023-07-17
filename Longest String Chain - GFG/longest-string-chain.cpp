//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
private:
bool check(string &s, string &t) {
        if(s.size() != t.size() + 1) return 0;
        int i=0; int j= 0;

        while( i < s.size()) {
            if(j<t.size() && s[i] == t[j]) {
                i++;
                j++;
            }
            else {
                i++;
            }
        }
        if(i==s.size() && j==t.size()) return 1;
        return 0;
    }
  public:
    int longestChain(int n, vector<string>& nums) {
        // Code here
        // int n=nums.size();
        sort(nums.begin(), nums.end(), [](string &a, string &b) {
            return a.size() < b.size();
        });

        vector<int> dp(n, 1);
        int maxi = 1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {

                if(check(nums[i], nums[j]) && 1+dp[j] > dp[i]) {
                    dp[i] = 1+dp[j];
                }
            }

            maxi = max(maxi, dp[i]);
        }
        return maxi;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends