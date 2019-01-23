#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int m[105][105];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            scanf("%d",&m[i][j]);
            if(j>0) m[i][j]=m[i][j]+m[i][j-1];
        }

    int maxsum = -127*100*100;
    for(int l=0;l<n;l++)
    {
        for(int r=l;r<n;r++)
        {
            int maxi=0;
            for(int row = 0;row<n;row++)
            {
                (l>0)?maxi+=m[row][r]-m[row][l-1]:maxi+=m[row][r];
                if(maxi<0)maxi=0;
                maxsum = max(maxsum,maxi);
            }
        }
    }
    printf("%d\n",maxsum);
    return 0;
}
