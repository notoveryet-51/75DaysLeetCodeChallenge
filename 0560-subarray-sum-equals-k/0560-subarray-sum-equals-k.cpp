class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int a=nums.size();
        int sum;
        int count=0;
        for (int l=0; l<a; l++) {
            sum=nums[l];
            if (sum==k) count++;
            for (int m=l+1; m<a; m++) {
            sum+=nums[m];
            if (sum==k) count++;
            }
        }
        return count;
    }
};