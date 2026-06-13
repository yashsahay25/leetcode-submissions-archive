class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        int g=__gcd(mn,mx);
        return g;
    }
};