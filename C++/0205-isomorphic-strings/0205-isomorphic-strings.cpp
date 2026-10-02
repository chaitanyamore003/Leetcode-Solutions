class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // using unique index
        if (s.size() != t.size())
            return false;

        vector<int> map1(256, -1), map2(256, -1);

        for(int i = 0; i < s.size(); i++){
            if(map1[s[i]] != map2[t[i]]) return false;
            map1[s[i]] = map2[t[i]] = i;
        }
        return true;   
    }
};