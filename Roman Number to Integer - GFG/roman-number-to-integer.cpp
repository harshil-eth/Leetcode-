//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        
        unordered_map<char, int> mp = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
        int ans = 0;
        
        for(int i = 0; i<s.size(); i++) {
            if(i == 0 || mp[s[i]] <= mp[s[i-1]]) {
                ans += mp[s[i]];
            }
            else {
                ans += mp[s[i]] - 2*mp[s[i-1]];
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
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends