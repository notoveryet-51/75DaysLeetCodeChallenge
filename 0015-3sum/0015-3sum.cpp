class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int target=0;
        set<vector<int>>st;
        vector<vector<int>>result;
        for (int i=0; i<n; i++)     {
            vector<int>v;
            int reqSum=target-(nums[i]);
            int j=i+1,k=n-1;
            while (j<k) {
                if (nums[j]+nums[k]<reqSum) j++;
                else if (nums[j]+nums[k]==reqSum) {
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    st.insert(v);
                    j++; k=n-1; v.clear();
                }
                else k--;
            }
        }
        for (auto it: st)   result.push_back(it);
        return result;
    }
};