class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (num < 0 || sum > num * 9)
            return "";

        // number of nines we can take
        int nines = sum / 9;
        // remaining number after taking all possible nines
        int rem = sum % 9;

        // added nines in result
        string result(nines, '9');

        // append the reminder
        if (rem > 0) {
            result.push_back(rem + '0');
        }

        // add zeros for remaining digits
        result.append(num - result.size(), '0');

        return result;
    }
};