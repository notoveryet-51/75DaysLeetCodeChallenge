class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> st;
        vector<int> v;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        for (int i = 1; i <= n; i++) {
            if (st.find(i) == st.end()) {
                v.push_back(i);
            }
        }
        return v;
    }
};