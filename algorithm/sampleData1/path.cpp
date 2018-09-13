#include <iostream>
#include <fstream>
using namespace std;

class List
{
	public:
		int m;
		int n;
		int k;
};

long double Factorial(int k)
{
	long double result = 1;
	for(int i=1;i<=k;i++)
	{
		result = result*i;
		cout<<result<<endl;
	}
	
	return result;
}

int main(void)
{
	int cnt;
	ifstream fin;
	fin.open("path.inp");
	
	fin >> cnt;
	
	int *result = new int[cnt];
	List *list = new List[cnt];
	int row_column[2];
	
	for(int i=0;i<cnt;i++)
	{
		fin >> list[i].n;
		fin >> list[i].m;
		fin >> list[i].k;
	}
	fin.close();
	
	for(int i=0;i<cnt;i++)
	{
		if(list[i].k == 0)
		{
			result[i] = Factorial(list[i].n-1 + list[i].m-1)/(Factorial(list[i].n-1)*Factorial(list[i].m-1));
		}
		else
		{

			row_column[0] = (list[i].k-1)/list[i].m; //row
			row_column[1] = (list[i].k-1)%list[i].m; // column
			
			result[i] = Factorial(row_column[0] + row_column[1])/(Factorial(row_column[0])*Factorial(row_column[1]));
			result[i] = result[i] * (Factorial((list[i].n -1 - row_column[0]) + (list[i].m-1 -row_column[1]))/(Factorial(list[i].n-1-row_column[0])*Factorial(list[i].m-1-row_column[1])));		
		}
	}
	
	ofstream fout;
	fout.open("path.out");
	
	for(int i=0;i<cnt;i++)
	{
		fout<<result[i]<<endl;
	}
	fout.close();
	
	
}
