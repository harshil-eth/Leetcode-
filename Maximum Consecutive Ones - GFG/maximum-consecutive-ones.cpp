//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestOnes(int n, vector<int>& arr, int k) {
        // Code here
        int i=0, j=0;
        int mx = 0;
        int c =0;
        
        while(j<n) {
            if(arr[j] == 0) c++; 
            if(c <= k) {
                mx = max(mx, j-i+1);
                j++;
            }
            else if(c>k) {
                while(c>k) {
                    c -= arr[i] == 0;
                    i++;
                }
                
                mx = max(mx, j-i+1);
                j++;
            }
        }
        return mx;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends