//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> arr) 
    {
        // Code here.
        int xorr = 0;
        for(auto it:arr) {
            xorr ^= it;
        }
        
        vector<int> res(2);
        int lowest = (xorr & (-xorr));
        
        for(int i=0; i<arr.size(); i++) {
            if((arr[i] & lowest) == 0) {
                res[0] ^= arr[i];
            }
            else {
                res[1] ^= arr[i];
            }
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends