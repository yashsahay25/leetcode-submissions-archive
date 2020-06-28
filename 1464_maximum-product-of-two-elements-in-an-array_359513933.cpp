class Solution {
public:
    int maxProduct(vector<int>& arr) {
        sort(arr.begin(),arr.end(),greater<int> ());
        int ans=(arr[0]-1)*(arr[1]-1);
        return ans;
    }
};