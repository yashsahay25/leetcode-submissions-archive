class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        // Brute
        // for(int i=0;i < n;i++){
        //     for(int j=i+1;j < n;j++){
        //         if(arr[i]+arr[j]==k){
        //             return true;
        //         }
        //     }
        // }
        // return -1;

        // Better
        // sort(arr.begin(),arr.end());
        // int lo=0,hi=n-1;
        // while(lo < hi){
        //     if(arr[lo]+arr[hi] < k) lo++;
        //     else if(arr[lo]+arr[hi]>k) hi++;
        //     else if(arr[lo]+arr[hi]==k)
        //         return true;
        // }
        // return false;

        // Optimal
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            int k = target - arr[i];
            if (mp.find(k) != mp.end())
                return {i, mp[k]};
            mp[arr[i]] = i;
        }
        return {-1, -1};
    }
};