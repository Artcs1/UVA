#include<bits/stdc++.h>

using namespace std;

int preorder[10005],inorder[10005],input[10005],bst[1000005][5],n,pa = 0;

void build(int l,int r, int padre , int flag)
{
	if(l>r)
		return;

	int padre2 = pa ,i;

	printf("l: %d\n",l );
	printf("r: %d\n",r );

	for(i=l;i<=r;i++)
		if(preorder[pa] == inorder[i])
			break;

	if(padre!=-1)
		bst[preorder[padre]][flag] = preorder[pa];

	pa++;

	build(l,i-1,padre2,0);
	build(i+1,r,padre2,1);
}

void postorder(int u)
{
	if(u == -1)
		return;

	postorder(bst[u][0]);
	postorder(bst[u][1]);
	printf("%d\n",u);
}
int main()
{
	int i=0;
	while(~scanf("%d\n",&input[i]))
		i++;

	int n = i;

	for(int i=0;i<n;i++)
		preorder[i] = input[i];

	sort(input,input + n);

	for(int i=0;i<n;i++)
		inorder[i] = input[i];

	memset(bst,-1,sizeof bst);

	build( 0 , n-1 , -1 , 0);

	postorder(preorder[0]);
	return 0;
}