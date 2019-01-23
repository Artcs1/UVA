
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


string cad;
int n;
lli r;
lli memo[20][20];
map<char,int>mymap;

lli queen(int row,int column)
{
    if(row == n-1)
        return memo[row][column] = 1;

    if(memo[row][column]!=-1)
        return memo[row][column];


    lli r = 0;
    if(cad[row+1] == '?')
    {
        REP(i,n)
            if(abs((i+1)-column)>=2)
                r = r + queen(row+1,i+1);
    }
    else if(abs(mymap[cad[row+1]]-column)  >=2)
        r = r + queen(row+1, mymap[cad[row+1]]);
    return memo[row][column] = r;
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/

    mymap['1'] = 1,mymap['2'] = 2,mymap['3'] = 3,mymap['4'] = 4,mymap['5'] = 5,mymap['6'] = 6,mymap['7'] = 7;
    mymap['8'] = 8,mymap['9'] = 9,mymap['A'] = 10,mymap['B'] = 11,mymap['C'] = 12,mymap['D'] = 13;
    mymap['E'] = 14,mymap['F'] = 15;

    while(cin>>cad)
    {
        n = cad.size();
        r = 0;
        mset(memo,-1);
        if(cad[0] == '?')
            REP(i,n)
                r = r + queen(0,i+1);
        else
            r = r + queen(0,mymap[cad[0]]);
        printf("%lld\n",r);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


