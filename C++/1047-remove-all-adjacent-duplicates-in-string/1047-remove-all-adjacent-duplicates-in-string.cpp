class Solution {
public:
    string removeDuplicates(string s) {
        //using stack sratergy
        string ans = "";

        for(auto it : s){
            if(ans.empty() || ans.back() != it) ans += it;
            else ans.pop_back();
        }
        return ans;
    }
};