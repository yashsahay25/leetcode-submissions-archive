class Solution {
public:
    void swapSort(vector<int> &arr){
        int i=0;
        while(i<arr.size()){
            if(arr[i]!=arr[arr[i]-1]) 
                swap(arr[i],arr[arr[i]-1]);
            else
                i++;
        }
    }
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int N=n*n;
        vector<int> arr;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr.push_back(grid[i][j]);
            }
        }
        swapSort(arr);
        int i;
        for(i=0;i<arr.size();i++){
            if(arr[i]!=i+1)
                break;
        }
        // a-repeat, b-miss
        return {arr[i],i+1};
    }
};