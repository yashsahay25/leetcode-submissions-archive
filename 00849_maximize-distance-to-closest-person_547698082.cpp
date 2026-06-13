class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int l=-1,maxd=0,n=seats.size();
        for(int i=0;i<n;i++)
        {
            //if 0, then we keep on moving
            if(seats[i]==1) //if 1, we check dist till now
            {
                if(l==-1)
                {
                    maxd=i;
                }
                else
                    maxd=max(maxd,(i-l)/2);
                l=i;    //update l to i
            }
        }
        if(seats[n-1]==0)
                maxd=max(maxd,n-1-l);
        return maxd;
    }
};