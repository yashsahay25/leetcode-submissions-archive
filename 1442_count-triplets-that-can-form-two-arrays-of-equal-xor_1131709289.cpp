class Solution
{
    public:
        int countTriplets(vector<int> &arr)
        {
            /*We are searching for sub-array of length ≥ 2 and we need to split it to 2 non-empty arrays so that the xor of the first array is equal to the xor of the second array. This is equivalent to searching for sub-array with xor = 0.
             */
            int count = 0;	// to store result
            int n = arr.size();

           	// prefix xor array
            vector<int> preXor(n);
            preXor[0] = arr[0];
            for (int i = 1; i < n; i++)
            {
                preXor[i] = arr[i] ^ preXor[i - 1];	// prefix logic
            }
           	// actual logic
            for (int i = 0; i < n - 1; i++)
            {
                for (int k = i + 1; k < n; k++)
                {
                   	// by observation, similar to prefix sum (DIY and you'll know)
                    int xorOfRange = preXor[i] ^ preXor[k] ^ arr[i];
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