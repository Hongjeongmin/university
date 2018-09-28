#include<iostream>
#include<fstream>
using namespace std;
class Ladder
{
	public:
		int x=-1;
		int y=-1;
};

Ladder ladder[10000][50];

int main(void)
{
	ifstream fin;
	ofstream fout;
	fin.open("ladder.inp");
	fout.open("ladder.out");
	int start;
	
	int n;
	int *arr = new int[n];
	fin>>n;
	int x1,x2,y1,y2;
	
	while(true)
	{
		fin>>x1;fin>>y1;fin>>x2;fin>>y2;
		if(x1+x2+y1+y2==0) break;
		ladder[y1][x1].x=x2;ladder[y1][x1].y=y2;
		
		ladder[y2][x2].x=x1;ladder[y2][x2].y=y1;
	}
	
	for(int i=0;i<n;i++)
	{
		x1=i;y1=9999;
		while(true)
		{
			if(ladder[y1][x1].y==-1)
			{
				y1--;
				if(y1==0) break;
			}
			else 
			{
				x2=ladder[y1][x1].x;
				y2=ladder[y1][x1].y;
				x1=x2;
				y1=y2-1;
				if(y1==0) break;
			}
		}
		arr[x1]=i;
	}
	for(int i=0;i<n;i++)
	{
		fout<<arr[i]<<" ";
	}	
}
