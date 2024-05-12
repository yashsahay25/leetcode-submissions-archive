class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Hashing BFS
        if(nums.size()==0) return 0;
        
        unordered_map<int, bool> visited;
        for (int i = 0; i < nums.size(); i++) {
            visited.insert({nums[i], false});
        }

        int maxLen = 1;
        for (int i = 0; i < nums.size(); i++) {
            int current = nums[i], len = 1;
            if (visited[current] == true)
                continue;

            visited[current] = true;
            int next = current + 1, prev = current - 1;
            while (visited.find(next) != visited.end()) {
                len++;
                visited[next] = true;
                next++;
            }
            while (visited.find(prev) != visited.end()) {
                len++;
                visited[prev] = true;
                prev--;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};