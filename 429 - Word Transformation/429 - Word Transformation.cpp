
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

vector<int>ady[205];
int recorrido[205];

bool form(string a,string b)
{
    if(a.size()!=b.size())
        return false;
    else
    {
        int c =0;
        REP(i,a.size())
        {
            if(a[i]!=b[i])
                c++;
        }
        if(c==1)
            return true;
        else
            return false;
    }
}

void bfs(int u)
{
    queue<int>q;
    q.push(u);
    recorrido[u]=0;
    while(!q.empty())
    {
        int u2 = q.front();
        q.pop();
        REP(i,ady[u2].size())
        {
            int v = ady[u2][i];
            if(recorrido[v] == -1)
            {
                recorrido[v]= recorrido[u2]+1;
                q.push(v);
            }
        }
    }
}

int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/

    map< string , int >mymap;
    int cases;
    scanf("%d",&cases);
    REP(k,cases)
    {
        if(k)
            printf("\n");
        string cad;
        vector<string>arr;
        int index = 0;
        while(cin>>cad)
        {
            if(cad[0]=='*')
                break;
            arr.PB(cad);
            mymap[cad]=index++;
        }
        REP(i,arr.size())
            FOR(j,i+1,arr.size())
                {
                    if(form(arr[i],arr[j]))
                    {
                        ady[i].PB(j);
                        ady[j].PB(i);
                    }
                }
        cin.ignore();
        while(getline(cin,cad)&&cad!="")
        {
            string A,B;
            bool band = true;
            REP(i,cad.size())
            {
                if(cad[i]==' ')
                    band = false;
                else if(band == true)
                    A+=cad[i];
                else if(band == false)
                    B+=cad[i];
            }
            mset(recorrido,-1);
            bfs(mymap[A]);
            printf("%s %s %d\n",A.c_str(),B.c_str(),recorrido[mymap[B]]);
         }
         REP(i,index)
            ady[i].clear();
    }

/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


