class Solution {
    public int maxArea(int[] height) {
        int n=height.length;
        int lt=0, rt=n-1;
        int maxWater=0;
        while (lt<rt)  {
            int water=Math.min(height[lt],height[rt])*(rt-lt);
            maxWater=Math.max(maxWater,water);
            if (height[lt]<height[rt]) lt++;
            else rt--;
        }
        return maxWater;
    }
}