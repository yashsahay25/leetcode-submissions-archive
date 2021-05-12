class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n=logs.size();
        //vector<int> v(101,0);
        int v[101]={0};
        
        for(int i=0;i<n;i++)
            for(int j=0;j<2;j++)
            {
                int start=logs[i][0]-1950;
                int end=logs[i][1]-1951;
                for(int k=start;k<=end;k++)
                    v[k]++;
            }
        //int *p;
        //p = max_element(v.begin(),v.end());
        //return (int*)max_element(v.begin(),v.end())+50;
        return (max_element(v,v+101) - v)+1950;
    }
};