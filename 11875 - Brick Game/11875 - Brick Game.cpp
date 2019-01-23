#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int m,temp;
		scanf("%d",&m);
		vector<int>A;
		for(int j=0;j<m;j++)
		{
			scanf("%d",&temp);
			A.push_back(temp);
		}
		printf("Case %d: %d\n",i+1,A[m/2]);
	}
	return 0;
}
