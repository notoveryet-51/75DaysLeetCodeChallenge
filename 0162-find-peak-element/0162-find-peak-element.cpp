class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        vector<int>copy;
        copy.push_back(INT_MIN);
        for (auto it: nums) copy.push_back(it);
        copy.push_back(INT_MIN);
        int n=copy.size();
        for (int i=1; i<n-1; i++) {
            if (copy[i]> copy[i-1] && copy[i]>copy[i+1]) {
                return i-1;
            }
        }
        return 0;
    }
};