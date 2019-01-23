#include<stdio.h>
#include<vector>
#include<math.h>

using namespace std;

double p,q,r,s,t,u;

double f(double x)
{
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

double bisection( double ini ,double fin)
{
    double eps = 1e-9;
    while(fin-ini > eps)
            {
                double mid = (ini + fin)/2;
                if(f(ini) * f(mid)<=0)
                    fin = mid;
                else
                    ini = mid;
            }
    return (ini + fin)/2 ;
}
int main()
{

    while(~scanf("%lf %lf %lf %lf %lf %lf",&p,&q,&r,&s,&t,&u))
    {
        if(f(0)*f(1)>0)
            printf("No solution\n");
        else
        {
            double ini = 0.0,fin = 1.0;
            printf("%.4lf\n",bisection(ini,fin));
        }
    }


    return 0;
}
