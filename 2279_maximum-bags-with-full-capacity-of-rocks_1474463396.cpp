class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int k) {
        vector<int> space; // remainingSpace (can reuse rocks array also)
        for (int i = 0; i < rocks.size(); i++) {
            space.push_back(capacity[i] - rocks[i]);
        }
        // first fill smallest remaining space bag
        sort(space.begin(), space.end());
        int count = 0;
        for (int s : space) {
            if(s==0) count++;
            else if (k >= s) {
                k = k - s;
                count++;
            }
        }
        return count;
    }
};