class Solution {
public:
    string largestOddNumber(string num) {
        // start from reverse & search for first odd digit
        // anything infront of it will become the answer
        int n = num.size();
        for (int i = n - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 != 0)
                return num.substr(0, i + 1);
        }
        return "";
    }
};