#include<bits/stdc++.h>

using namespace std;

string c1,c2;
int t1,t2;
int memo[105][105];

int dp(int i,int j)
{
	if(i==t1||j==t2)
		return 0;
	if(memo[i][j]!=-1)
		return memo[i][j];
	int res = 0;
	if(c1[i] == c2[j])
		res = 1+dp(i+1,j+1);
	res = max(res,max(dp(i+1,j),dp(i,j+1)));
	return memo[i][j] = res;
}
int main()
{
	int vez =1;
	while(getline(cin,c1))
	{
		if(c1[0] == '#')
			break;
		getline(cin,c2);
		t1 = c1.size();
		t2 = c2.size();
		memset(memo,-1,sizeof memo);
		printf("Case #%d: you can visit at most %d cities.\n",vez++,dp(0,0));
	}
	return 0;
}
