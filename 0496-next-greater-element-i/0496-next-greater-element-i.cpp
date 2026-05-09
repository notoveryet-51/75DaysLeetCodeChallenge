class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        for (int i=0; i<nums1.size(); i++) {
            for  (int j=0; j<nums2.size(); j++) {
                if (nums1[i]==nums2[j]) {
                    for (int k=j+1; k<nums2.size(); k++) {
                        if (nums1[i]<nums2[k]) {
                            v.push_back(nums2[k]); break;
                        }
                    }
                }
            }
            if (v.size()<i+1)   v.push_back(-1);
        }
        return v;
    }
};