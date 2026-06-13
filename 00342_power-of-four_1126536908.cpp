class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0)    return false;
        while(n%4 == 0){
            n = n/4; // keep dividing by 4 until it becomes 1 
        }
        return n==1;   
    }
};