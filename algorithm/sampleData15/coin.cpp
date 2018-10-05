#include <iostream>
#include <fstream>
using namespace std;
int n;
int c[3];
int dp[105][105][105]={147201};//1is my turn


int look(int l,int m,int r)
{
	return dp[l+3][m+3][r+3];
}
int main(void)
{

	for(int i=1;i<=100;i++)
	{
		if((i-1)%4==0)
		{
			dp[i+3][3][3]=-1;
			dp[3][i+3][3]=-1;
			dp[3][3][i+3]=-1;
		}
		else
		{
			dp[i+3][3][3]=1;
			dp[3][i+3][3]=1;
			dp[3][3][i+3]=1;
		}
	}
	for(int i=0;i<=100;i++)
	{
		for(int j=0;j<=100;j++)
		{
			for(int k=0;k<=100;k++)
			{
				if((i==0&&j==0)||(i==0&&k==0)||(k==0&&j==0)) continue;
				
				if(dp[j+2][k+3][i+3]==-1||dp[j+1][k+3][i+3]==-1||dp[j][k+3][i+3]==-1)
				{
					dp[j+3][k+3][i+3]=1;
					continue;
				}
				
				if(dp[j+3][k+2][i+3]==-1||dp[j+3][k+1][i+3]==-1||dp[j+3][k][i+3]==-1)
				{
					dp[j+3][k+3][i+3]=1;
					continue;
				}	

				if(dp[j+3][k+3][i+2]==-1||dp[j+3][k+3][i+1]==-1||dp[j+3][k+3][i]==-1)
				{
					dp[j+3][k+3][i+3]=1;
					continue;
				}			
				
				dp[j+3][k+3][i+3]=-1;
								
			}
		}
	}
	
	ifstream fin;
	ofstream fout;
	fin.open("coin.inp");
	fout.open("coin.out");
	fin>>n;
	for(int i=0;i<n;i++)
	{
		fin>>c[0];fin>>c[1];fin>>c[2];
		
		
		fout<<"("<<c[0]<<" "<<c[1]<<" "<<c[2]<<") : "<<look(c[0],c[1],c[2])<<endl;
		//cout<<"("<<c[0]<<" "<<c[1]<<" "<<c[2]<<") : "<<look(c[0],c[1],c[2])<<endl;
			
	}
}
