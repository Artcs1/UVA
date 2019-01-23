#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int n,temp;
    scanf("%d\n",&n);

    for(int i=0;i<n;i++)
    {
        vector<int>arr;
        arr.push_back(-1);
        int r;
        scanf("%d\n",&r);
        int s = 0;
        for(int j=0;j<r-1;j++)
        {
            scanf("%d",&temp);
            s+= temp;
            if(s<0)
            {
                s = 0;
                arr.push_back(-1);
            }
            else
                arr.push_back(s);
        }
        int maxi = 0;
        int indmin = 0,indmax = 0,imin,imax;
        for(int j=0;j<r;j++)
        {
            if(arr[j]==-1)
                imin = j;
            else
            {
                imax = j;
                if(maxi < arr[j] || (maxi == arr[j] && imax - imin > indmax - indmin ))
                {
                    maxi = max(maxi,arr[j]);
                    indmin = imin;
                    indmax = imax;
                }
            }
        }
        if(indmin == indmax)
            printf("Route %d has no nice parts\n",i+1);
        else
            printf("The nicest part of route %d is between stops %d and %d\n",i+1,indmin+1,indmax+1);
    }
    return 0;
}
