class Solution {
public:
    bool canJump(vector<int>& nums) {
        //let last be the last reachable index
        //initially last=n-1
        //now, we iterate from right to left to check whether this position can be reached
        //or not from any previous position. if yes, we update last to this position
        int n=nums.size();
        int last=n-1;
        for(int i=n-2;i>=0;i--)
        {
            //if we can reach/exceed end, it means that
            if(i+nums[i]>=last)
                last=i;
        }
        //Keep track of the smallest index that can "jump" to the last index. Check whether the current         index can jump to this smallest index.
        return last==0;
    }
};