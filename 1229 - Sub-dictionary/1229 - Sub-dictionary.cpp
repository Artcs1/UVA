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

int DFS_WHITE=0,numSCC;
map<int,int>mymap3;
vector<int>ady[3005],ady2[3005],ady3[3005],S,dfs_num;
vector<int>kosa[3005];
void Kosaraju(int u, int pass) { // pass = 1 (original), 2 (transpose)
    kosa[numSCC].PB(u);
    mymap3[u]=numSCC;
    dfs_num[u] = 1;
    VE neighbor; // use different Adjacency List in the two passes
    if (pass == 1) neighbor = ady[u];
    else if(pass==2)neighbor = ady2[u];
    else if(pass==3) neighbor = ady3[u];
    for (int j = 0; j < (int)neighbor.size(); j++) {
        int v = neighbor[j];
        if (dfs_num[v] == DFS_WHITE)
            Kosaraju(v, pass);
    }
    S.push_back(u); // as in finding topological order in Section 4.2.5
}

int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n;
    while(~scanf("%d",&n),n)
    {
        set<string>res;
        REP(i,3005)
            ady[i].clear(),ady2[i].clear(),ady3[i].clear(),kosa[i].clear();
        map<string,int>mymap;
        map<int,string>mymap2;
        mymap3.clear();
        int index=0;
        string cad;
        cin.ignore();
        REP(i,n)
        {
            getline(cin,cad);
            istringstream iss(cad);
            string cad1,cad2;
            iss>>cad1;
            if(mymap.count(cad1)<=0)
            {
                mymap2[index]=cad1;
                mymap[cad1]=index++;
            }
            while(iss>>cad2)
            {
                if(mymap.count(cad2)<=0)
                {
                    mymap2[index]=cad2;
                    mymap[cad2]=index++;
                }
                ady[mymap[cad1]].PB(mymap[cad2]);
                ady2[mymap[cad2]].PB(mymap[cad1]);
            }
        }
        numSCC=0;
        S.clear(); // first pass is to record the ‘post-order’ of original graph
        dfs_num.assign(n, DFS_WHITE);
        for (int i = 0; i < n; i++)
            if (dfs_num[i] == DFS_WHITE)
                Kosaraju(i, 1);
        REP(i,3005)
            kosa[i].clear();
        numSCC = 0; // second pass: explore the SCCs based on first pass result
        dfs_num.assign(n, DFS_WHITE);
        int men=inf_i;
        VE scc;
        for (int i = n - 1; i >= 0; i--)
            if (dfs_num[S[i]] == DFS_WHITE) {
                Kosaraju(S[i], 2);
                if(kosa[numSCC].size()>=2)
                    scc.PB(numSCC);
                numSCC++;
            }
        REP(i,n)
            REP(j,ady[i].size())
            {
                int u=mymap3[i],v=mymap3[ady[i][j]];
                if(u!=v)
                    ady3[u].PB(v);
            }
        int tam=scc.size();
        dfs_num.assign(n, DFS_WHITE);
        REP(i,tam)
            Kosaraju(scc[i],3);
        REP(i,n)
            if(dfs_num[i]==1)
                REP(j,kosa[i].size())
                    res.insert(mymap2[kosa[i][j]]);
        int cont=0;
        printf("%d\n",res.size());
        for( set <string> ::iterator it=res.begin();it!=res.end();it++)
        {
            cont++;
            (cont==(int)res.size())?cout<<*it<<endl:cout<<*it<<" ";
        }
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}
