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

vector<int>A,B;
int pa = 0;
int bst[10005][5],sum[300];
void build(int padre,int flag)
{
	int padre2 = pa;
	if(padre!=-1)
	{
		bst[B[padre]][flag] = B[pa];
	}
	pa=pa+1;
	if(B[padre2]!=-1)
	{
		build(padre2,0);
		build(padre2,1);
	}
}

void preorder(int u,int i)
{
	if(u==-1)
		return;
	sum[i] += A[u];
	//printf("U: %d\n",A[u] );
	preorder(bst[u][0],i-1);
	preorder(bst[u][1],i+1);
}
int main()
{

	int n,vez=1;
	while(~scanf("%d",&n)&&n!=-1)
	{
		pa = 0 ;
		vector<int>res;
		A.push_back(n);
		B.push_back(0);
		int m = 2,temp,index = 1;
		for(int i=0;i<m;i++)
		{
			scanf("%d",&temp);
			A.push_back(temp);
			if(temp>=0)
			{	B.push_back(i+1);}
			else
			{	B.push_back(-1);}

			if(temp!=-1)
				m+=2;
		}

		//printf("index : %d\n",index );
		memset(bst,-1,sizeof bst);
		build(-1,0);


		//mdebug(bst,10,2);
		memset(sum,0,sizeof sum);
		preorder(0,100);
		


		printf("Case %d:\n",vez++);
		for(int i=0;i<200;i++)
		{
			if(sum[i]!=0)
				res.push_back(sum[i]);
		}

		for(int i=0;i<res.size();i++)
			(i==0)?printf("%d",res[i]):printf(" %d",res[i]);
		printf("\n\n");
		A.clear();
		B.clear();
	}
	return 0;
}
