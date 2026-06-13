class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        // is b a substring of repeated a - how many times?

        // b = k*a - (abcd)
        // b = some_prefix + k*a - cd (abcd)
        // b = n*a + some_suffix - (abcd) ab
        // b = some_prefix + k*a + some_suffix - cd (abcd) ab

        // here we can see that b can repeat exact k times, or
        // (k+1) times or (k+2) times

        int k = ceil(b.size() / a.size());
        string repeatA = "";
        // Case 1
        for (int i = 1; i <= k; i++)
            repeatA += a; // k*a
        if (repeatA.find(b) != string::npos)
            return k;

        // Case 2
        repeatA += a; // (k+1)*a
        if (repeatA.find(b) != string::npos)
            return k + 1;

        // Case 3
        repeatA += a; // (k+2)*a
        if (repeatA.find(b) != string::npos)
            return k + 2;

        // Not found
        return -1;
    }
};