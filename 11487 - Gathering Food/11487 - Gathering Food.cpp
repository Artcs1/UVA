
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

int n,maxi;
vector<string >arr;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

bool inside(int x,int y)
{
    if(x>=0 && y>=0 &&x<n && y <n)
        return true;
    return false;
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    string cad;
    int vez = 1 ;
    while(~scanf("%d",&n)&&n!=0)
    {
        int X[30];
        int Y[30];
        arr.clear();
        int x,y;
        maxi = 'A';
        REP(i,n)
        {
            cin>>cad;
            arr.PB(cad);
            REP(j,n)
            {
                if(arr[i][j]!='.'&&arr[i][j]!='#')
                {
                    maxi = max(maxi,(int)arr[i][j]);
                    X[arr[i][j]-'A'] = i;
                    Y[arr[i][j]-'A'] = j;
                }
            }
        }

        printf("Case %d: ",vez++);
        int top = maxi - 'A';
        int dist[20][20],path[20][20];
        int tempx = 1,tempy = 0;
        path[X[0]][Y[0]] = tempx;
        dist[X[0]][Y[0]] = tempy;
        bool band = true;
        REP(i,top)
        {
            mset(dist,0);
            mset(path,0);
            path[X[i]][Y[i]] = tempx;
            dist[X[i]][Y[i]] = tempy;
            queue< ii > q;
            q.push(ii(X[i],Y[i]));
            arr[X[i]][Y[i]] = '.';
            while(!q.empty())
            {
                x = q.front().first;
                y = q.front().second;
                q.pop();
                REP(j,4)
                {
                    int xx = x+dx[j];
                    int yy = y+dy[j];
                    if(inside(xx,yy)&&(arr[xx][yy]=='.'||arr[xx][yy]==char(i+'A'+1)))
                    {
                        if(dist[xx][yy] == 0)
                        {
                            dist[xx][yy] = dist[x][y] + 1;
                            q.push(ii(xx,yy));
                        }
                        if(dist[xx][yy] == dist[x][y] +1)
                        {
                            path[xx][yy]+= path[x][y];
                            path[xx][yy]%=20437;
                        }
                    }
                }
            }
            if(dist[X[i+1]][Y[i+1]]==0)
            {
                puts("Impossible");
                band = false;
                break;
            }
            tempy = dist[X[i+1]][Y[i+1]];
            tempx = path[X[i+1]][Y[i+1]];
        }
        if(band )
            printf("%d %d\n",dist[X[top]][Y[top]],path[X[top]][Y[top]]);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


