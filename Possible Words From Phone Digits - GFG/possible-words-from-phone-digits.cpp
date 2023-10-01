//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    private:
    void f(int ind, string &ds, vector<string> &ans, int arr[], string mp[], int n) {
        if(ind >= n) {
            ans.push_back(ds);
            return;
        }
        
        string s = mp[arr[ind]];
        for(int i=0; i<s.size(); i++) {
            ds.push_back(s[i]);
            f(ind+1, ds, ans, arr, mp, n);
            ds.pop_back();
        }
    }
    
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int arr[], int n)
    {
        //Your code here
        vector<string> ans;
        if(n == 0) return ans;
        
        string mp[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        string ds="";
        f(0, ds, ans, arr, mp, n);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends