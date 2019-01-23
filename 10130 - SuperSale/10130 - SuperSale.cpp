#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>

using namespace std;

struct node{
    int p,w;
    node(int _p,int _w)
    {
        p=_p;
        w=_w;
    }
};


int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n,m;
        int W[1005],P[1005];
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d %d",&P[i],&W[i]);
        int matriz[1005][40];
        memset(matriz,0,sizeof matriz);
        for(int i=1;i<n+1;i++)
            for(int j=1;j<35;j++)
                if(j-W[i-1]>=0)
                    matriz[i][j] = max(matriz[i-1][j],P[i-1]+matriz[i-1][j-W[i-1]]);
                else
                    matriz[i][j] = matriz[i-1][j];

        int res = 0 ;
        scanf("%d",&m);
        for(int j=0;j<m;j++)
        {
            int w;
            scanf("%d",&w);
            res += matriz[n][w];
        }
        printf("%d\n",res);
    }

}
