class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n = arr.size();
        int c1=0, c2=0, el1, el2;
        for(int i=0; i<n; i++) {
            if(c1 == 0 && arr[i] != el2) {
                c1 += 1, el1 = arr[i];
            } else if(c2 == 0 && arr[i] != el1) {
                c2 += 1, el2 = arr[i];
            } else if(arr[i] == el1) c1++;
            else if(arr[i] == el2) c2++;
            else c1--, c2--;
        }
        
        int realc1 = 0, realc2 = 0;
        for(int i=0; i<n; i++) {
            if(arr[i] == el1) realc1++;
            else if(arr[i] == el2) realc2++;
        }
        
        vector<int> ans;
        int mini = n/3 + 1;
        if(realc1 >= mini) ans.push_back(el1);
        if(realc2 >= mini) ans.push_back(el2);
        
        return ans;
    }
};