class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        list<int> q;
        
        int i=0,j=0,n=nums.size();
        while(j<n)
        {
            //do calculations
            //remove all prev smaller elements until list is not empty
            while(q.size()>0 and q.back()<nums[j])
                q.pop_back();
            q.push_back(nums[j]);    //finally add elememt at j
            
            //reach window size
            if(j-i+1<k) j++;
            else if(j-i+1==k)
            {
                //get answer
                //our list->front contains the maximum value of that window
                res.push_back(q.front());
                
                //remove calc for i
                //if start element of window ie arr[i] is itslef maxm,
                //remove it from queue
                if(nums[i]==q.front())
                    q.pop_front();
                i++;j++;
            }
        }
        return res;
    }
};