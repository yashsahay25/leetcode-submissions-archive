class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> S;
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++)
            S.insert(arr[i]);

        for (int i = 0; i < n; i++) 
        { 
            if (S.find(arr[i] - 1) == S.end()) 
            { 
                int j = arr[i]; 
                while (S.find(j) != S.end()) 
                    j++; 

                ans = max(ans, j - arr[i]); 
            } 
        } 
        return ans; 
    }
};