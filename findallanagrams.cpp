class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;

        int n = s.size();
        int m = p.size();

        if (m > n) return result;

        vector<int> target(26, 0);
        vector<int> window(26, 0);

        for (char c : p) {
            target[c - 'a']++;
        }

        for (int i = 0; i < m; i++) {
            window[s[i] - 'a']++;
        }

        if (window == target) {
            result.push_back(0);
        }

        for (int i = m; i < n; i++) {
            window[s[i] - 'a']++;
            window[s[i - m] - 'a']--;

            if (window == target) {
                result.push_back(i - m + 1);
            }
        }

        return result;
    }
};