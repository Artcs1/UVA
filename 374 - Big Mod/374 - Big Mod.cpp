#include<bits/stdc++.h>
using namespace std; 

#define lli long long int

lli b, p, m;

lli fastExp(lli b, lli p)
{
    if(p==0) return 1ll;
    else if(p==1) return b;
    else
    {
        lli res = fastExp(b, p/2);
        res= (res*res)%m;
        if(p%2==1)
            res= (res*b)%m;
        return res;
    }
}

int main()
{
    while(~scanf("%lld %lld %lld",&b,&p,&m))
    {
        printf("%lld\n",fastExp(b, p));
    }
    return 0;
}
