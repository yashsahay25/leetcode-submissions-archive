class Solution {
public:
bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
	bool one,two,three,four;
    one=two=three=four=true;
	int n=mat.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(mat[i][j]!=target[i][j]) one=false;
			if(mat[i][j]!=target[n-j-1][i]) two=false;
			if(mat[i][j]!=target[n-i-1][n-j-1]) three=false;
			if(mat[i][j]!=target[j][n-i-1]) four=false;
		}
	}
	return one||two||three||four;
}
};