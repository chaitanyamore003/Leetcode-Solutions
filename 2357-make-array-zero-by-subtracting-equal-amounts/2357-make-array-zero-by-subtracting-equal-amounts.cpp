class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // number of unique elements
        // leaving zeros because they are already zeros

        unordered_set<int> st;
        for (auto& it : nums)
            if (it)
                st.insert(it);
        return st.size();
    }
};