//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    bool isPossible(int div, vector<int> &nums, int k) {
        int c=0;
        for(int i=0;i<nums.size();i++) {
            int temp = ceil(double(nums[i] / double(div)));
            c += temp;
        }
        return c<=k;
    }
    
  public:
    int smallestDivisor(vector<int>& nums, int k) {

        // Write your code here.
        int low=1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = -1;
        
        while(low <= high) {
            int mid = (low+high) >> 1;
            
            if( isPossible(mid, nums, k) ) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
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
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends