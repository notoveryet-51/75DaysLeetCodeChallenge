class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double avg,total=0;
        for (int i=0; i<k; i++) {
            total+=nums[i];
        }
        avg=total/k;
        //constant window selection
        int i=1, j=i+k-1;
        while (j<n) {
            total=total-nums[i-1]+nums[j];
            double temp=total/k;
            avg=max(avg,temp);
            i++;    j++;
        }
        return avg;
    }
};