
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

int tonum(string cad)
{
    int t=cad.size();
    int m =1;
    int s=0;
    RFOR(i,t-1,0)
    {
        s= s+ (cad[i]-'0')*m;
        m*=10;
    }
    return s;
}

int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/

int cases;
scanf("%d",&cases);
string cad1;
getline(cin,cad1);
cin.ignore();
REP(k,cases)
{
    string cad;
    VE arr;
    int n=0;
    while(getline(cin,cad))
    {
        if(cad.size()==0)
            break;
        arr.PB(tonum(cad));
        n++;
    }
    int lis[n+5];
    VE A,B;
    vector<int>::iterator it;
    int maxi =0 ;
    REP(i,n)
    {
        int val = arr[i];
        it = lower_bound(all(A),val);
        int i1=it-A.begin();
        if(it == A.end())
            A.PB(val);
        else
        {
            A.erase(it);
            A.insert(it,val);
        }
        lis[i] = i1+1;
    }
    int tam = A.size();

    if(k)
        printf("\n");
    printf("Max hits: %d\n",tam);
    VE res;
    RFOR(i,n-1,0)
    {
        if(lis[i]==tam)
            res.PB(arr[i]),tam--;
    }
    RFOR(i,res.size()-1,0)
    {
        printf("%d\n",res[i]);
    }
}
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


