#include<bits/stdc++.h>

using namespace std;

int main()
{
    int NCOWS,NCARS,NSHOW;
    while(~scanf("%d %d %d",&NCOWS,&NCARS,&NSHOW))
    {
        double I1 = (NCOWS/((NCOWS+NCARS)*1.0))*(NCARS/((NCOWS+NCARS-NSHOW-1)*1.0));
        double I2 = (NCARS/((NCOWS+NCARS)*1.0))*((NCARS-1)/((NCOWS+NCARS-NSHOW-1)*1.0));
        printf("%.5lf\n",I1+I2);
    }
    return 0;

}
