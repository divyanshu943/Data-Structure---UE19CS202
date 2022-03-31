#include<stdio.h>
void bfs(int a[20][20],int source,int visited[20],int n)
{
	int q[20],f,u,r,v;
	f=0;
	r=-1;
	q[++r]=source; 
	while(f<=r)
	{
	u=q[f++];
	for(v=1;v<=n;v++)
	if(a[u][v]==1 && visited[v]==0)
	{
	q[++r]=v;
	visited[v]=1;
	}
	}
}
void main()
{
	int n,a[20][20],i,j,visited[20],source;
	printf("Enter the number of vertices:");
	scanf("%d",&n);
	printf("Enter the Adjacency matrix:\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
	visited[i]=0;
	printf("Enter the source node:\n");
	scanf("%d",&source);
	visited[source]=1;
	bfs(a,source,visited,n);
	for(i=1;i<=n;i++)
	{
	if(visited[i]!=0)
	printf("\n Node %d is reachable",i);
	else
	printf("\n Node %d is not reachable",i);
	}
	getch();
}