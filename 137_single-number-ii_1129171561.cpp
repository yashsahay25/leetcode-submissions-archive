class Solution
{
    public:
        int singleNumber(vector<int> &nums)
        {
            int ans = 0;
           	// consider each number stored as 32 bits
           	// iterate over all the 32 bits
            for (int i = 0; i < 32; i++)
            {
                int countSetBits = 0;	// number of set bits at current position
               	// iterate over each array element
                for (int j = 0; j < nums.size(); j++)
                {
                    if ((nums[j] >> i) &1 == 1)
                    {
                        countSetBits++;	// count if bit is set 
                    }
                }
               	// reset the count of set bits after every three occurrences
               	// since all elemnets occur thrice except the single element
                countSetBits = countSetBits % 3;

               	// if the count is not zero, it means current i'th bit has set bit
               	// so we left shift the countSetBits by i positions, 
               	// aligning it with the correct bit position.
                if (countSetBits != 0)
                    ans = ans | (countSetBits << i);
            }
            return ans;
        }
};