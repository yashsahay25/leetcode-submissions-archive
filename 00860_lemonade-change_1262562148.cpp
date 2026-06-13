class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives=0,tens=0,twenties=0;
        for(int b:bills){
            if(b==5){
                fives++;
            }
            else if(b==10){
                tens++;
                if(fives>=1){
                    fives--;
                }
                else return false;
            }
            else if(b==20){
                twenties++;
                if(fives>=1 && tens>=1){
                    fives--,tens--;
                }
                else if(fives>=3){
                    fives-=3;
                }
                else return false;
            }
        }
        return true;
    }
};