#include<bits/stdc++.h>

using namespace std;

int main()
{
    static int dp[305][10005],pai[305][10005];
    int c,ferry;
    scanf("%d",&c);
    //printf("%d\n",c);
    while(c--)
    {
        int A[2005],S[2005];
        S[0] = 0;
        scanf("%d",&ferry);
        ferry*=100;
        int n =1 ;
        while(scanf("%d",&A[n]),A[n])
        {
            S[n] = A[n]+S[n-1] ;
            n++;
        }
        //for(int i =0;i<(int)A.size();i++)
        //    cout<<S[i]<<endl;
        memset(dp,0,sizeof dp);
        dp[0][0] = 1;
        int mx_car = 0,mx_len;
        int i,j;
        n--;
        for(i=1;i<=n;i++)
        {
            for(j =0;j<=ferry;j++)
            {
               if(j-A[i] >= 0 && dp[i-1][j-A[i]]) {
                    dp[i][j] = 1;
                    pai[i][j] = 0;
                }
                if(S[i]-j <= ferry && dp[i-1][j]) {
                    dp[i][j] = 1;
                    pai[i][j] = 1;
                }
                if(dp[i][j])
                    mx_car = i, mx_len = j;
            }
            if(mx_car != i)
                break;   
        }
        
        printf("%d\n", mx_car);
        int where[305];
        i = mx_car, j = mx_len;
        while(i) {
            where[i] = pai[i][j];
            if(!pai[i][j])
                j -= A[i];
            i--;
        }
        for(i = 1; i <= mx_car; i++)
            printf((where[i] ? "starboard\n" : "port\n"));
        if(c)
            printf("\n");
    }
    return 0;
}
