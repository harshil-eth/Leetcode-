//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    bool isPossible(int dis, int cows, vector<int> &nums) {
        
        int prevCow = nums[0];
        int cnt=1;
        for(int i=1;i<nums.size();i++) {
            if(nums[i] - prevCow >= dis) {
                cnt++;
                prevCow = nums[i];
            }
            
            if(cnt == cows) return true;
        }
        return false;
    }

public:

    int solve(int n, int k, vector<int> &nums) {
    
        // Write your code here
        sort(nums.begin(), nums.end());
        int low=1, high = nums[n-1] - nums[0];
        int ans = -1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            
            if( isPossible(mid, k, nums)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid-1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends