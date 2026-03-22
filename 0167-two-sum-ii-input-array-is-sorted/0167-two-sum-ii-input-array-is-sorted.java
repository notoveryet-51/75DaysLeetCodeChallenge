class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int n=numbers.length;
        int i=0,j=n-1;
        int[] nums=new int[2];
        while (i<j) {
            int sum=numbers[i]+numbers[j];
            if (sum==target)    {
                nums[0]=i+1;  nums[1]=j+1;
                return nums;
            }
            else {
                if (sum>target) j--;
                else i++;
            } 
        }
        return nums;
    }
}