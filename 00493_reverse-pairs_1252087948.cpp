class Solution {
public:
    void merge(vector<int>& arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - (m + 1) + 1;
        vector<int> left(n1), right(n2);

        // populate
        for (int i = 0; i < n1; i++)
            left[i] = arr[l + i];
        for (int j = 0; j < n2; j++)
            right[j] = arr[m + 1 + j];

        // merge both
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
            }
        }
        // copy remaining elements
        while (i < n1) {
            arr[k++] = left[i++];
        }
        while (j < n2) {
            arr[k++] = right[j++];
        }
    }
    int countPairs(vector<int>& arr, int l, int m, int r) {
        int count = 0;
        //[l...m] &[m+1...r]
        int i = l, j = m + 1;
        while (i <= m) {
            while (j <= r && (long long)arr[i] > (long long)2 * arr[j]) {
                j++;
            }
            count += (j - (m + 1));
            i++;
        }
        return count;
    }
    int mergeSort(vector<int>& arr, int l, int r) {
        int count = 0;
        if (l >= r)
            return count;
        int m = l + (r - l) / 2;

        count += mergeSort(arr, l, m);
        count += mergeSort(arr, m + 1, r);
        count += countPairs(arr, l, m, r);
        merge(arr, l, m, r);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};