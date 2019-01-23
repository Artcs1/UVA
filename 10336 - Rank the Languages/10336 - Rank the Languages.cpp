
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

int r,c;
vector<string>arr;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void floodfill(int x,int y,char C)
{
    arr[x][y]='.';
    REP(i,4)
    {
        int xx= x+dx[i];
        int yy= y+dy[i];
        if(xx>=0&&xx<r&&yy>=0&&yy<c&&arr[xx][yy]==C)
            floodfill(xx,yy,C);
    }
}

bool cmp(ii p1,ii p2)
{
    if(p1.second==p2.second)
        return p1.first<p2.first;
    return p1.second>p2.second;
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    int n;
    scanf("%d",&n);
    string cad;
    REP(i,n)
    {
        printf("World #%d\n",i+1);
        scanf("%d %d",&r,&c);
        REP(j,r)
        {
            cin>>cad;
            arr.PB(cad);
        }
        int freq[30];
        mset(freq,0);
        REP(j,r)
            REP(k,c)
                {
                    if(arr[j][k]!='.')
                    {
                        freq[arr[j][k]-'a']++;
                        floodfill(j,k,arr[j][k]);
                    }
                }
        vector<ii > res;
        REP(i,30)
            if(freq[i]!=0)
                res.PB( ii(i,freq[i]));

        sort(all(res),cmp);
        REP(i,res.size())
            printf("%c: %d\n",res[i].first+'a',res[i].second);
        REP(j,r)
            arr.clear();
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}




