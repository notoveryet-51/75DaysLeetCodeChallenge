class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size(),ln=1;
        int dist=1;
        if (n==0) return 0;
        if (n==1) return 1;
        sort(nums.begin(), nums.end());
        int i=0,j=1;
        while (j<n) {
            if (nums[j]-nums[i]==1) {
                j++; i++; dist++; ln=max(ln,dist);
            }
            else if (nums[i]==nums[j]) {
                i++; j++;
            }
            else {
                i=j; j=i+1; dist=1;
            }
        }
        return ln;
    }
};