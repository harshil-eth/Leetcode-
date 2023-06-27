//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    long long int solve(int speed, vector<int> &piles) {
        long long int res = 0; // time to eat bananas with speed = speed
        for(int i=0; i<piles.size() ;i++) {
            long long int temp = ceil(piles[i] / double(speed));
            res += temp;
        }
        return res;
    }

  public:
    int Solve(int n, vector<int>& piles, int h) {
        // Code here
        int low=1;
        int high = *max_element(piles.begin(), piles.end());
        int ans=-1;

        while(low <= high) {
            int mid = low + (high-low)/2;

            long long int hrs = solve(mid, piles);

            if(hrs <= h) {
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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends