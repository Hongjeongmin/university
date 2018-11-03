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
	
	int T,N;
	cin >> T;
	fout << T << endl;
	//fout << M << " " << N << " " << K << endl;
	for(int t=0;t<T;t++)
	{
		v.clear();
		cin >>N;
		fout <<N<<endl;
		for(int i=0;i<N;i++)
		{
			fout<<(rand() % N)<<endl;
		}

	}
	return 0;
}
