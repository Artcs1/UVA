#include<bits/stdc++.h>

using namespace std;

vector<int>ady[1010];
int f;
int matriz[1005][1005];
int pai[1010];

#define inf_i (1<<30)

void augment(int u,int minEdge)
{
	if(u==0){f = minEdge;return ;}
	else if(pai[u]!=-1)
	{
		augment(pai[u],min(minEdge,matriz[pai[u]][u]));
		matriz[pai[u]][u]-=f;
		matriz[u][pai[u]]+=f;
		ady[u].push_back(pai[u]);
	}
}
int main()
{
/*	
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/	
	int cases,temp,vez =1 ;
	scanf("%d",&cases);
	while(cases--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		int s=0,t=n+m+1;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&temp);
				matriz[i+1][n+j+1]=temp;
				if(temp)
					ady[i+1].push_back(n+j+1);
			}
		}
		for(int i=0;i<n;i++)
		{ady[s].push_back(i+1),matriz[s][i+1] = 1;}
		for(int i=0;i<m;i++)
		{ady[n+i+1].push_back(t),matriz[n+i+1][t] = 1;}

		int mf=0;
		while(true)
		{	
			f=0;
			vector<int>dist;
			dist.assign(n+m+2,inf_i);
			dist[0]=0;
			memset(pai,-1,sizeof pai);
			pai[0] = -1;
			queue<int>q;
			q.push(0);		
			while(!q.empty())
			{
				int u = q.front();
				q.pop();
				if(u==t)
					break;
				for(int i=0;i<ady[u].size();i++)
				{
					int v = ady[u][i];
					if(dist[v]==inf_i&&matriz[u][v]>0)
					{
						pai[v]=u;
						dist[v]= dist[u]+1;
						q.push(v);
					}
				}
			}
			augment(t,inf_i);
			if(f==0)break;
			mf+=f;
		}
	
		printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",vez++,mf);
		for(int i=0;i<n+m+2;i++)
			ady[i].clear();
	
	}
/*
    fclose(stdin);
    fclose(stdout);
*/
	return 0;
}
