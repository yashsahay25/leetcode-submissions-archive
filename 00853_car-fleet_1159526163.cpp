class Solution
{
    public:
        int carFleet(int target, vector<int> &position, vector<int> &speed)
        {
           	// take greedy approach
           	// using Stack
            int n = speed.size();
            vector<pair<int, double>> cars;	// (position,timeToReachTarget)
            for (int i = 0; i < n; i++)
            {
                double timeToReach = (target - position[i]) *1.0 / speed[i];
                cars.push_back({ position[i],
                    timeToReach });
            }
            sort(cars.begin(), cars.end());

           	// main logic
            stack<double> st;
            for (int i = 0; i < n; i++)
            {
               	// remove if car at top of stack is faster/gets merged
                while (!st.empty() && st.top() <= cars[i].second)
                    st.pop();
                st.push(cars[i].second);	// push if unmerged
            }
            return st.size();	//  number of unmerged fleets left will be ans
        }
};