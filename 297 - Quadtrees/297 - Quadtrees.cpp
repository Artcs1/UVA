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

int q1[1024],q2[1024],tam=0;
void backt(string c,int n,int ind,int v)
{
    REP(i,4)
    {
        if(c[tam]=='p')
            {tam++;backt(c,n/4,ind+n*i,v);}
        else if(c[tam]=='f')
        {
            int top=ind+n*i;
            FOR(j,top,top+n)
                (v==1)?q1[j]=0:q2[j]=0;
            tam++;
        }
        else
            tam++;
    }
    return;
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n;
    scanf("%d",&n);
    while(n--)
    {
        REP(i,1024)
            q1[i]=1,q2[i]=1;
        string cad,cad1;
        cin>>cad;
        cin>>cad1;
        tam=0;
        backt(cad,1024,0,1);
        tam=0;
        backt(cad1,1024,0,2);
        int res=0;
        REP(i,1024)
            if(!(q1[i]&q2[i])) res++;
        printf("There are %d black pixels.\n",res);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


