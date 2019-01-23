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

static int M[100005][20];
VE arr,A;

void process()
{
    int tam=A.size();
    memset(M,-1,sizeof M);
    for(int i=0;i<tam;i++)
        M[i][0]=A[i];
    for(int j=1;(1<<j)<=tam;j++)
        for(int i=0;i+(1<<j)<=tam;i++)
            M[i][j]=max(M[i][j-1],M[i+(1<<(j-1))][j-1]);
}
int query(int i,int j)
{
    int k = (int)floor(log((double)j-i+1) / log(2.0));
    return max(M[i][k],M[j-(1<<k)+1][k]);
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    //debug(__builtin_clz(0));
    int der[100005],izq[100005];
    int n,q;
    while(scanf("%d",&n),n)
    {
        int temp,_temp,c=0,cont=0;
        A.clear();
        arr.clear();
        VE mapeo;
        scanf("%d",&q);
        REP(i,n)
        {
            scanf("%d",&temp);
            arr.PB(temp);
            if(i>=1&&temp!=_temp)
            {
                A.PB(c);
                c=0;
                if(i!=n-1)
                    cont++;
            }
            mapeo.PB(cont);
            c++;
            _temp=temp;
        }
        A.PB(c);
        mset(izq,-1);
        REP(i,100005)
            der[i]=n;
        FOR(i,1,n)
        {
            if(arr[i]!=arr[i-1])
            {
                int j=i-1;
                while(arr[j]==arr[i-1]&&j>=0)
                {
                    der[j]=i;
                    j--;
                }
            }
        }
        RFOR(i,n-1,0)
        {
            if(arr[i]!=arr[i+1])
            {
                int j=i+1;
                while(arr[j]==arr[i+1]&&j<n)
                {
                    izq[j]=i;
                    j++;
                }
            }
        }
        process();
        int _u,_v;
        REP(i,q)
        {
            scanf("%d %d",&_u,&_v);
            int l=max(_u-2,izq[_v-1]),r=min(_v,der[_u-1]),res=0;
            //debug(l);
            //debug(r);
            res=max(res,max(abs((_u-1)-r),abs((_v-1)-l)));
            //debug(res);
            if(der[_u-1]<=izq[_v-1])
            {
                int l2=der[_u-1],r2=izq[_v-1];
                //debug(l2);
                //debug(r2);
                res=max(res,query(mapeo[l2],mapeo[r2]));
                //debug(query(mapeo[l2],mapeo[r2]));
            }
            printf("%d\n",res);
        }
    }
    //adebug(A,A.size());
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


