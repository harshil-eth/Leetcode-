//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int binary_to_decimal(string s) {
        // Code here.
        
        int ans = 0;
        int n=s.size();
        int ind = n-1;
        int i = 0;
        
        while(ind >= 0) {
            int num = s[ind--] - '0';
            ans += num*pow(2, i);
            i++;
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.binary_to_decimal(str);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends