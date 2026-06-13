class Solution
{
    public:
        vector<int> singleNumber(vector<int> &nums)
        {
           	// refer to video solution https://www.youtube.com/watch?v=XAmaiztzDiQ 
            long int res = 0;	// store xor of whole array
            for (int num: nums)
            {
                res = res ^ num;	// calculate xor of whole array
            }
           	// calculate mask (isolate the rightmost set bit of res)
            long mask = res & (-res);

            int first = 0;	// first single number
            for (int num: nums)	// iterate over the array
            {
               	// take and of arr[i] & mask, if it's non-zero, it means has given set bit
                if ((mask & num) != 0)
                {
                    first = first ^ num;
                }
            }
           	// say xor = a^b. We have found a, to find b, we xor with a again
           	// so xor^a = a^b^a = b
            int second = first ^ res;	// second single number

            return {first,second};
        }
};