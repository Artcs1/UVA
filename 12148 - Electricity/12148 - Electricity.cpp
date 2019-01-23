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
#define inf_i (1<<31)-1
bool bis(int i)
{
    if((i%4==0&&i%100!=0)||i%400==0)
        return true;
    return false;
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    static int y[2200];
    mset(y,0);
    FOR(i,1900,2200)
        y[i]=365;
    int ma[]={0,31,28,31,30,31,30,31,31,30,31,30,31},md[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    FOR(i,1,13)
    {
        ma[i]+=ma[i-1];
        md[i]+=md[i-1];
    }

    FOR(i,1900,2200)
    {
        if(bis(i))
            y[i]++;
        y[i]+=y[i-1];
    }
    int n;
    while(scanf("%d",&n),n)
    {
        vector<ii>arr;
        REP(i,n)
        {
            int d,m,a,c;
            scanf("%d %d %d %d",&d,&m,&a,&c);
            int value=d+((bis(a))?md[m-1]:ma[m-1])+y[a-1];
            //debug(value);
            arr.PB(ii(value,c));
        }
        int v=0,r=0;
        REP(i,n-1)
        {
                if(arr[i].first+1==arr[i+1].first)
                {
                    v++;
                    r+=arr[i+1].second-arr[i].second;
                }
        }
        printf("%d %d\n",v,r);
    }

/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


