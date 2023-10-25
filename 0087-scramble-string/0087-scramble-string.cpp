class Solution {
private:
    typedef vector<vector<vector<vector<int>>>> fourDimentionalVector;

    bool _mcm(string& s1, string& s2, int left1, int right1, int left2, int right2, fourDimentionalVector& store) {
        if (right1 - left1 != right2 - left2) {
            return false;
        }

        if (left1 == right1) {
            return s1[left1] == s2[left2];
        }

        if (store[left1][right1][left2][right2] != -1) {
            return store[left1][right1][left2][right2] == 1;
        }

        bool result = false;
        int limit = right1 - left1;
        for (int i = 0; i < limit; i++) {
            if (result) {
                break;
            }

            bool option1 = _mcm(s1, s2, left1, left1 + i, left2, left2 + i, store) & _mcm(s1, s2, left1 + i + 1, right1, left2 + i + 1, right2, store);
            bool option2 = _mcm(s1, s2, left1, left1 + i, right2 - i, right2, store) & _mcm(s1, s2, left1 + i + 1, right1, left2, right2 - i - 1, store);

            result = option1 | option2;
        }

        store[left1][right1][left2][right2] = result ? 1 : 0;

        return result;
    }

public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();

        fourDimentionalVector store(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1))));

        return _mcm(s1, s2, 0, n - 1, 0, n - 1, store);
    }
};