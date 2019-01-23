
//AUTOR:MURRUGARRA JEFFRI ERWIN
//UNIVERSIDAD: UNIVERSIDAD NACIONAL DE TRUJILLO
#include <bits/stdc++.h>


using namespace std;

int n;

bool inside(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<n)
        return true;
    return false;
}
bool rook(int x,int y, vector<string> M)
{
    int xx=x+1,yy=y;
    while(inside(xx,yy)&&M[xx][yy]!='X')
    {
        if(M[xx][yy]=='1')
            return false;
        xx++;
    }
    xx=x-1,yy=y;
    while(inside(xx,yy)&&M[xx][yy]!='X')
    {
        if(M[xx][yy]=='1')
            return false;
        xx--;
    }
    xx=x,yy=y+1;
    while(inside(xx,yy)&&M[xx][yy]!='X')
    {
        if(M[xx][yy]=='1')
            return false;
        yy++;
    }
    xx=x,yy=y-1;
    while(inside(xx,yy)&&M[xx][yy]!='X')
    {
        if(M[xx][yy]=='1')
            return false;
        yy--;
    }
    return true;
}

bool valid(vector<string>M)
{
    bool band = true;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(M[i][j]=='1')
                band&= rook(i,j,M);
        }
    return band;
}

bool Solve(vector<string>M,vector<int>pos)
{
    bool flag=true;
    //printf("%d\n",pos.size());
    for(int i=0;i<pos.size();i++)
    {
        int x = pos[i]/n;
        int y = pos[i]%n;
        if(M[x][y] == 'X')
            flag = false;
        else
            M[x][y] ='1';
    }

    if(!flag)
        return false;
    return valid(M);
}

int main(){
/*
   freopen("input.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
*/
    while(~scanf("%d",&n)&&n!=0)
    {
        vector<string>arr;
        string cad;
        for(int i=0;i<n;i++)
        {
            cin>>cad;
            arr.push_back(cad);
        }
        int sol = 0;
        vector<int>pos;
        for(int mask = 0 ; mask < (1<<(n*n)) ; mask++)
        {
            int ones = __builtin_popcount(mask);
            pos.clear();
            for(int j=0;j<(n*n);j++)
            {
                if((1<<j)&mask)
                    pos.push_back(j);
            }
            bool band = Solve(arr,pos);
            if(band)
                sol = max(sol,ones);
        }
        printf("%d\n",sol);
    }
/*
    fclose(stdin);
    fclose(stdout);
*/

    return 0;
}


