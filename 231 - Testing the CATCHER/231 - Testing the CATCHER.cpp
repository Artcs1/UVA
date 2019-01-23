#include<stdio.h>
#include<vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int>arr;
    int n;
    int vez = 0;
    while(scanf("%d",&n))
    {
        if(n==-1)
        {
            if(arr.size()==0)
                break;
            else
            {
                vector<int>lis;
                vector<int>::iterator it;
                int tam = arr.size();
                for(int i=0;i<tam;i++)
                {
                    it = upper_bound(lis.begin(),lis.end(),arr[i]);
                    if(it == lis.end())
                        lis.push_back(arr[i]);
                    else
                    {
                        lis.erase(it);
                        lis.insert(it,arr[i]);
                    }
                }
                if(vez)
                    printf("\n");
                printf("Test #%d:\n",vez+1);
                printf("  maximum possible interceptions: %d\n",lis.size());

                vez++;
            }

            arr.clear();
        }
        else
        arr.push_back(-n);
    }
    return 0;
}
