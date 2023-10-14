class Solution {
public:
    int beauty(string str){
        int arr[26]={0};
        for(char c:str){
            arr[c-'a']++;
        }
        int maxFreq=INT_MIN,minFreq=INT_MAX;
        for(int i=0;i<26;i++){
            if(arr[i]>maxFreq) maxFreq=arr[i];
            if(arr[i]>0 && arr[i]<minFreq) minFreq=arr[i];
        }
        // cout << maxFreq << " " << minFreq << "\n";
        return maxFreq-minFreq;

    }
    int beautySum(string s) {
        int n =s.length();
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                string str = s.substr(i,j-i+1);
                // cout << str << " ";
                sum += beauty(str);
            }
        }
        return sum;   
    }
};