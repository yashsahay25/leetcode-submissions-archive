class Solution {
public:
    string countAndSay(int n) {
        string current = "1"; // start with base case

        // build iteratively
        for (int i = 2; i <= n; i++) {
            string next = "";
            int freq = 1;

            for (int j = 1; j < current.size(); j++) {
                if (current[j] == current[j - 1]) {
                    freq++; // increase freq if repeated char
                } else {
                    // form next seq if non repeated char occurs
                    next += to_string(freq) + current[j - 1];
                    freq = 1; // reset for next fresh char
                }
            }
            // for last char
            next += to_string(freq) + current.back();

            current = next; // update current for next iteration
        }
        return current;
    }
};