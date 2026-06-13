class Solution
{
    public:
        int countTriplets(vector<int> &arr)
        {
           	// Optimised - O(N^2) Time and O(1) Space
           	// we just need to find all subarrays whose xor is 0
           	// no need of prefix xor array
            int count = 0;
            for (int i = 0; i < arr.size(); i++)
            {
                int xorOfRange = arr[i];
                for (int k = i + 1; k < arr.size(); k++)
                {
                    xorOfRange = xorOfRange ^ arr[k];
                    if (xorOfRange == 0)
                    {
                        count += (k - i);
                       	//[i to k] is an array where j can take values from i+1 to k
                       	// i and k remain fixed
                       	// no of values of j = k-(i+1)+1 = k-i
                    }
                }
            }
            return count;
        }
};