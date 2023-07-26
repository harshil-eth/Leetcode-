//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int n)
    {
        // code here
        vector<int> nums;
        nums.push_back(2000);
        nums.push_back(500);
        nums.push_back(200);
        nums.push_back(100);
        nums.push_back(50);
        nums.push_back(20);
        nums.push_back(10);
        nums.push_back(5);
        nums.push_back(2);
        nums.push_back(1);
        
        vector<int> res;
        
        int sz = nums.size();
        int ind = 0;
        while(ind < sz) {
            if(nums[ind] > n) {
                ind++;
            }
            else {
                n -= nums[ind];
                res.push_back(nums[ind]);
                if( n== 0) break;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends