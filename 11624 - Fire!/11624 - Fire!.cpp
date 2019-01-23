
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

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        vector<string>arr;
        int n,m;
        string cad;
        arr.clear();
        scanf("%d %d",&n,&m);
        REP(i,n)
        {
            cin>>cad;
            arr.PB(cad);
        }

        queue<ii>q;
        REP(i,n)
            REP(j,m)
            {
                if(arr[i][j] == 'J')
                    q.push(ii(i,j));
            }
        REP(i,n)
            REP(j,m)
            {
                if(arr[i][j] == 'F')
                    q.push(ii(i,j));
            }
        bool band = false;
        int r = inf_i;
        static int matriz[1000][1000];
        mset(matriz,0);
        while(!q.empty())
        {
            ii p = q.front();
            q.pop();
            char c = arr[p.first][p.second];
            REP(i,4)
            {
                int xx= p.first+dx[i];
                int yy= p.second+dy[i];
                if(c=='F')
                {
                    if(xx>=0&&xx<n&&yy>=0&&yy<m&&(arr[xx][yy]=='.'||arr[xx][yy]=='J'))
                    {
                        q.push(ii(xx,yy));
                        arr[xx][yy] = 'F';
                    }
                }
                else if(c=='J')
                {
                    if(xx<0||xx>=n||yy<0||yy>=m)
                    {
                        r = min(r,matriz[p.first][p.second]+1);
                        band = true;
                    }
                    else if(xx>=0&&xx<n&&yy>=0&&yy<m&&arr[xx][yy]=='.')
                    {
                        matriz[xx][yy] = matriz[p.first][p.second]+1;
                        arr[xx][yy] = 'J';
                        q.push(ii(xx,yy));
                    }
                }
            }
        }
        (band)?printf("%d\n",r):printf("IMPOSSIBLE\n");
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


