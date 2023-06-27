//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    #define ll long long int
    private:
    bool hai(ll days, vector<int> &nums, int m, int k) {
        int bloomed = 0,  c=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] <= days) {
                c++;
            }
            else {
                bloomed += (c/k);
                c=0;
            }
        }
        bloomed += (c/k);
        return bloomed >= m;
    }
    
  public:
    int solve(int m, int k, vector<int> &nums){
        
      // Code here
      int n=nums.size();
      long long int condn = 1LL * m * 1LL * k;
      if(condn > n) return -1;
      
      ll low = 1;
      ll high = *max_element(nums.begin(), nums.end());
      ll ans = -1;
      
      while(low <= high) {
          ll mid = low + (high-low)/2;
          if(hai(mid, nums, m, k)) {
              ans = mid;
              high = mid-1;
          }
          else low = mid+1;
      }
      return (int)ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends