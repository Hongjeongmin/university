#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <vector>
using namespace std;

typedef struct
{
	int a;
	int b;
}mem;

vector<mem> v;

int main()
{
	ofstream fout;
	fout.open("test.inp");
	
	srand((unsigned int)time(NULL));
	
	int T,n,k;
	cin >> T;
	fout << T << endl;
	//fout << M << " " << N << " " << K << endl;
	for(int t=0;t<T;t++)
	{
		v.clear();
		cin >>n>>k;
		fout <<n<<" "<<k<<endl;
		for(int i=0;i<n;i++)
		{
			fout<<(rand() % 199)+2<<" ";
			fout<<(rand() % 5)+1<<" ";
			fout<<(rand() % 5)+1<<" ";
			fout<<endl;
		}
		fout<<endl;
		

	}
	return 0;
}
