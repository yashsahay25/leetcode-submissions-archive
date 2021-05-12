class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
                map<int,int>mp;
        stack<int>st;
        vector<int>v;
        
        
        for(int i=0;i<nums2.size();i++)
        {
            if(st.size()>0)
            {
                while(st.size()>0&&st.top()<nums2[i])
                {
                    mp[st.top()]=nums2[i];
                    st.pop();
                }
            }
            st.push(nums2[i]);
        }
        
        
        for(int i=0;i<nums1.size();i++)
        {
            if(mp[nums1[i]]==0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(mp[nums1[i]]);
            }
        }
        return v;
    }
};