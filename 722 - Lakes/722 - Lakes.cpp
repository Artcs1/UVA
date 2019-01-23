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

vector<string>arr;
string cad;
int tx,ty,cont;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void floodfill(int x,int y)
{
    cont++;
    arr[x][y]='?';
    REP(i,4)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>=0&&xx<tx&&yy>=0&&yy<ty&&arr[xx][yy]=='0')
            floodfill(xx,yy);
    }
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
int n;
scanf("%d",&n);
while(n--)
{
    arr.clear();
    int i,j;
    scanf("%d %d",&i,&j);

    cin.ignore();
    while(getline(cin,cad))
    {
        if(cad.size()==0)
            break;
        arr.PB(cad);
    }
    tx=arr.size();
    ty=arr[0].size();
    cont=0;
    if(arr[i-1][j-1]=='0') floodfill(i-1,j-1);

    printf("%d\n",cont);
    if(n)
        printf("\n");
}
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


