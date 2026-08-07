class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int> pair1, vector<int> pair2) {
            return pair1[1] < pair2[1];
        });

        for (auto pair: pairs) {
            cout << pair[0] << "," << pair[1] << " ";
        }

        cout << endl;

        int n = pairs.size();
        vector<int> count(n);
        int result = 0;
        for (int i = 0; i < n; i++) {
            int current = 0;
            for (int j = 0; j < i; j++) {
                if (pairs[j][1] < pairs[i][0]) {
                    current = max(current, count[j]);
                }
            }

            count[i] = current + 1;
            result = max(result, count[i]);
        }

        return result;
    }
};

