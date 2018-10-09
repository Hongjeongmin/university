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
		//cout<<"0000000000"<<endl;
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
		if(min_par==w && min_par!=l && min_par!=h)
		{
			if(l%w==0&&h%w==0)
			{
				ref = (l/w) * (h/w);
				return ref;	
			}
			else if(l%w==0&&h%w!=0)
			{
				ref = (l/w) * cube(w,w,h);
				return ref;
			}
			else if(h%w==0&&l%w!=0)
			{
				ref = (h/w) * cube(w,l,w);
				return ref;
			}
			else if(l==h)
			{
				if(l%2==0)
				{
					
				}
				else
				{
					
				}
			}
		}////////////////////////////////////////////////////////////////
		else if(min_par!=w && min_par==l && min_par!=h)
		{
			
		}/////////////////////////////////////////////////////////////////
		else if(min_par!=w && min_par!=l && min_par==h)
		{
			
		}//////////////////////////////////////////////////////////////////
		else if(min_par==w && min_par==l)
		{
			
		}/////////////////////////////////////////////////////////////////
		else if(min_par==l && min_par==h)
		{
			
		}///////////////////////////////////////////////////////////////////
		else if(min_par==w && min_par==h)
		{
			
		}////////////////////////////////////////////////////////////////////
	}
		
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
		cout<<cube(w,l,h)<<endl;
	}
	fin.close();
	fout.close();
}
