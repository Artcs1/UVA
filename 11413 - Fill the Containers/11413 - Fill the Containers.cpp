
#include<stdio.h>
#include<vector>

using namespace std;

vector<int>arr;

int f(int mid)
{
	int c =0,s=0;
	for(int i =0 ; i<(int)arr.size();i++)
	{
		s+=arr[i];
		if(s>mid)
		{
			s=0;
			c++;
			i--;
		}
	}
	return c+1;
}

int main()
{
	int n,m,temp,suma,maxi;
	while(~scanf("%d %d",&n,&m))
	{
		suma =0;
		maxi =0;
		arr.clear();
		arr.push_back(0);
		for( int i =0 ; i< n ;i++)
		{
			scanf("%d",&temp);
			arr.push_back(temp);
			suma+=temp;
			maxi = max(maxi,temp);
		}
		int ini = maxi,fin = suma;
		while(ini<=fin)
		{
			int mid =(ini+fin)/2;
			if(f(mid)<=m)
				fin = mid - 1;
			else
				ini = mid + 1;
		}
		printf("%d\n",fin+1);
	}

}
