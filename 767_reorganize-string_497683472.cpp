class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        
        int count[26] = { 0 };
        //for (auto c : S)  //store freq
        //count[c-'a']++;
        
        
        //store & check if freq>half of str.length --> return null in that case
        for(auto c: s)
        {
            if (++count[c-'a'] > (s.size() + 1)/2)
                return "";
        }
        
        for (int i = 0; i < 26; ++i)    //store freq and char pair 
        {
            if (count[i])
                pq.push({count[i], i + 'a'});
        }
        
        string ans;
        while(!pq.empty()) 
        {
            pair<int, char> p1, p2;
            p1 = pq.top();  //store most frequent (found at top)
            pq.pop();       //remove the stored top to not include it next time
            ans.push_back(p1.second);   //add to res string
            
            if (!pq.empty()) 
            {
                p2 = pq.top();  //store next most frequent
                pq.pop();       //remove it
                ans.push_back(p2.second);   //add to res string
                if (--p2.first)     //decrease freq & push
                    pq.push(p2);
            }
            if (--p1.first)         //decrease freq & push
                pq.push(p1);
        }
        return ans;
    }
};