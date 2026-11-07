class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n-1;
        int cnt = 0;
        while(i >= 0 && s[i] == ' ') i--; //spaces skipped
        while(i >= 0 && s[i] != ' '){ //last word 
            i--;
            cnt++;
        }
        return cnt;
    }
};