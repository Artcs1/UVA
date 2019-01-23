

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

vector<int>ady[105];
int M[105][105],p[105],weight,ini=0,fin=37,f,total;

void augment(int u,int minEdge)
{
    if(u==ini){f=minEdge;return;}
    else if(p[u]!=-1)
    {
        augment(p[u],min(minEdge,M[p[u]][u]));
        ady[u].PB(p[u]);
        M[u][p[u]]+=f,M[p[u]][u]-=f;
    }
}

int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    map<string , int > mymap;
    FOR(i,1,27)
    {
        string t= "";
        char c = (char)('A'+(i-1));
        t+=c;
        mymap[t] = i;
    }
    string cad;
    while(getline(cin,cad))
    {
        mset(M,0);
        FOR(i,27,37)
        {
            ady[i].PB(37);
            M[i][37] = 1;
        }

        total = 0;
        string s;
        s=cad;
        do{

            string t = "";
            char a = s[0],b=s[1];
            t+=a,weight = b -'0';

            total+=weight;
            ady[0].PB(mymap[t]);
            M[0][mymap[t]] = weight;

            string r = s.substr(3,s.size()-1);

            REP(i,r.size()-1)
            {
                int val = 27 +(r[i]-'0');
                ady[mymap[t]].PB(val);
                M[mymap[t]][val] = 1;
            }
            getline(cin,s);

        }while(!s.empty());

        int mf = 0;
        while(true)
        {
            f=0;
            queue<int>q;
            mset(p,-1);
            VE dist(105,inf_i);
            dist[ini] = 0;
            q.push(ini);
            while(!q.empty())
            {
                int u = q.front();
                q.pop();

                if(u==fin) break;

                REP(i,ady[u].size())
                {
                    int v = ady[u][i];
                    if(M[u][v]>0 && dist[v]==inf_i)
                        dist[v]=dist[u]+1,p[v]=u,q.push(v);
                }
            }
            augment(fin,inf_i);
            if(f==0) break;
            mf+=f;
        }
        if(mf==total)
        {
            FOR(i,27,37)
            {
                bool band = true;
                FOR(j,1,27)
                {
                    //debug(i);
                    //debug(j);
                    if(M[i][j]==1)
                    {
                        printf("%c",(char)((j-1)+'A'));
                        band = false;
                        break;
                    }
                }
                if(band)
                    printf("_");
            }
            printf("\n");
        }
        else
        {
            printf("!\n");
        }
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}

