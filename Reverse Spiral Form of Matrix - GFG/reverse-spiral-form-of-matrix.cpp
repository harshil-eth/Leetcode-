//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int row, int col, vector<vector<int>>&matrix)  {
        // code here
        vector<int> ans;
        // int row = matrix.size();
        // int col = matrix[0].size();

        int startingrow = 0;
        int startingcol = 0;
        int endingrow = row-1;
        int endingcol = col - 1;

        int cnt=0;
        int total = row*col;

        while(cnt<total)
        {
            //printing 1st row
            for(int i=startingcol; i<=endingcol && cnt<total; i++)
            {
                ans.push_back(matrix[startingrow][i]);
                cnt++;
            }
            startingrow++;

            for(int i=startingrow; i<=endingrow && cnt<total; i++)
            {
                ans.push_back(matrix[i][endingcol]);
                cnt++;
            }
            endingcol--;

            for(int i=endingcol; i>=startingcol && cnt<total; i--)
            {
                ans.push_back(matrix[endingrow][i]);
                cnt++;
            }
            endingrow--;

            for(int i=endingrow; i>=startingrow && cnt<total; i--)
            {
                ans.push_back(matrix[i][startingcol]);
                cnt++;
            }
            startingcol++;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends