class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0, j=0 , n=nums.size();
        int sum=0;
        int mn=n+1;
        while (j<n) {
            sum+=nums[j];
            while (sum>=target) {
                int len=j-i+1;
                mn=min(len,mn);
                sum-=nums[i];   i++;
            }
            j++;
        }
        if (mn==n+1 && sum<target) mn=0;
        return mn;
    }
};