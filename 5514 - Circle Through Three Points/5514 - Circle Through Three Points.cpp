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


double det(vector<double>dete[])
{
    double pos=dete[0][0]*dete[1][1]*dete[2][2]+dete[1][0]*dete[2][1]*dete[0][2]+dete[2][0]*dete[0][1]*dete[1][2];
    double neg=dete[2][0]*dete[1][1]*dete[0][2]+dete[1][0]*dete[0][1]*dete[2][2]+dete[0][0]*dete[2][1]*dete[1][2];
    return pos -neg;
}
int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/

    double x1,y1,x2,y2,x3,y3;
    while(~scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3))
    {
        vector<double>dis[3],d[3],e[3],f[3];
        dis[0].PB(x1),dis[0].PB(y1),dis[0].PB(1),dis[1].PB(x2),dis[1].PB(y2),dis[1].PB(1),dis[2].PB(x3),dis[2].PB(y3),dis[2].PB(1);
        //mdebug(dis,3,3);
        REP(i,3)
            d[i]=e[i]=f[i]=dis[i];
        double res1=-(cua(x1)+cua(y1)),res2=-(cua(x2)+cua(y2)),res3=-(cua(x3)+cua(y3));
        d[0][0]=e[0][1]=f[0][2]=res1;
        d[1][0]=e[1][1]=f[1][2]=res2;
        d[2][0]=e[2][1]=f[2][2]=res3;
        //mdebug(d,3,3);
        //mdebug(e,3,3);
        //mdebug(f,3,3);
        double det1=det(dis),D=det(d)/det1,E=det(e)/det1,F=det(f)/det1;
        double cx=-(D/2),cy=-(E/2.0),r=sqrt(cua(D)+cua(E)-4*F)/2.0;
        double h=D/2.0,k=E/2.0;
            printf("(x ");
            printf(" %.3lf)^2 +",abs(h),(h<0)?printf("-"):printf("+"));

            printf(" (y ");
            printf(" %.3lf)^2 = ",abs(k),(k<0)?printf("-"):printf("+"));
        printf("%.3lf^2\n",r);

        printf("x^2 + y^2 ");

        printf(" %.3lfx ",abs(D),(D<0)?printf("-"):printf("+"));
        printf(" %.3lfy ",abs(E),(E<0)?printf("-"):printf("+"));
        printf(" %.3lf ",abs(F),(F<0)?printf("-"):printf("+"));
        printf("= 0\n");
        printf("\n");

    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


