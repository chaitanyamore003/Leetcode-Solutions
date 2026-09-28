class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int depth = 0;

    
        for(auto it : s){
            //if opening braces depth increases
            if(it == '(') depth++;
            else if(it == ')'){ //if closing braces depth reduces
                depth--;
            }
            //this gives us maximum number of opening brakcets in a row
            ans = max(ans, depth);
        }
        return ans;
    }
};