class Solution {
    public int[] productExceptSelf(int[] nums) {
        int mul = 1;
        int zeroCount = 0;
        for (int it : nums) {
            if (it == 0) zeroCount++;
            else mul *= it;
        }
        for (int i = 0; i < nums.length; i++) {
            if (zeroCount > 1)  nums[i] = 0;
            else if (zeroCount == 1)
                nums[i] = (nums[i] == 0 ? mul : 0);
            else    nums[i] = mul / nums[i];
        }
        return nums;
    }
}
