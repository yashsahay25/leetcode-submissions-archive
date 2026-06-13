class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries,
                                     int x) {
        vector<int> answer;
        vector<int> indices;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                indices.push_back(i);
            }
        }
        for (int query : queries) {
            if (query <= indices.size()) {
                answer.push_back(indices[query - 1]);
            } else {
                answer.push_back(-1);
            }
        }
        return answer;
    }
};