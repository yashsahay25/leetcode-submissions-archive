class Solution
{
    public:
        int carFleet(int target, vector<int> &position, vector<int> &speed)
        {
           	// take greedy approach
           	// sort &check from back
            int n = speed.size();
            vector<pair<int, double>> cars;	// (position,timeToReachTarget)
            for (int i = 0; i < n; i++)
            {
                double timeToReach = (target - position[i]) *1.0 / speed[i];
                cars.push_back(make_pair(position[i], timeToReach));
            }
            sort(cars.begin(), cars.end());

           	// main logic
            int fleetSize = 0;
            for (int i = n - 1; i > 0; i--)
            {
               	// if prev car takes less time than next one
               	// it means they'll merge &become fleet
                if (cars[i - 1].second <= cars[i].second)
                {
                    cars[i - 1] = cars[i];	// make them same
                }
                else
                    fleetSize++;
            }
           	// add one since last element in loop (first in array)
           	// isn't compared with anyone, so include it
            return fleetSize + 1;
        }
};