#include<iostream>
#include<fstream>
using namespace std;
int n;
int pump;
int T;
long long int result; 
int N[2][100000];
int dp[2][100010]; //0 top 1 bottom
int Stickers(int where,int cul)
{

	int &ref = dp[where][cul];
	if(ref!=147201)
	{
		return ref;
	}
	if(cul>n) return 0;
	if(cul==n)
	{
		ref = N[where][n];
		return ref;
	} 
	
	if(where==0)
	{
		ref = N[0][cul] + max(Stickers(1,cul+1),max(Stickers(1,cul+2),Stickers(0,cul+2)));
		return ref;	
	}
	else
	{
		ref = N[1][cul] + max(Stickers(0,cul+1),max(Stickers(0,cul+2),Stickers(1,cul+2)));
		return ref;
	}
}
int main(void)
{
	
	ifstream fin;
	ofstream fout;
	fin.open("stickers.inp");
	fout.open("stickers.out");
	fin>>T;
	
	for(int i=1;i<=T;i++)
	{
		fin>>n;
		for(int j=1;j<=n;j++)fin>>N[0][j];
		for(int j=1;j<=n;j++)fin>>N[1][j];
		for(int j=1;j<=n+10;j++)dp[0][j]=147201;
		for(int j=1;j<=n+10;j++)dp[1][j]=147201;
		for(int j=n;j>=1;j--) 
		{
			Stickers(0,j);
			Stickers(1,j);
		}
		fout<<max(Stickers(0,1),Stickers(1,1))<<endl;					
	}

	fin.close();
	fout.close();
}
