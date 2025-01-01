class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        vector < vector < int >> result(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

               
                int currVal = 0;
                int divider = 0;

                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {

                        if (0 <= x && x < m && 0 <= y && y < n) {
                            currVal += img[x][y];
                            divider += 1;
                        }
                    }
                }
                result[i][j] = currVal/divider;
            }
        }
        return result;
    }
};