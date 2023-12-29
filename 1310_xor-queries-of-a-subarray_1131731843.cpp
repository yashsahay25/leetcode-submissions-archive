class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<int> res(q); // result array
        
        // precompute prefix xor array
        int n = arr.size();
        vector<int> preXor(n);
        preXor[0]=arr[0];
        for(int i=1;i<n;i++){
            preXor[i]=arr[i]^preXor[i-1];
        }

        for(int i=0;i<q;i++){
            int left = queries[i][0];
            int right = queries[i][1];
            res[i] = preXor[left]^preXor[right]^arr[left];
            // By observation, 
            // xor[left...right] = xor of prefix[left], prefix[right] & arr[left]
            // Dry run yourself & you'll get the logic behind it
        }
        return res;
    }
};