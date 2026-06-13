class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lo=0,hi=n-1,lmax=0,rmax=0,res=0;
        
        //instead of having two arrays, we can have 2 variables/pointers
        //which we update on the go
        while(lo<=hi)
        {
            if(height[lo]<=height[hi])
            {
                if(height[lo]>lmax)
                    lmax = height[lo];
                else
                    res+= lmax-height[lo];
                lo++;
            }
            else
            {
                if(height[hi]>rmax)
                    rmax = height[hi];
                else
                    res+= rmax-height[hi];
                hi--;
            }
        }
        return res;
    }
};