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

struct node{
    int a,b;
    string c;
    node(int _a,int _b,string _c)
    {
        a=_a,b=_b,c=_c;
    }
};
vector< node > arr;

bool func(double mid)
{
    double l=0,km=arr[0].a,f=arr[0].b,temp=mid;
    int t=arr.size();
    FOR(i,1,t)
    {
        mid-=((arr[i].a-km)*f)/100+(arr[i].a-km)*l;
        km=arr[i].a;
        if(mid<0.0)
            return false;
        if(arr[i].c=="Fuel")
            f=arr[i].b;
        else if(arr[i].c=="Leak")
            l++;
        else if(arr[i].c=="Mechanic")
            l=0;
        else if(arr[i].c=="Gas")
            mid=temp;
    }
    return true;
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n,c;
    string cad,cad1;
    while(cin>>n>>cad>>cad1>>c)
    {
        if(n==0&&cad=="Fuel"&&cad1=="consumption"&&c==0)
            break;
        arr.clear();
        arr.PB(node(0,c,cad));
        while(cin>>n>>cad)
        {
            if(cad=="Fuel")
            {
                cin>>cad1;
                cin>>c;
                arr.PB(node(n,c,cad));
            }
            if(cad=="Gas")
            {
                cin>>cad1;
                arr.PB(node(n,0,cad));
            }
            if(cad=="Mechanic")
            {
                arr.PB(node(n,0,cad));
            }
            if(cad=="Leak")
            {
                arr.PB(node(n,0,cad));
            }
            if(cad=="Goal")
            {
                arr.PB(node(n,0,cad));
                break;
            }
        }
            double ini=0.0,fin=1000000000.0;
            REP(i,50)
            {
                double mid=(ini+fin)/2;
                if(func(mid))
                    fin=mid;
                else
                    ini=mid;
            }
            printf("%.3lf\n",ini);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


