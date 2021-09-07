class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n=arr.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++)    //a seq of length=1 starts from every element (only that element)
            s.insert(arr[i]);
        
        int maxlen=0;   //to keep track of maxlength sequence
        for(int i=0;i<n;i++)
        {
            //if arr[i]-1 is not found, it means that seq starts from arr[i] itself.
            //otherwise we would take arr[i]-1 as start
            if(s.find(arr[i]-1)==s.end())   
            {
                int curr = arr[i];  //current element
                int currlen = 1;    //initial seq of length 1
                
                //now we move upwards to find a consecutive seq starting from arr[i]
                while(s.find(arr[i]+1)!=s.end())
                {
                    //if arr[i]+1 is found, we update current length & arr[i]
                    currlen++;
                    arr[i] += 1;    //now next elemnet 
                }
                //we keep moving until we cannot find a consecutive number for our seq
                maxlen=max(maxlen,currlen); //update maxlength
            }
        }
        return maxlen; 
    }
};