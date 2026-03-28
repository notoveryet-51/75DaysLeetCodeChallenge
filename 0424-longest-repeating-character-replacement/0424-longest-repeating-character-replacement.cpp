class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int hash[26] = {0};
        int left = 0, maxFreq = 0, result = 0;
        for (int right = 0; right < n; right++) {
            hash[s[right] - 'A']++;
            maxFreq = max(maxFreq, hash[s[right] - 'A']);
            int windowSize = right - left + 1;
            if (windowSize - maxFreq > k) {
                hash[s[left] - 'A']--;
                left++;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};