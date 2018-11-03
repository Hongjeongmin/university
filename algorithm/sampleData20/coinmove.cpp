#include<iostream>
#include<fstream>
using namespace std;
class Arr
{
	public:
		int k[7];
};

int p;
int k;
int s;
Arr N[1000001];
int T;


int movecoin(int p,int k,int s)//p 2~10 k 3~7 s 5~10^6
{
	for(int i=1;i<s;i++)
	{
		if(i%p==0)
		{
			for(int q=0;q<k;q++)
			{
				N[i].k[q] = 0;
			}
		}
		else
		{
			for(int j=1;j<=k;j++)
			{
				if(i-j<0)
				{
					N[i].k[j-1] = -1;
				}
				else
				{
					for(int q=0;q<k;q++)
					{		
						if(j-1!=q)
						{
							if(N[i-j].k[q]==0)
							{
								N[i].k[j-1] = -1;
								break;
							}											
						}
						if(q==k-1)
						{
							N[i].k[j-1] = 0;
							break;
						}						
					}
				}
			}
		}
	}
	for(int j=1;j<=k;j++)
	{
		if(s-j<0)
		{
			N[s].k[j-1] = -1;
		}
		else
		{
			for(int q=0;q<k;q++)
			{		
				if(j-1!=q)
				{
					if(N[s-j].k[q]==0)
					{
						N[s].k[j-1] = -1;
						break;
					}											
				}
				if(q==k-1)
				{
					N[s].k[j-1] = 0;
					return s-j;
				}						
			}
		}
	}
	return -1;	
}
int main(void)
{
	for(int q=0;q<7;q++)
	{
		N[0].k[q] = -1;
	}
	ifstream fin;
	ofstream fout;
	fin.open("coinmove.inp");
	fout.open("coinmove.out");
	fin>>T;
	
	for(int i=0;i<T;i++)
	{
		fin>>p;fin>>k;fin>>s;
	//	cout<<movecoin(p,k,s)<<endl;
		fout<<movecoin(p,k,s)<<endl;
		/*
		for(int q=0;q<=s;q++)
		{
			cout<<q<<" : ";
			for(int w=0;w<k;w++)
			{
				cout<<N[q].k[w]<<" ";
			}
			cout<<endl;
		}
		*/
				
	}
	fin.close();
	fout.close();
}
