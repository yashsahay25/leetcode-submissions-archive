typedef pair<int, int> pp;
class compare
{
    public:
        bool operator()(pp a, pp b)
        {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second < b.second;
        }
};
class Solution
{
    public:
        vector<int> topKFrequent(vector<int> &nums, int k)
        {
            unordered_map<int, int> mp;
            vector<int> res;
            for (int element: nums)
                mp[element]++;

            priority_queue<pp, vector < pp>, compare> pq(mp.begin(), mp.end());
            while (k--)
            {
                res.push_back(pq.top().first);
                pq.pop();
            }
            return res;
        }
};