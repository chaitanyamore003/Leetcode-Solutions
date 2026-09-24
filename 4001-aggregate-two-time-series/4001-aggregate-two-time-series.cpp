class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1,
                                            vector<vector<int>>& series2) {
        // optimal using two pointers
        int n1 = series1.size();
        int n2 = series2.size();

        int i = 0;
        int j = 0;

        vector<vector<int>> ans;

        // until both the series are finished
        while (i < n1 || j < n2) {
            int t = 0;

            // finiding minimum timestamp
            if (i == n1)
                t = series2[j][0];
            else if (j == n2)
                t = series1[i][0];
            else {
                t = min(series1[i][0], series2[j][0]);
            }

            // adding the timestamp values
            int val1 = (i == n1) ? 0 : series1[i][1];
            int val2 = (j == n2) ? 0 : series2[j][1];

            // add the processed timestamp
            ans.push_back({t, val1 + val2});

            // move the pointer which is used
            if (i < n1 && t == series1[i][0])
                i++;
            if (j < n2 && t == series2[j][0])
                j++;
        }
        return ans;
    }
};