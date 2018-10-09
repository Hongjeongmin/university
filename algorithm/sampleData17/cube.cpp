#include<iostream>
#include<fstream>
using namespace std;
int dp[201][201][201]={0};
int cube(int w,int l,int h)
{
	int &ref = dp[w][l][h];
	if(dp[w][l][h]!=0)
	{
		return ref;
	}
	else if(dp[w][h][l]!=0)
	{
		ref = dp[w][h][l];
		return ref;
	}
	else if(dp[l][w][h]!=0)
	{
		ref = dp[l][w][h];
		return ref;
	}
	else if(dp[l][h][w]!=0)
	{
		ref = dp[l][h][w];
		return ref;
	}
	else if(dp[h][l][w]!=0)
	{
		ref = dp[h][l][w];
		return ref;
	}
	else if(dp[h][w][l]!=0)
	{
		ref = dp[h][w][l];
		return ref;
	}
					
	if(w==0||l==0||h==0)
	{
		ref = 50000;
		return ref;
	}
		
	if(w==h&&w==l)
	{
		ref =1;
		return ref;
	}
	if(w==1||l==1||h==1)
	{
		ref= w*l*h;
		return ref;
	}
	int a1,a2,a3;
	int b1,b2,b3;
	a1=100000;
	for(int i=1;i<=(w+1)/2;i++)
	{
		if(w-i==0)continue;	
		b1= cube(i,l,h) + cube(w-i,l,h);
		if(b1<a1) a1 = b1;
	}
	a2=100000;
	for(int i=1;i<=(l+1)/2;i++)
	{
		if(l-i==0)continue;		
		b2= cube(w,i,h) + cube(w,l-i,h);
		if(b2<a2) a2 = b2;
	}
	a3=100000;
	for(int i=1;i<=(h+1)/2;i++)
	{
		if(h-i==0)continue;
		b3= cube(w,l,i) + cube(w,l,h-i);
		if(b3<a3) a3 = b3;
	}
	ref = min(a1,min(a2,a3));		
	return ref;
		
}
int main(void)
{
	int T;
	int w,l,h;
	ifstream fin;
	ofstream fout;
	fin.open("cube.inp");
	fout.open("cube.out");
	fin>>T;
	
	for(int i=1;i<=T;i++)
	{
		fin>>w;fin>>l;fin>>h;
		fout<<cube(w,l,h)<<endl;
	}
	
	fin.close();
	fout.close();
}
