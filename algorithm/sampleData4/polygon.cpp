#include <iostream>
#include <fstream>

using namespace std;
int abs(int &a)
{
	if(a>0)
	{
		return a;
	}
	else
	{
		return -a;
	}
}
int main(void)
{
	ifstream fin;
	ofstream fout;
	fin.open("polygon.inp");
	fout.open("polygon.out");
	int t; // this is test case count
	int n;
	int r;
	int cnt=0;
	int is_1=0;
	fin>>t;
	
	for(int i=0;i<t;i++)
	{	
		is_1=0;
		fin>>n;
		int *s1 = new int[n];
		int *s2 = new int[n];
		int *tmp = new int[n]; 
		for(int j=0;j<n;j++)
		{
			fin>>s1[j];
		}
		for(int j=0;j<n;j++)
		{
			fin>>s2[j];
		}		
		//----------------------------
		//정배열 비교
		for(int j=0;j<n;j++)
		{
			cnt=0;
			r=j;
			for(int k=0;k<n;k++)
			{
				if(s1[(r+k)%n]==s2[k])
				{
					cnt++;
				}
				else
				{
					break;
				}
			}
			if(cnt==n)
			{
				is_1=1;
				break;
			}
		}
		if(is_1==1)
		{
			fout<<"1"<<endl;
		}		
		else//역배열 배교
		{
		/////////////////역배치하기
			for(int j=0;j<n;j++)
			{
				if(s1[(j+n-1)%n]>0)
				{
					tmp[j]= -abs(s1[j]);
				}
				else
				{
					tmp[j]= abs(s1[j]);
				}
			}
			for(int j=0;j<n;j++)
			{
				s1[j]= tmp[n-j-1];
			}
			for(int j=0;j<n;j++)
			{
				r=j;
				cnt=0;
				for(int k=0;k<n;k++)
				{
					if(s1[(r+k)%n]==s2[k])
					{
						cnt++;
					}
					else
					{
						break;
					}
				}
				if(cnt==n)
				{
					is_1=1;
					break;
				}
			}
			if(is_1==1)
			{
				fout<<"1"<<endl;
			}
			else
			{
				fout<<"0"<<endl;
			}		
		}
		 
		//----------------------------
		
		delete [] s1;
		delete [] s2;
		delete [] tmp;
	}
	
}
