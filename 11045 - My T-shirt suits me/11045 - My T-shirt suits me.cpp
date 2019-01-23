
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

vector<int>ady[75];
int M[75][75];
int p[75];

int augmentpath(int u,int minEdge)
{
    int mini = inf_i;
    if( u == 0)
    {
        mini = minEdge;
        return mini;
    }
    else
    {
        mini = min(mini,augmentpath(p[u],min(M[p[u]][u],minEdge)));
        ady[u].PB(p[u]);
        M[p[u]][u] -= mini;
        M[u][p[u]] += mini;
    }
    return mini;
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    map<string ,int > mymap;
    mymap["XS"]= 1;
    mymap["S"]= 2;
    mymap["M"]= 3;
    mymap["L"]= 4;
    mymap["XL"]= 5;
    mymap["XXL"]= 6;

    string cad,cad1;
    int cases;

    scanf("%d",&cases);
    while(cases--)
    {
        REP(i,70)
            REP(j,70)
                M[i][j] = 0;
        int n,s;
        scanf("%d %d",&n,&s);
        int index = 7,div = n/6;

        REP(i,6)
            ady[0].PB(i+1),M[0][i+1] = div;

        FOR(i,index,index+s)
        {
            //debug(i);
            cin>>cad>>cad1;
            ady[mymap[cad]].PB(i);
            M[mymap[cad]][i] = 1;

            ady[mymap[cad1]].PB(i);
            M[mymap[cad1]][i] = 1;

            ady[i].PB(index+s);
            M[i][index+s] = 1;
        }
        int f = 0,ini = 0,fin = 6+s+1;
        //debug(fin);
        bool band =true;
        while(band)
        {
            mset(p,-1);
            queue<int>q;
            q.push(ini);
            band = false;
            VE dist(75,inf_i);
            dist[ini] = 0;
            while(!q.empty())
            {
                int u = q.front();
                q.pop();

                if(u == fin)
                {
                    f+=augmentpath(fin,inf_i);
                    band = true;
                    //debug("acabo");
                    break;
                }
                REP(i,ady[u].size())
                {
                    int v = ady[u][i];
                    if(M[u][v] >0 && dist[v] == inf_i)
                        dist[v] = dist[u] + 1,p[v] = u,q.push(v);
                }
            }
        }
        //debug(f);
        (f == s)?printf("YES\n"):printf("NO\n");
        REP(i,70)
            ady[i].clear();
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


