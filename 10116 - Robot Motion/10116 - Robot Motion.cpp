
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

int r,c,c1;

bool inside(int x,int y)
{
    if(x<r&&x>=0&&y<c&&y>=0)
        return true;
    return false;
}

int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/

    while(~scanf("%d %d %d",&r,&c,&c1)&&(r!=0||c!=0||c1!=0))
    {
        vector<string>M;
        int vis[15][15];
        int cnt[15][15];
        mset(vis,0);
        mset(cnt,0);
        REP(i,r)
        {
            string cad;
            cin>>cad;
            M.PB(cad);
        }
        int x = 0 , y = c1-1;
        int cont = 0;
        while(vis[x][y]==0&&inside(x,y))
        {
            cont++;
            cnt[x][y]= cont;
            vis[x][y]=1;
            if(M[x][y]=='N')
                x--;
            else if(M[x][y]=='S')
                x++;
            else if(M[x][y]=='E')
                y++;
            else if(M[x][y]=='W')
                y--;
        }
        if(!inside(x,y))
            printf("%d step(s) to exit\n",cont);
        else
            printf("%d step(s) before a loop of %d step(s)\n",cnt[x][y]-1,cont-cnt[x][y]+1);
    }

/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


