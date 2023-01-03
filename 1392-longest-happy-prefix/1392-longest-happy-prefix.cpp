class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();

        vector<int> lps(n);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[lps[i - 1]]) {
                lps[i] = lps[i - 1] + 1;
            } else {
                int j = lps[i - 1];

                while (j > 0 && s[i] != s[j]) {
                    j = lps[j - 1];
                }

                if (s[i] == s[j])
                    j++;

                lps[i] = j;
            }
        }

        return s.substr(0, lps[n - 1]);
    }
};
