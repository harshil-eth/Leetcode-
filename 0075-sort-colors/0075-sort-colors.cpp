class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int lo =0, hi = n-1, mid=  0;
        
        while(mid <= hi) {
            if(arr[mid] == 0) {
                swap(arr[lo], arr[mid]);
                lo++, mid++;
            }
            else if(arr[mid] == 1) mid++;
            else {
                swap(arr[hi], arr[mid]);
                hi--;
            }
        }
    }
};