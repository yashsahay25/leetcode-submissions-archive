class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // array size is N+1, so indexes are 0...N
        // Note that the values are within range [1,N]
        // so they can be treated as indexes

        // consider the entire array as a linked list
        // i --> nums[i] will be a link

        // For nums = [1,3,4,2,2]
        // 0 --> 1 --> 3 --> 2 --> 4 --> 2 (2-->4-->2 is a cycle)
        // so we use the floyd/fast-slow 2 pointer approach

        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // bring fast to head, keep slow at same place
        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow; // return fast;
    }
};
