class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // to check if new transformed word exists in wordList or not
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        if (wordSet.find(endWord) == wordSet.end()) return 0;

        // BFS
        queue<pair<string, int>> q; // <word, sequence length>
        q.push({beginWord, 1});
        wordSet.erase(beginWord); // mark as visited

        while (!q.empty()) {
            auto [word, len] = q.front();
            q.pop();

            if (word == endWord) 
                return len; // if tranformed into endWord reached, return seq len so far

            // for each char in the word
            for (int i = 0; i < word.length(); i++) {
                char originalChar = word[i];

                // replace with all chars from a-z
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    // minor optimization: skip same char check
                    if (ch == originalChar) continue;

                    word[i] = ch;
                    if (wordSet.find(word) != wordSet.end()) {
                        // mark as visited (erase from set) so can't be checked again
                        wordSet.erase(word); 
                        // matching word found, add to q with len+1
                        q.push({word, len + 1}); 
                    }
                }

                // reset to the original char
                word[i] = originalChar;
            }
        }
        return 0;
    }
};