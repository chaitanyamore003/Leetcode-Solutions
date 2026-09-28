class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        // using two minimums
        int min1 = INT_MAX; int min2 = 0;
        for(auto& it : prices){
            if(it < min1){
                min2 = min1;
                min1 = it;
            } else if (it < min2){
                min2 = it;
            }
        }

        int amount = min1 + min2;
        int leftOver = money - amount;
        if (leftOver < 0)
            return money;
        else
            return leftOver;
    }
};