//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int n, vector<int> arr)
  {
      // code here
        unordered_map<int,int> mp;
        //   vector<int> nums(n);
          for(int i=0; i<n; i++){
            //   cin>>nums[i];
              if(arr[i]!=-1) mp[arr[i]]+=i;
          }
          int maxi = INT_MIN;
          int res = 0;
          for(auto i: mp){
              if(maxi<i.second){
                  maxi=i.second;
                  res = i.first;
              }
          }
          return res;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends