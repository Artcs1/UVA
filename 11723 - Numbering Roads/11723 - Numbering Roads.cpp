#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,m,vez=1;
	while(~scanf("%d %d",&n,&m)&&(n!=0||m!=0))
	{
		printf("Case %d: ",vez++);
		if(n>((m*26)+m))
			printf("impossible\n");
		else
		{
			if(n-m<=0)
			{
				printf("0\n");
			}
			else
			{
				int n2 = n-m;
				printf("%d\n",(n2-1)/m +1 );
			}
		}
	}
	return 0;
}
