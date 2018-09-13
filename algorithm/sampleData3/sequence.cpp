#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int n;
	ifstream fin;
	fin.open("sequence.inp");
	
	fin>>n;
	//cout<<n<<endl;
	int tmp;
	int *s = new int[n];
	int *c = new int[n];
	int *re = new int[n];
	
	for(int i=0;i<n;i++)
	{
		fin>>s[i];
		//cout<<s[i]<<endl;
	}
	for(int i=0;i<n;i++)
	{
		fin>>c[i];
		//cout<<c[i]<<endl;
	}
	fin.close();
	

	int cnt=0;
	for(int k = n-1;k>=0;k--)
	{
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(s[i]>s[j])
				{
					tmp = s[i];
					s[i] = s[j];
					s[j] = tmp;
				}
			}
		}
		re[k] = s[c[k]+cnt];
		s[c[k]+cnt]=-1;
		cnt++;
	}
	ofstream fout;
	fout.open("sequence.out");
	for(int i=0;i<n;i++)
	{
		fout<<re[i]<<endl;
	}
	fout.close();
	
	
}
