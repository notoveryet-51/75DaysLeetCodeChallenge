class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int result;
        int mn=INT_MAX;
        for(int i=0; i<n; i++)  {
            for (int j=i+1; j<n; j++)   {
                for (int k=j+1; k<n; k++)   {
                    int sum=nums[i]+nums[j]+nums[k];
                    int diff=abs(target-sum);
                    if (diff<mn)  {
                        mn=diff;
                        result=sum;
                    }
                }
            }
        }
        return result; 
    }
};