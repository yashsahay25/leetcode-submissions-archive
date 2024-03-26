typedef pair<int, int> pp;
class Solution
{
    public:
        vector<int> topKFrequent(vector<int> &nums, int k)
        {
            vector<int> res;
            unordered_map<int, int> mp;
            for (int e: nums) mp[e]++;

            priority_queue<pp, vector < pp>, greater < pp>> pq;	//min heap
            for (auto it: mp)
            {
                pq.push({ it.second,it.first });
                if (pq.size() > k)
                    pq.pop();
            }
            while (pq.size() > 0)
            {
                res.push_back(pq.top().second);
                pq.pop();
            }
            return res;
        }
};