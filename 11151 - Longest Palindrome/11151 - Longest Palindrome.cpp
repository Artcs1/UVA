#include<bits/stdc++.h>

using namespace std;

string c1;
int memo[1005][1005],t1;
int dp(int i,int j)
{
	if(i==j)
		return 1;
	if(i>j)
		return 0;
	if(memo[i][j]!=-1)
		return memo[i][j];
	int res = 0 ;
	if(c1[i]==c1[j])
		res = 2+ dp(i+1,j-1);
	res = max(res,max(dp(i+1,j),dp(i,j-1)));
	return memo[i][j] = res;
}

int main()
{
	int cases;
	scanf("%d",&cases);
	cin.ignore();
	while(cases--)
	{
		getline(cin,c1);
		memset(memo,-1,sizeof memo);
		t1 = c1.size();
		printf("%d\n",dp(0,t1-1));	
	}
}
