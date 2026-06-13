class Solution {
public:
    int kthGrammar(int n, int k) {
    
        if(n==1 && k==1)    
            return 0;
        
        int mid=pow(2,n-1)/2;   //len=2^n-1 mid=len/2
        if(k<=mid)
            return kthGrammar(n-1,k);   //1st half remains same
        else
            return !(kthGrammar(n-1,k-mid));    //2nd half is negation
    }
};