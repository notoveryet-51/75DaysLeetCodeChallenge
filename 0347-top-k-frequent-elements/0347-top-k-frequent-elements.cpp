class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        vector<int>vec;
        for (int i=0; i<nums.size(); i++)   mp[nums[i]]++;  
        vector<pair<int,int>>p;
        for (auto it: mp)    p.push_back({it.second,it.first});
        sort(p.begin(),p.end(),greater<>());
        for (int i=0; i<k; i++)    {
            vec.push_back(p[i].second);
        }
        return vec;
    }
};