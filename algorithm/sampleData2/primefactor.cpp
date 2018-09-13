#include<iostream>
#include<fstream>
using namespace std;
int Sosu(int number)
{
	for(int i=2;i<=(number/2);i++)
	{
		if(number%i==0) return 0; //no Prime Number
	}
	return 1; // is Prime Number
}
int main()
{
	int n;
	int j=2;
	int result=0;
	
	ifstream fin;
	fin.open("primefactor.inp");
	
	fin>>n;
	
	int *arr = new int[n];
	
	for(int i=0;i<n;i++)
	{
		fin>>arr[i];
	}
	fin.close();
	
	ofstream fout;
	fout.open("primefactor.out");
	
	for(int i=0;i<n;i++)
	{
		if(Sosu(arr[i])==1)
		{
			fout<<"Prime Number"<<endl;
		}
		else
		{
			j=2;
			result=0;
			while(true)
			{
				if(arr[i]%j==0)
				{
					result = result + j;
					arr[i] = arr[i]/j;
					if(arr[i]==1) break;
				}
				else
				{
					while(true)
					{
						j++;
						if(Sosu(j)==1) break;
					}
				}
			}
			fout<<result<<endl;
		}
	}
	fout.close();
}
