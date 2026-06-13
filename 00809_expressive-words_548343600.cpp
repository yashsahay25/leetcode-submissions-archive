class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
            int res = 0;
    for (auto &w : words)
        if (w.size() <= S.size()) 
        {
            int i=0,j=0;
            while(j < S.size()) 
            {
                if (w[i] == S[j])
                    i++;
                else if (j > 0 && S[j] == S[j - 1] && j + 1 < S.size() && S[j] == S[j + 1]) 
                    j++;
                else if (!(j > 1 && S[j] == S[j - 1] && S[j] == S[j - 2]))
                    break;
                j++;
            }
            if (i == w.size() && j == S.size())
                res++;
        }
    return res;
    }
};