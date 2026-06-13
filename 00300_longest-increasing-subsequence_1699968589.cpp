class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Logic: Binary Search based (see video, by-heart this soln)

        // create a temp vector to hold temp lis forming values
        vector<int> temp;
        // iterate over the array
        // if num > temp.last or temp.isEmpty --> append
        // if num < temp.last, find correct position using lower_bound
        for (int num : nums) {
            auto it = lower_bound(temp.begin(), temp.end(), num);
            if (it == temp.end()) {
                temp.push_back(num);  // Append
            } else {
                *it = num;  // Replace first element >= num
            }
        }
        // at the end, the size of temp will the answer
        return temp.size();
    }
};