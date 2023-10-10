class Solution {
public:
    string largestOddNumber(string num) {
        string res="";
        
        // start from reverse & search for first odd digit
        // anything infront of it will become the answer
        int i;
        for(i=num.size()-1;i>=0;i--){
            if(num[i]=='1' || num[i]=='3' || num[i]=='5' || num[i]=='7' || num[i]=='9')
                break;
        }
        for(int j=0;j<=i;j++)
            res+= num[j];
        return res;
    }
};