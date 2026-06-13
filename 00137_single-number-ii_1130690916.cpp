class Solution
{
    public:
        int singleNumber(vector<int> &nums)
        {
           	// if 2 occurs 1x in the array, store it in once
           	// if 2 occurs 2x, remove from once and store in twice
           	// if 2 occurs 3x, we need to check value of both once &twice and update accordingly
            int once = 0, twice = 0;	// to store the numbers against their freq
            for (int num: nums)
            {
                once = (once ^ num) &~twice;	// update once if &only if, not occurs in twice
                twice = (twice ^ num) &~once;	// update twice if &only if, not occurs in once
            }
            return once;
        }
};