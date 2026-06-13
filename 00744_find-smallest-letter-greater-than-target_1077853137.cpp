class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int lo=0,hi=n-1;
        int c = letters[0];
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;

            if(letters[mid] <= target)
                lo = mid+1;
            else if(letters[mid] > target){
                hi = mid-1;
                c = letters[mid];
            }    
        }
        return c;
    }
};