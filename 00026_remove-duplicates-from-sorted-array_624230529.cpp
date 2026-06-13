
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) return 0;        // exclude corner case
		int res = 1;
		for(int i=1;i<nums.size();i++){
			if(nums[i] != nums[res-1]){
				nums[res] = nums[i];
				res++;
			}
		}
		return res;
	}
};
/*  We initilize our result as 1 (res=1), 
    we will start from the 2nd element and 
    then we compare every element with the last element 
    that we have included in our result. 
    
    If the current element is not same as nums[res-1] 
    then we got a new distinct element. 
    
    we copy at the index result ( nums[res] = nums[i] ) 
    and increment result and 
    in the end simply return res.
*/
