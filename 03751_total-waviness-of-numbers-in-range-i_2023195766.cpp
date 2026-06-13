class Solution {
public:
    int calc(int num){
        int count=0;
        while(num/100>0){
            int last=num%10;
            int secondLast = (num/10)%10;
            int thirdLast = (num/100)%10;

            if((secondLast < last && secondLast < thirdLast)
                || (secondLast > last && secondLast > thirdLast))
                count++;

            num = num/10;
        }
        return count;
    }
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int num=num1;num<=num2;num++){
            ans += calc(num);
        }
        return ans;
    }
};