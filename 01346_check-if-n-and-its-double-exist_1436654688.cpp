class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for (int a : arr) {
            if (s.count(a * 2) || (a % 2 == 0 && s.count(a / 2)))
                return true;
            s.insert(a);
        }
        return false;
    }
};