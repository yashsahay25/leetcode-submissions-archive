class Solution {
public:
    int bitwiseComplement(int num) {
        if(num==0) return 1;
        int bits = (int)log2(num)+1;
        long nearestPowerOf2 = pow(2,bits)-1;
        if(nearestPowerOf2 < num) 
            return (int)nearestPowerOf2;
        return (int)(nearestPowerOf2 - num);
    }
};