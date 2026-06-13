class Solution {
public:
    int findComplement(int num) {
        // take xor of num & mask (0000....111)
        // only Leftmost Set bit to Rightmost Set Bit to be filpped
        int mask = 0;      
        int temp = num; // copy num into temp
        while(temp){
            mask = (mask << 1) | 1; // set righmost bit as 1 in mask
            // keep right shifting temp until no more set bits are left
            // ie. temp becomes 0
            temp = temp >> 1; 
        }              	
        return mask ^ num;  
    }
};