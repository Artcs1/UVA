
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

vector<int>ady[2000];
int M[2000][2000],p[2000],cap[2000],n,m,w,ini,fin,f;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};



void augment(int u,int minEdge)
{
    if(u==0){f = minEdge;return;}
    else if(p[u]!=-1)
    {
       /* debug(p[u]);
        debug(u);
        debug(M[p[u]][u]);*/
        augment(p[u],min(minEdge,M[p[u]][u]));
        ady[u].PB(p[u]);
        M[p[u]][u]-= f,  M[u][p[u]]+= f;
    }
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/

    string cad;
    while(~scanf("%d %d %d",&n,&m,&w))
    {
        mset(cap,0);
        ini = 0,fin = (n*m)+1;
        vector<string>arr;
        REP(i,n)
        {
            cin>>cad,arr.PB(cad);
            REP(j,cad.size())
            {
                if(arr[i][j] == '*')
                {
                    ady[0].PB((i*m)+j+1);
                    M[0][(i*m)+j+1] = 1;
                }
            }
        }

        REP(i,n)
            REP(j,m)
            {
                if(arr[i][j]!='~')
                {
                    cap[(i*m)+j+1] = fin +(i*m)+j+1;
                    ady[(i*m)+j+1].PB(cap[(i*m)+j+1]);
                    if(arr[i][j]=='*'||arr[i][j]=='.')
                        M[(i*m)+j+1][cap[(i*m)+j+1]] = 1;
                    else if(arr[i][j] == '#' || arr[i][j] == '@')
                        M[(i*m)+j+1][cap[(i*m)+j+1]] = inf_i;

                    REP(k,4)
                    {
                        int xx= i + dx[k];
                        int yy= j + dy[k];
                        if(xx>=0&&yy>=0&&xx<n&&yy<m)
                        {
                            if(arr[xx][yy]!='~')
                            {
                                ady[cap[(i*m)+j+1 ]].PB((xx*m)+yy+1 );
                                M[cap[(i*m)+j+1 ]][(xx*m)+yy+1 ]=inf_i;
                            }
                        }
                    }
                }
            }

        REP(i,n)
            REP(j,m)
                 if(arr[i][j] == '#')
                    {
                        ady[cap[i*m+j+1]].PB(fin);
                        M[cap[i*m+j+1]][fin] = w;
                    }

         int mf = 0;

         /*REP(i,30)
         {
             printf("%d ->",i);
             REP(j,ady[i].size())
             {
                 printf("%d ",ady[i][j]);
             }
             printf("\n");
         }
         debug(ini);
         debug(fin);*/
        while(true)
        {
            mset(p,-1);
            f = 0;

            queue<int>q;
            q.push(ini);
            VE dist(2005,inf_i);
            dist[ini] = 0;

            while(!q.empty())
            {
                int u = q.front();
                q.pop();

                if(u==fin) break;

                REP(i,ady[u].size())
                {
                    int v = ady[u][i];
                    if(M[u][v]>0&&dist[v]==inf_i)
                        dist[v] = dist[u]+1,p[v] = u , q.push(v);
                }
            }
            augment(fin,inf_i);
            if(f==0)break;
            mf+=f;
        }

        printf("%d\n",mf);

        REP(i,2005)
            ady[i].clear();

    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


