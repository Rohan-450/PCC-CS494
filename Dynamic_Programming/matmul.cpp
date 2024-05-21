#include<stdio.h>
#include<iostream>
using namespace std;
int p[20];
int M[20][20]={0};
int S[20][20]={0};
int n;

void matrixChainOrder()
{
	
	for(int i=1;i<=n;i++) 
		M[i][i]=0;

	for(int len=2;len<n;len++)
	{
		for(int i=1;i<n-len+1;i++)
		{
			int j=i+len-1;
			M[i][j]=999999;
			for(int k=i;k<j;k++)
			{
				int cost=M[i][k]+M[k+1][j]+p[i-1]*p[k]*p[j];
				if(cost<M[i][j]){
					M[i][j]=cost;
					S[i][j]=k;
				}
			}
		}
	}

    printf("\nM-table\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%4d",M[i][j]);
		}
        printf("\n");
	}

    printf("\nS-table\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%4d",S[i][j]);
		}
		printf("\n");
	}
}



void printOptimalParenthesis(int i,int j)
{
	if(i==j) 
        printf("A%d",i);
	else{
        printf("(");
		printOptimalParenthesis(i,S[i][j]);
		printOptimalParenthesis(S[i][j]+1,j);
        printf(")");
	}
}


int main()
{
	int i;
	printf("Enter number of matrices\n");
    scanf("%d",&n);
 	printf("Enter dimensions \n");
 	for(i=0;i<n;i++)
    {
        printf("Enter d%d :: ",i);
        scanf("%d",&p[i]);
    }
	matrixChainOrder();
    cout<<"Minimum number of multiplications are: ";
    cout<< M[1][n - 1]<<endl;
	printOptimalParenthesis(1,n-1);
	printf("\n");
	return 0;
}
