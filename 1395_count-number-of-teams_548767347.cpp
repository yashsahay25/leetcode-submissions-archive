class Solution {
public:
    int numTeams(vector<int>& arr) {
        int n=arr.size(),count=0;
        /*brute-force
        for(int i=0;i<n-2;i++)
            for(int j=i+1;j<n-1;j++)
                for(int k=j+1;k<n;k++)
                {
                    if(arr[i]<arr[j] and arr[j]<arr[k])
                        count++;
                    else if(arr[i]>arr[j] and arr[j]>arr[k])
                        count++;
                }*/
        
        for(int j=0;j<n;j++)
        {
            int leftsmaller=0,rightlarger=0,leftlarger=0,rightsmaller=0;
            for(int i=0;i<j;i++)
            {
                if(arr[i]<arr[j])
                    leftsmaller++;
                else
                    leftlarger++;
            }
            for(int k=j+1;k<n;k++)
            {
                if(arr[k]>arr[j])
                    rightlarger++;
                else
                    rightsmaller++;
            }
            count += leftsmaller*rightlarger + leftlarger*rightsmaller;
        }
        return count;
    }
};