class Solution
{
    public:
        int findDuplicate(vector<int> &nums)
        {
            int slow = 0, fast = 0;
           	// each value in nums is also a valid index

           	// use do while loop, as they start at same place
            do {
                slow = nums[slow];	// one place
                fast = nums[nums[fast]];	// two places
            } while (slow != fast);	// until they meet

           	// after they meet, reset slow, move both one by one, return meet point
            slow = 0;	// reset
            while (slow != fast)
            {
                slow = nums[slow];
                fast = nums[fast];	// one place only this time
            }
            return fast;	// OR return slow
        }
};