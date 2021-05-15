class Solution {
public:
    int majorityElement(vector<int>& a) {
        int n=a.size();
        int count=0,ele=0;
        for(int i=0;i<n;i++)
        {
            if(count==0)
                ele = a[i];
            if(ele==a[i])
                count++;
            else
                count--;
        }
        return ele;
    }
};