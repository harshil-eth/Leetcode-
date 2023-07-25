//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<pair<int, int>, int>> arr;
        for(int i=0; i<n; i++) {
            arr.push_back({{start[i], end[i]}, i+1});
        }
        
        sort(arr.begin(), arr.end(), [] (const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
            return a.first.second < b.first.second;
        });
        //sorted acc to ending time
        
        int ansEnd = arr[0].first.second;
        vector<int> res;
        res.push_back(arr[0].second);
        
        for(int i=1; i<n; i++) {
            if(arr[i].first.first > ansEnd) {
                res.push_back(arr[i].second);
                ansEnd = arr[i].first.second;
            }
        }
        
        return res.size();
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends