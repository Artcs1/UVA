#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b){return  (b==0)?a:gcd(b,a%b); }
int main()
{
    int n,a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        printf("Case %d: %d\n",i+1,(a+b)/gcd(a,b));
    }
    return 0;

}
