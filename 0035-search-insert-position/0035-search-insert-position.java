class Solution {
    public int searchInsert(int[] nums, int target) {
        int n=nums.length;
        if (n==1) {
            if (target>nums[0]) return n;
            else return 0;
        }
        for (int i=1; i<n; i++) {
            if (nums[i-1]<target && nums[i]>target) return i;
            else if(nums[i-1]>=target)  return i-1;
            else if (nums[i]==target)   return i;
        }
        return n;
    }
}