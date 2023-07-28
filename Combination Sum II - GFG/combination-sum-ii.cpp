//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void f(int ind, int t, vector<int> &ds, vector<vector<int>> &res, vector<int> &arr, int n) {
        if(t == 0) {
            res.push_back(ds);
            return;
        }

        for(int i=ind; i<n; i++) {
            if(i != ind && arr[i] == arr[i-1]) continue;
            if(arr[i] > t) break;

            ds.push_back(arr[i]);
            f(i+1 ,t-arr[i], ds, res, arr, n);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &nums, int t) {
        // Write your code here
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n=nums.size();
        vector<int> ds;
        f(0, t, ds, res, nums, n);
        return res;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends