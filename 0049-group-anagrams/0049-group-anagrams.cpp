class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>vec;
        vector<string>original=strs;
        vector<string>temp;
        set<string>s;
        for (int i=0; i<strs.size(); i++) {
            sort(strs[i].begin(),strs[i].end());
            s.insert(strs[i]);
        }
        for (auto it: s) {
            temp.clear();
            for (int i=0; i<strs.size(); i++) {
                if (it==strs[i]) temp.push_back(original[i]);
            }
            vec.push_back(temp);
        }
        return vec;
    }
};