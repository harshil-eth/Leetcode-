//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void f(int ind, string &s, vector<string> &res) {
        
        if(ind >= s.size()) {
            res.push_back(s);
            return;
        }
        
        for(int i=ind; i<s.size(); i++) {
            swap(s[i], s[ind]);
            f(ind+1, s, res);
            swap(s[i], s[ind]);
        }
    }
    
    vector<string> permutation(string s)
    {
        //Your code here
        vector<string> res;
        // string ds = "";
        f(0, s, res);
        sort(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends