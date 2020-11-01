#include <stdio.h>
#include <ctime>
#include <stdlib.h>
main()
{
	int n,m;
	int mas[100][100];
	int mas_ed[100];
	srand(time(NULL));
	scanf("%d%d",&n,&m);
	//Zapolnenie massiva
	for(int i=0; i<n;i++)
	{
		for(int j=0; j<m;j++)
		{
			mas[i][j]=rand()%10;
		}
	}
	int k=0;
	for(int i=0; i<n;i++)
	{
		for(int j=0; j<m;j++)
		{
			mas_ed[k]=mas[i][j];
			k++;
		}
	}
	for(int i=0; i<n*m;i++)
	{
		for(int j=0; j<n*m-1;j++)
		{
			if(mas_ed[j]>mas_ed[j+1])
			{
				int q=mas_ed[j];
				mas_ed[j]=mas_ed[j+1];
				mas_ed[j+1]=q;			
			}
		}
	}
	int mas2[n][m]={0};
	int t=0,r=m-1,b=n-1,l=0;
	k=0;
	while(l<r and t<b)
	{
	for(int i=l;i<=r;i++)
	{
		mas2[t][i]=mas_ed[k];
		k++;
	}
	t++;
	for(int i=t;i<=b;i++)
	{
		mas2[i][r]=mas_ed[k];
		k++;
	}
	r--;
	for(int i=r;i>=l;i--)
	{
		mas2[b][i]=mas_ed[k];
		k++;
	}
	b--;
	for(int i=b;i>=t;i--)
	{
		mas2[i][l]=mas_ed[k];
		k++;
	}
	l++;
	}
	//Zapolnenie serediny
	if(n>=m and m%2==1 and n%2==1)
	{
		for(int i=t;i<=b;i++)
		{
			mas2[i][n/2-1]=mas_ed[k];
			k++;
		}
	}
	if(n<m and m%2==1 and n%2==1)
	{
		for(int i=l;i<=r;i++)
		{
			mas2[n/2][i]=mas_ed[k];
			k++;
		}
	}
	//Vyvod
	for(int i=0; i<n;i++)
	{
		for(int j=0; j<m;j++)
		{
			printf("%3d",mas[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	k=0;
	for(int i=0; i<n;i++)
	{
		for(int j=0; j<m;j++)
		{
			printf("%3d",mas_ed[k]);
			k++;
		}
	}
	printf("\n");
	printf("\n");
	
	for(int i=0; i<n;i++)
	{
		for(int j=0; j<m;j++)
		{
			printf("%3d",mas2[i][j]);
		}
		printf("\n");
	}
}
