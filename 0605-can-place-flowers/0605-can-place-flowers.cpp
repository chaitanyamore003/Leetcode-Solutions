class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();

        //if no flowers need to be planted return true
        if(n == 0) return true;

        // traverse through the array
        for (int i = 0; i < len; i++) {

            // if current bed is empty
            if (flowerbed[i] == 0) {

                // then we should check weather we can plant here or not
                bool leftEmpty = (i == 0) || (flowerbed[i - 1] == 0);
                bool rightEmpty = (i == len - 1) || (flowerbed[i + 1] == 0);

                // so if all clear plant a flower and move on
                if (leftEmpty && rightEmpty) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            // planted all the flowers
            if (n == 0)
                return true;
        }

        // all flowers were not planted
        return false;
    }
};