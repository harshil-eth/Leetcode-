class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n = arr.size();
        bool one = 0;
        for(int i=0; i<n; i++) {
            if(arr[i] == 1) one = 1;
            if(arr[i] < 1 || arr[i] > n) arr[i] = 1;
        }
        
        if(one == 0) return 1;
        
        for(int i=0; i<n; i++) {
            int ind = abs(arr[i]) - 1;
            if(arr[ind] < 0) continue;
            arr[ind] = -(arr[ind]);
        }
        
        for(int i=0; i<n; i++) {
            if(arr[i] > 0) {
                return i+1;
            }
        }
        
        return n+1;
    }
};