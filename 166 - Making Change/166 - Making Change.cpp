
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


int main()
{
/*
        freopen("input.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
*/

    int arr[]={5,10,20,50,100,200};
    int c1,c2,c3,c4,c5,c6;
    double change;
    while(~scanf("%d %d %d %d %d %d",&c1,&c2,&c3,&c4,&c5,&c6)&&(c1!=0||c2!=0||c3!=0||c4!=0||c5!=0||c6!=0))
    {
        scanf("%lf",&change);
        int val = (int)((change * 100)+ 1e-9 );
        VE coins;
        REP(i,c1)
            coins.PB(arr[0]);
        REP(i,c2)
            coins.PB(arr[1]);
        REP(i,c3)
            coins.PB(arr[2]);
        REP(i,c4)
            coins.PB(arr[3]);
        REP(i,c5)
            coins.PB(arr[4]);
        REP(i,c6)
            coins.PB(arr[5]);
        //debug(val);
        int M[1005];
        int M2[1005];
        for(int i=0;i<1000;i++)
            M[i]=inf_i,M2[i]= inf_i;
        M[0] = 0 ;
        M2[0] = 0 ;
        for(int i=0;i<(int)coins.size();i++)
            for(int j=1000;j>=0;j--)
                if(j - coins[i] >= 0&& M[ j - coins[i]] + 1< M[j])
                    M[j] = M[ j - coins[i]] + 1;


        for(int i=1;i<1000;i++)
            for(int j=0;j<6;j++)
                if( i - arr[j] >=0 && M2[i-arr[j]] + 1 < M2[i])
                    M2[i] = M2[i-arr[j]] + 1;

        int res = inf_i;
        FOR(i,val,1000)
        {
            if(M[i]!=inf_i && M2[i - val]!=inf_i  )
                res = min(res,M[i]+M2[i-val]);
        }

        printf("%3d\n",res);
    }

/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


