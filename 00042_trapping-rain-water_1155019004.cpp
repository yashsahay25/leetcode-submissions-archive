class Solution
{
    public:
        int trap(vector<int> &height)
        {
            int n = height.size();
            int lo = 0, hi = n - 1;
            int lmax = 0, rmax = 0, water = 0;

           	//instead of having two arrays, we can have 2 variables/pointers
           	//which we update on the go
            while (lo <= hi)
            {
                if (height[lo] <= height[hi])	// left block
                {
                    if (height[lo] > lmax)	// if bar is longer, update max
                        lmax = height[lo];
                    else
                        water += lmax - height[lo];	// else, it stores water
                    lo++;
                }
                else	// right block
                {
                    if (height[hi] > rmax)	//	// if bar is longer, update max
                        rmax = height[hi];
                    else
                        water += rmax - height[hi];	// else, it stores water
                    hi--;
                }
            }
            return water;
        }
};