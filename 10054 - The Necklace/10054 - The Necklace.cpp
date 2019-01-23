#include<bits/stdc++.h>

#define REP(i, a) for( int i = 0; i < a; i++ )
#define RFOR(i,x,y) for(int i = x; i>= y; i--)
#define FOR(i,x,y) for (int i = x; i < y; i++)
#define ITFOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define VE vector <int>
#define mset(A,x) memset(A, x, sizeof A)
#define PB push_back
#define ones(x) __builtin_popcount(x)
#define cua(x) (x)*(x)
#define debug(x) cout <<#x << " = " << x << endl
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)
#define LSOne(S) (S&(-S))

using namespace std;

#define ll long long
#define lli long long int
#define PI acos(-1.0)
#define ii pair<int,int>
#define inf_ll (((1LL<<62)-1)<<1)+1
#define inf_i (1<<30)-1

vector< ii > ady[55];
int degree[55],cop[55],cop2[55];
int m;

bool solvable()
{
	for(int i=0;i<52;i++)
	{
		if(degree[i+1]&1)
			return false;
	}
	return true;
}

list<int>cyc;
void solve(list<int>::iterator i,int u)
{
		for(int j=0;j<(int)ady[u].size();j++)
		{
			ii v = ady[u][j];
			if(v.second)
			{
				ady[u][j].second =0;
				for(int k=0;k<(int)ady[v.first].size();k++)
				{
					ii uu =ady[v.first][k];
					if(uu.first ==  u && uu.second)
					{
						ady[v.first][k].second = 0;
						break;
					}
				}
				solve(cyc.insert(i,u),v.first);
			}
		}
}
int main()
{

	int cases,u,v;
	scanf("%d",&cases);
	for(int i=0;i<cases;i++)
	{
		memset(cop,0,sizeof cop);
		memset(degree,0,sizeof degree);
		scanf("%d",&m);
		int ls;
		for(int j=0;j<m;j++)
		{
			scanf("%d %d",&u,&v);
			ls = v;
			if(u!=v)
			{
				ady[u].push_back(ii(v,1));
				ady[v].push_back(ii(u,1));
				degree[u]++,degree[v]++;
			}
			else if(u==v)
				{cop[u]++;}
		}
		
		if(i)
			printf("\n");

		printf("Case #%d\n",i+1);
		if(solvable())
		{
			cyc.clear();
			solve(cyc.begin(),ls);

			vector<int> R;
			for(list<int>::iterator it = cyc.begin();it !=cyc.end();it++)
				R.push_back(*it);
			
			int tam = R.size();
			for(int j=0;j<tam;j++)
			{
				while(cop[R[j]]>0)
				{
					printf("%d %d\n",R[j%tam],R[j%tam] );
					cop[R[j]] --;
				}
				printf("%d %d\n",R[j%tam],R[(j+1)%tam] );
			}
		}
		else
		{
			printf("some beads may be lost\n");
		}
		
		for(int j=0;j<52;j++)
			ady[j+1].clear();
	}
	return 0;
}
