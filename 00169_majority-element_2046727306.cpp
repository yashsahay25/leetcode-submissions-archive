class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // freq > n/2
        int n = nums.size();

        // assume whole scenario to be elections
        // assume first element to be leading candidate, initial votes = 1
        int leader = nums[0];
        int voteLead = 1; // By how many votes is the leader leading (the excess)

        // iterate from 2nd position onwards
        for (int i = 1; i < nums.size(); i++) {
            // if next position is leader, increase leader's votes
            if (nums[i] == leader) {
                voteLead++;
                // if leader's votes > n/2, majority found
                if (voteLead > n / 2) break;
            } else {
                // another candidate reduces leader's leading votes
                voteLead--;
                // if lead becomes 0, it means no one is in majority
                // But current candidate can be next leader, so we assume here
                if (voteLead == 0) {
                    leader = nums[i];
                    voteLead = 1; // new leader starts with 1 vote
                }
            }
        }
        return leader;
    }
};