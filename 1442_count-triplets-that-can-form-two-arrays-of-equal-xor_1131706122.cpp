class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count=0;
        int n = arr.size();
        
        // prefix xor array
        vector<int> preXor(n);
        preXor[0]=arr[0];
        for(int i=1;i<n;i++){
            preXor[i]=arr[i]^preXor[i-1];
        }
        // actual logic
        for(int i=0;i<n-1;i++){
            for(int k=i+1;k<n;k++){
                int xorOfRange = preXor[i]^preXor[k]^arr[i];
                if(xorOfRange==0){
                    count += (k-i);
                }
            }
        }
        return count;
    }
};