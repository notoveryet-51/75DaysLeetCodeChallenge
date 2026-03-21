class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        for (int i=0; i<n; i++) {
            if (nums[i]!=0) v.push_back(nums[i]);
        }
        int zero=n-v.size();
        for (int i=1;i<=zero; i++)  v.push_back(0);
        nums=v;
    }
};