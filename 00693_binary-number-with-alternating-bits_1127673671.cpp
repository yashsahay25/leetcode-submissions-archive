class Solution
{
    public:
        bool hasAlternatingBits(int n)
        {
           	//      10101010101
           	//  +    1010101010    (number >> 1)
           	//  ---------------
           	//  =   11111111111
           	//  &100000000000
           	//  ---------------
           	//  =             0    (power of two)
            unsigned int temp = n ^ (n >> 1);
            return (temp &(temp + 1)) == 0;
        }
};