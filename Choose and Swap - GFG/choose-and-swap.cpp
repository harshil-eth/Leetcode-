//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    string chooseandswap(string s){
        // Code Here
        int n=s.size();
        set<char> st;
        for(int i=0; i<n; i++) st.insert(s[i]);
        for(int i=0; i<n; i++) {
            st.erase(s[i]);
            if(st.size() == 0) break;
            char ch = *st.begin();
            if(ch < s[i]) {
                int ch2 = s[i];
                for(int j=0; j<n; j++) {
                    if(s[j] == ch) s[j] = ch2;
                    else if(s[j] == ch2) s[j] = ch;
                }
                break;
            }
        }
        
        return s;
    }
    
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}

// } Driver Code Ends