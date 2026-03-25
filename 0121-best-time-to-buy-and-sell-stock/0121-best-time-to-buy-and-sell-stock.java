class Solution {
    public int maxProfit(int[] prices) {
        int n=prices.length;
        int i=0, j=1;
        int max_profit=0;
        while (i<j && i<n && j<n) {
            int profit=prices[j]-prices[i];
            if (profit>0)  {
                max_profit=Math.max(profit,max_profit);
                j++;
            }
            else {
                i=j;
                j++;
            }
        }
        return max_profit;
    }
}