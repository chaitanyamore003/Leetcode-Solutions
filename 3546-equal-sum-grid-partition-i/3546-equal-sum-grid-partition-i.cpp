using vi = vector<long long>;

class Solution {

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vi rowSum(rows);
        vi colSum(cols);
        long long total = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
                total += grid[i][j];
            }
        }

        //if total is odd it cannot be partitioned in two equal halves
        if(total & 1) return false;

        // checking rows partition horizontal partition
        long long leftSum = 0;
        for (int i = 0; i < rowSum.size(); i++) {
            leftSum += rowSum[i];
            if (leftSum > total / 2)
                break;
            else if (leftSum == total / 2)
                return true;
        }

        // checking columns parition vertical partition
        leftSum = 0;
        for (int i = 0; i < colSum.size(); i++) {
            leftSum += colSum[i];
            if (leftSum > total / 2)
                break;
            else if (leftSum == total / 2)
                return true;
        }

        // checked all possible combinations but cannot make a partition
        return false;
    }
};