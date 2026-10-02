class Solution {
private:
    bool isIsomorphic(string& s, string& t) {
        if (s.size() != t.size())
            return false;
        vector<int> map1(26, -1), map2(26, -1);

        for (int i = 0; i < s.size(); i++) {
            if (map1[s[i]-'a'] != map2[t[i]-'a'])
                return false;
            map1[s[i]-'a'] = map2[t[i]-'a'] = i;
        }
        return true;
    }

public:
    vector<string> findAndReplacePattern(vector<string>& words,
                                         string pattern) {
        vector<string> ans;
        for (auto& it : words) {
            if (isIsomorphic(it, pattern))
                ans.push_back(it);
        }
        return ans;
    }
};