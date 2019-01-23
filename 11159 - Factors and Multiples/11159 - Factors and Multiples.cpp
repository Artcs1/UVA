#include<bits/stdc++.h>

using namespace std;

#define inf_i (1<<30)

int pai[205];
int M[205][205];
vector<int>ady[205];
int f;

void Augment(int u,int minEdge)
{
	if(u==0){f = minEdge;return;}
	else if(pai[u]!=-1)
	{
		Augment(pai[u],min(M[pai[u]][u],minEdge));
		M[u][pai[u]] += f;
		M[pai[u]][u] -= f;
		ady[u].push_back(pai[u]);
	}
}
int main()
{
	int cases;
	scanf("%d",&cases);
	for(int c=0;c<cases;c++)
	{
		int A[105],B[105];
		int n,m,temp,cant;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&A[i]);
		scanf("%d",&m);
		for(int i=0;i<m;i++)
			scanf("%d",&B[i]);
		
		
		memset(M,0,sizeof M);
		int s=0,t = n+m+1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(B[j]==0)
				{ady[i+1].push_back(n+j+1),M[i+1][n+j+1]=1;}
				else if(A[i]==0)
				{M[i+1][n+j+1] = 0;}
				else if(B[j]%A[i]==0)
				{ady[i+1].push_back(n+j+1),M[i+1][n+j+1]=1;}
			}
		}

		for(int i=0;i<n;i++)
		{	ady[s].push_back(i+1),M[s][i+1] = 1; }
		for(int i=0;i<m;i++)
		{	ady[i+n+1].push_back(t),M[i+n+1][t]=1 ;}
	
	
		int mf =0 ;
		while(true)
		{
			f=0;
			queue<int>q;
			q.push(0);
			memset(pai,-1,sizeof pai);
			vector<int>dist(205,inf_i);
			dist[0] = 0;
			while(!q.empty())
			{
				int u = q.front();
				q.pop();
				if(u==t)
					break;
				for(int i = 0 ; i < ady[u].size();i++)
				{
					int v = ady[u][i];
					if(dist[v]==inf_i&&M[u][v]>0)
					{
						dist[v]=dist[u]+1;
						q.push(v);
						pai[v]=u;
					}
				}
			}
			Augment(t,inf_i);
			if(f==0)break;
			mf+=f;
		}
		printf("Case %d: %d\n",c+1,mf);
		for(int i=0;i<n+m+2;i++)
			ady[i].clear();
	}
	return 0;
}
