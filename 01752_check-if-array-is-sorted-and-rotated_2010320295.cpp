class Solution {
public:
    bool check(vector<int>& nums) {
        // if the original array is sorted, there will be only 1 drop
        int n = nums.size();
        int drops = 0;
        
        for (int i = 0; i < n; i++) {
            // %n to check wrap around of last & first element
            if (nums[i] > nums[(i + 1) % n])
                drops++;

            if (drops > 1)
                return false;
        }
        return true;
    }
};