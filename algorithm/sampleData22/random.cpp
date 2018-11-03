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
	
	int T,N,M,K;
	cin >> T;
	fout << T << endl;
	cin >>N;cin >>M;cin >>K;
	//fout << M << " " << N << " " << K << endl;
	for(int t=0;t<T;t++)
	{
		v.clear();
		
		fout <<N<<" ";
		fout <<M<<" ";
		fout <<K<<endl;
		
		for(int i=0;i<M;i++)
		{
			fout<<(rand() % N +1)<<" "<<(rand() % N +1)<<" "<<(rand() % 1000 +1)<<endl;
		}
		
		for(int i=0;i<K;i++)
		{
			fout<<(rand() % N+1)<<" "<<(rand() % N+1)<<endl;
		}

	}
	return 0;
}
