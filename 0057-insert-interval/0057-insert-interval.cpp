class Solution {
private:
    vector<vector<int>> merge(vector<vector<int>> &arr) {
        vector<vector<int>> ans;
        for(int i=0; i<arr.size(); i++) {
            if(ans.empty() || arr[i][0] > ans.back()[1]) {
                ans.push_back(arr[i]);
            }
            else {
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
        }
        
        return ans;
    }
    
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.insert(intervals.begin(), {newInterval[0], newInterval[1]});
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans = merge(intervals);
        return ans;
    }
};