
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
#define inf_i (1<<31)-1

int power(int a,int b)
{
    int r=1;
    REP(i,b)
        r*=a;
    return r;
}

int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n;
    while(~scanf("%d",&n))
    {
        vector<string>arr;
        int iterations = power(10,(n/2));
        REP(i,iterations)
            REP(j,iterations)
            {
                if(cua(i+j)==i*iterations+j)
                {
                    int x=i,y=j;
                    string temp="";
                    REP(k,n/2)
                        temp=char('0'+(y%10))+temp,y/=10;
                    REP(k,n/2)
                        temp=char('0'+(x%10))+temp,x/=10;

                    arr.PB(temp);
                }
            }

        REP(i,arr.size())
            printf("%s\n",arr[i].c_str());
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


