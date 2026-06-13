class Solution {
public:
    int trap(vector<int>& height) {
        int water=0;
        int n=height.size();

        // prefix arrays
        vector<int> maxLeft(n,-1);
        vector<int> maxRight(n,-1);

        for(int i=1;i<n;i++)
            maxLeft[i]=max(maxLeft[i-1],height[i-1]);

        for(int i=n-2;i>=0;i--)
            maxRight[i]=max(maxRight[i+1],height[i+1]);
        
        for(int i=1;i<n-1;i++){
            // water
            int minHeight = min(maxLeft[i],maxRight[i]);
            if(minHeight > height[i])
                water += (minHeight - height[i]);
        }
        return water;
    }
};