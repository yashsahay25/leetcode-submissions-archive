class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
		int lo = matrix[0][0];
        int hi = matrix[n - 1][n - 1];
		int mid = 0;
        
        /*using binary search concept
         in BS, we always want our answer to be mid & likewise apply conditions.
         terminating condition if return arr[mid] (if element is found)
         Using the same principle here*/
		while (lo < hi)
		{
			mid = lo + (hi-lo)/2;
			int count = 0;  //count of numbers which are less than mid
			
            //calculating count
            for (int i = 0; i < n; i++)
			{
				int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
				count += pos;
			}
            /*if count of numbers less than mid is less than k, it means 
            that the kth element is not present b/w lo and mid. So, we find in upper half. 
			*/
            if (count < k)    
			{
				lo = mid + 1;
			}
			else
			{
				/*here, count >=k --> 2 cases arise : count==k and count>k
                in either case, we will continue our loop as the calculated mid 
                may not be present in the matrix. 
                This ensures we get the answer always pointed by lo.
                */
                hi = mid;
			}
		}
		return lo;  //lo always contains the answer
    }
};