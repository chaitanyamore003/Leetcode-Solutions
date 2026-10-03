class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums2.begin(), nums2.end());
        unordered_set<int> ans;
        for(auto it : nums1){
            if(st.count(it) && !ans.count(it)) ans.insert(it);
        }
        return vector<int>(ans.begin(), ans.end());
    }
};