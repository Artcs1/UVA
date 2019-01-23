
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

int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n,q,t,vez = 1;
    while(~scanf("%d",&n)&&n!=0)
    {
        string cad,cad1;
        bool M[406][406];
        map<string , int > mymap;
        map<int , string > mymap2;

        mset(M,false);
        REP(i,406)
            M[i][i] = true;


        int index = 0,ant;
        REP(i,n)
        {
            scanf("%d",&t);
            ant = -1;
            REP(j,t)
            {
                cin>>cad;
                if(mymap.count(cad)<=0)
                    mymap[cad] = index++,mymap2[index-1] = cad;
                if(ant!=-1)
                    M[ant][mymap[cad]] = true;
                ant = mymap[cad];
            }
        }

        scanf("%d",&q);
        while(q--)
        {
            cin>>cad>>cad1;
            M[mymap[cad]][mymap[cad1]] = true;
        }

        n = index;
        REP(k,n)
            REP(i,n)
                REP(j,n)
                    M[i][j] |= (M[i][k]&M[k][j]);
        vector<ii >A;
        int c= 0;
        REP(i,n)
            FOR(j,i+1,n)
                if(M[i][j]!=true&&M[j][i]!=true)
                {
                    if(c<2)
                        A.PB(ii(i,j));
                    c++;
                }

        if(c==0)
            printf("Case %d, no concurrent events.\n",vez++);
        else
        {
            printf("Case %d, %d concurrent events:\n",vez++,c);
            REP(i,A.size())
                (i == (int)(A.size()-1))?printf("(%s,%s) \n",mymap2[A[i].first].c_str(),mymap2[A[i].second].c_str()):printf("(%s,%s) ",mymap2[A[i].first].c_str(),mymap2[A[i].second].c_str());

        }
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


