#include<iostream>
#include<fstream>
using namespace std;
int T;
int N[100001];
int P[100001];
int n;
int i,j,k;
int cnt;
int p=0;
int main(void)
{
	ifstream fin;
	ofstream fout;	
	fin.open("inv.inp");
	fout.open("inv.out");	
	fin>>T;	
	for(i=0;i<T;i++)
	{
		fin>>n;
		for(j=1;j<=n;j++)//input
		{
			fin>>N[j]; 
		}
	
		fout<<cnt<<endl;
		cnt=0; 
	}		
}

