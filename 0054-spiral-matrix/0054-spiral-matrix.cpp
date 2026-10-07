class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int fR = 0;
        int lR = rows - 1;
        int fC = 0;
        int lC = cols - 1;

        int cnt = 0;
        vector<int> ans;

        while (cnt < (rows * cols)) {
            // printing first row
            for (int i = fC; i <= lC && (cnt < (rows * cols)); i++) {
                ans.push_back(matrix[fR][i]);
                cnt++;
            }

            fR++;

            // printing last column
            for (int i = fR; i <= lR && (cnt < (rows * cols)); i++) {
                ans.push_back(matrix[i][lC]);
                cnt++;
            }
            lC--;

            // printing last row
            for (int i = lC; i >= fC && (cnt < (rows * cols)); i--) {
                ans.push_back(matrix[lR][i]);
                cnt++;
            }
            lR--;

            // printing first column
            for (int i = lR; i >= fR && (cnt < (rows * cols)); i--) {
                ans.push_back(matrix[i][fC]);
                cnt++;
            }
            fC++;
        }
        return ans;
    }
};