
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
    int n,val;
    while(~scanf("%d",&n)&&n!=0)
    {
        string cad;
        cin.ignore();
        int M[50][50];
        lli I[50][50];
        mset(I,0);
        REP(i,50)
        {
            REP(j,50)
                M[i][j] = inf_i;
            M[i][i] = 0;
        }


        REP(i,n)
        {
            getline(cin,cad);
            istringstream iss(cad);
            while(iss>>val)
            {
                val--;
                M[i][val] = 1;
            }
        }

        REP(k,n)
            REP(i,n)
                REP(j,n)
                    M[i][j]= min(M[i][j],M[i][k]+M[k][j]);

        REP(i,n)
            REP(j,n)
                REP(k,n)
                    if(M[i][k]+M[k][j] == M[i][j])
                        I[i][j] |= (1ll<<k);


        lli comp = (1ll<<n);
        comp--;
        int q;
        scanf("%d",&q);
        cin.ignore();
        REP(i,q)
        {
            vector<int>arr;
            getline(cin,cad);
            //debug(cad);
            istringstream iss(cad);
            while(iss>>val)
            {
                val--;
                arr.PB(val);
            }


            lli nodo = 0;
            REP(i,arr.size())
                REP(j,arr.size())
                    nodo |= I[arr[i]][arr[j]];

            if(nodo == comp)
                printf("yes\n");
            else
                printf("no\n");
        }
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


