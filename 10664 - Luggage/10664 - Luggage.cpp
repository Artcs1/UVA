
//AUTOR:MURRUGARRA JEFFRI ERWIN
//UNIVERSIDAD: UNIVERSIDAD NACIONAL DE TRUJILLO
#include <bits/stdc++.h>

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

VE arr;

int memo[25][205],n1;
int DP(int idx,int Rest)
{
	if(Rest==0 || idx==n1)
		return 0;
	if(memo[idx][Rest]!=-1)
		return memo[idx][Rest];
    int val = -inf_i;
	if(Rest<arr[idx])
		val = max(val,DP(idx+1,Rest));
	if(Rest>=arr[idx])
		val = max(val,max(DP(idx+1,Rest),arr[idx]+DP(idx+1,Rest-arr[idx])));
    return memo[idx][Rest] = val;
}

int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n,value;
    scanf("%d",&n);
    cin.ignore();
    while(n--)
    {
        arr.clear();
        string cad;
        getline(cin,cad);
        istringstream iss(cad);
        int s = 0 ;
        while(iss>>value)
        {
            arr.PB(value);
            s+=value;
        }
        if(s&1)
            printf("NO\n");
        else
        {
            int S = s/2;
            n1 = arr.size();
            mset(memo,-1);
            if(S == DP(0,S))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


