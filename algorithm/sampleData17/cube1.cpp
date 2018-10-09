#include<iostream>
#include<fstream>
using namespace std;
int dp[201][201][201]={0};
int cube(int w,int l,int h)
{
	int &ref = dp[w][l][h];
	if(ref!=0)
	{
		return ref;
	}
	
	if(w==0||l==0||h==0)
	{
		cout<<"0000000000"<<endl;
		ref = 50000;
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
		int min_par= min(w,min(l,h));
		int case1,case2;
		if(min_par==w)
		{
			if(l%w==0&&h%w==0)
			{
				ref = (l/w) * (h/w);
				return ref;
			}
			else
			{
				if(w==l)
				{
					ref = cube(w,l,min_par) + cube(w,l,h-min_par);
					return ref;
				}
				else if(w==h)
				{
					ref = cube(w,min_par,h) + cube(w,l-min_par,h);
					return ref;
				}
				else
				{
					case1 = cube(w,l-min_par,h) + cube(w,min_par,h);
					case2 = cube(w,l,h-min_par) + cube(w,l,h-min_par);
					if(case1>case2)
					{
						ref= case2;
					}
					else
					{
						ref = case1;
					}
					return ref;				
				}

			}
		}
		else if(min_par==l)
		{
			if(w%l==0&&h%l==0)
			{
				ref = (w/l) * (h/l);
				return ref;
			}
			else
			{
				if(l==w)
				{
					ref = cube(w,l,min_par) + cube(w,l,h-min_par);
					return ref;
				}
				else if(l==h)
				{
					ref = cube(min_par,l,h) + cube(h-min_par,l,h);
					return ref;
				}
				else
				{
					case1 = cube(w-min_par,l,h) + cube(min_par,l,h);
					case2 = cube(w,l,h-min_par) + cube(w,l,min_par);
					if(case1>case2)
					{
						ref= case2;
					}
					else
					{
						ref = case1;
					}
					return ref;			
				}

			}						
		}
		else
		{
			if(w%h==0&&l%h==0)
			{
				ref = (w/h) * (l/h);
				return ref;
			}
			else
			{	
				if(h==w)
				{
					ref = cube(w,min_par,h) + cube(w,l-min_par,h);
				}
				else if(h==l)
				{
					ref = cube(min_par,l,h) + cube(w-min_par,l,h);
				}
				else
				{
					case1 = cube(w-min_par,l,h) + cube(min_par,l,h);
					case2 = cube(w,l-min_par,h) + cube(w,min_par,h);
					if(case1>case2)
					{
						ref= case2;
					}
					else
					{
						ref = case1;
					}
					return ref;				
				}

			}				
		}
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
		cout<<cube(w,l,h)<<endl;
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
