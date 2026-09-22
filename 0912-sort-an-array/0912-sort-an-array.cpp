class Solution {
private:
    void merge(vector<int>& arr, int l, int mid, int r) {
        int i = l;
        int j = mid+1;

        vector<int> temp;
        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j])
                temp.push_back(arr[i++]);
            else
                temp.push_back(arr[j++]);
        }

        while(i <= mid) temp.push_back(arr[i++]);
        while(j <= r) temp.push_back(arr[j++]);

        for (int k = 0; k < temp.size(); k++) {
            arr[l + k] = temp[k];
        }
    }
    void mergeSort(vector<int>& arr, int s, int e) {
        if (s == e)
            return;

        int mid = s + (e - s) / 2;
        mergeSort(arr, s, mid);
        mergeSort(arr, mid + 1, e);
        merge(arr, s, mid, e);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};