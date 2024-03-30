class Solution {
private:
    int firstOcc(vector<int> &arr, int &t) {
        int n = arr.size();
        int lo = 0, hi = n-1;
        int ans = -1;

        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;

            if(arr[mid] == t) {
                ans = mid;
                hi = mid-1;
            }
            else if(arr[mid] < t) {
                lo = mid+1;
            }
            else {
                hi = mid-1;
            }
        }

        return ans;
    }

    int lastOcc(vector<int> &arr, int &t) {
        int n = arr.size();
        int lo = 0, hi = n-1;
        int ans = -1;

        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;

            if(arr[mid] == t) {
                ans = mid;
                lo = mid+1;
            }
            else if(arr[mid] < t) {
                lo = mid+1;
            }
            else {
                hi = mid-1;
            }
        }

        return ans;
    }

public:
    vector<int> searchRange(vector<int>& arr, int t) {
        
        int f = firstOcc(arr, t);
        int l = lastOcc(arr, t);

        return {f, l};
    }
};