#include<iostream>
#include<fstream>
#include<algorithm>
#include<string.h>
using namespace std;
int dp[201][201][201]={0};
int cube(int w,int l,int h)
{
	int &ref = dp[w][l][h];
	if(ref!=0)
	{
		return ref;
	}
	
	if(w==h&&w==l)
	{
		ref =1;
		return ref;
	}
	else if(w==1||l==1||h==1)
	{
		ref= w*l*h;
		return ref;
	}
	else
	{
		int min_par = min(min(w,l),h);
		int case1,case2;
		if(min_par == w && min_par!= l && min_par != h)
		{
			//cout<<"1case"<<endl;
			if(l==h&&l%2==0)
			{
				if(h%w==0)
				{
					ref = (h/w) * (h/w);
				}
				else
				{
					ref = cube(w/2,l,h) + cube(w-w/2,l,h);	
				}
				
			}
			else
			{
				case1 = cube(w,min_par,h) + cube(w,l-min_par,h);	
				case2 = cube(w,l,min_par) + cube(w,l,h-min_par);	
				if(case1>case2) ref = case2;
				else ref = case1;
			}

		}
		else if(min_par != w && min_par== l && min_par != h)
		{
			//cout<<"2case"<<endl;
			if(w==h&&w%2==0)
			{
				if(w%l==0)
				{
					ref = (w%l) * (w%l);
				}
				else
				{
					ref = cube(w,l/2,h) + cube(w,l-l/2,h);
				}
			}
			else
			{
				case1 = cube(min_par,l,h) + cube(w-min_par,l,h);	
				case2 = cube(w,l,min_par) + cube(w,l,h-min_par);	
				if(case1>case2) ref = case2;
				else ref = case1;			
			}
		}
		else if(min_par != w && min_par != l && min_par == h)
		{
			//cout<<"3case"<<endl;
			if(w==l&&w%2==0)
			{
				if(w%h==0)
				{
					ref = (w/h) * (w/h);
				}
				else
				{
					ref = cube(w,l,h/2) + cube(w,l,h-h/2);
				}
				
			}
			else
			{
				case1 = cube(min_par,l,h) + cube(w-min_par,l,h);	
				case2 = cube(w,min_par,h) + cube(w,l-min_par,h);	
				if(case1>case2) ref = case2;
				else ref = case1;					
			}
		}
		else if(min_par == w && min_par == l && min_par != h)
		{
			//cout<<"4case"<<endl;
			ref = cube(w,l,min_par) + cube(w,l,h-min_par);	

		}
		else if(min_par == w && min_par != l && min_par == h)
		{
			//cout<<"5case"<<endl;
			ref = cube(w,l-min_par,h) + cube(w,min_par,h);	
		}
		else if(min_par != w && min_par == l && min_par == h)
		{
			//cout<<"6case"<<endl;
			ref = cube(min_par,l,h) + cube(w-min_par,l,h);
		}						
		return ref;
	}
	
}
int main(void)
{
	//cout<<min(min(1,2),3)<<endl;
	int T;
	int w,l,h;
	ifstream fin;
	ofstream fout;
	fin.open("cube.inp");
	fout.open("cube.out");
	fin>>T;
	//cin>>T;
	for(int i=1;i<=T;i++)
	{
	//	cin>>w;cin>>l;cin>>h;
		fin>>w;fin>>l;fin>>h;
		//cout<<cube(w,l,h)<<endl;
		fout<<cube(w,l,h)<<endl;
	//	cout<<cube(w,l,h)<<endl;
	}
	/*
	for(int i=0;i<=15;i++)
	{
		for(int j=0;j<=15;j++)
		{
			for(int k=0;k<=15;k++)
			{
				cout<<"dp["<<i<<"]["<<j<<"]["<<k<<"] = "<<dp[i][j][k]<<endl; 
			}
		}
	}
	*/
	fin.close();
	fout.close();
}
