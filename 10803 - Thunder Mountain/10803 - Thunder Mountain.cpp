#include<stdio.h>
#include<vector>
#include<math.h>

using namespace std;


#define inf_i (1<<30)-1

int main()
{

    int cases;
    scanf("%d",&cases);
    for(int x=0;x<cases;x++)
    {
        int n;
        double u,v;
        scanf("%d",&n);
        vector< pair<double,double > > arr;
        for(int j=0;j<n;j++)
        {
            scanf("%lf %lf",&u,&v);
            arr.push_back(pair<double,double> (u,v));
        }
        double matriz[n][n];
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                matriz[j][k] = inf_i;
        for(int j=0;j<n;j++)
            for(int k=j;k<n;k++)
            {
                double w = hypotl(arr[j].first-arr[k].first,arr[j].second-arr[k].second);
                if(j == k)
                {
                    matriz[j][k] = 0.0;
                    matriz[k][j] = 0.0;
                }
                else
                {
                    matriz[j][k] = w;
                    matriz[k][j] = w;
                }
                if(matriz[j][k] > 10.0) matriz[j][k] = inf_i,matriz[k][j] = inf_i;
            }
        for(int k=0 ; k < n ; k++)
            for(int i =0 ; i< n; i++)
                for(int j =0; j< n; j++)
                        matriz[i][j] = min(matriz[i][j],matriz[i][k] + matriz[k][j]);

        double maxi=0.0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                maxi = max(maxi,matriz[i][j]);

        printf("Case #%d:\n",x +1);
        if(maxi == inf_i)
            printf("Send Kurdy\n\n");
        else
            printf("%.4lf\n\n",maxi);
    }


    return 0;
}
