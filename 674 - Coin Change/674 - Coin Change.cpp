#include<stdio.h>
#include<string.h>

using namespace std;

int arr[]={1,5,10,25,50},t = 5;

static int memo[10][10000];

int dp(int i,int change)
{
    if(change == 0 )
        return 1;
     if(i == t||change<0)
        return 0;
    if(memo[i][change]!=-1)
        return memo[i][change];
    return memo[i][change] = dp(i+1, change) + dp(i,change - arr[i]);
}

int main()
{
    int n;
    memset(memo,-1,sizeof memo);
    dp(0,10000);
    while(~scanf("%d",&n))
    {
        printf("%d\n",memo[0][n]);
    }
    return 0;
}
