//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        if(s.size() < p.size()) return  "-1";
        
        unordered_map<char, int> mp;
        for(auto it:p) mp[it]++;
        
        int minlen = INT_MAX;
        int start=0;
        int cnt=0;
        int minleft = 0;
        
        for(int i=0;i<s.size();i++) {
            if(mp.find(s[i]) != mp.end()) {
                mp[s[i]]--;
                if(mp[s[i]] >= 0) {
                    cnt++;
                }
            }
            
            while(cnt == p.size()) {
                //length save
                if(minlen > i-start+1) {
                    minlen = i-start+1;
                    minleft = start;
                }
                
                //remove
                if(mp.find(s[start]) != mp.end()) {
                    mp[s[start]]++;
                    if(mp[s[start]] > 0) cnt--;
                }
                start++;
            }
        }
        
        if(minlen > s.size()) return "-1";
        return s.substr(minleft, minlen);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends