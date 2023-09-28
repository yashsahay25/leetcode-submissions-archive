class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int n = numbers.size();
        int l = 0, r = n-1;
        while(l<r){
            int sum = numbers[l]+numbers[r];
            if(sum==target){
                res.push_back(l+1);
                res.push_back(r+1);
                l++; r--;
            }
            else if(sum > target) r--;
            else l++;
        }
        return res;
    }
};