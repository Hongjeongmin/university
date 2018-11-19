#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#define INF 987654321
using namespace std;

class Lectangles
{
	public:
		int x;
		int y;
		int p;
		int q;
};
class Tree
{
	public:
		int left;
		int right;
		int max;
};

bool XXX(const Lectangles& tmp1,const Lectangles& tmp2)
{
	if(tmp1.x != tmp2.x) return tmp1.x < tmp2.x;
	return tmp1.y<tmp2.y;
}
bool YYY(const Lectangles& tmp1,const Lectangles& tmp2)
{
	if(tmp1.y != tmp2.y) return tmp1.y<tmp2.y;
	return tmp1.x < tmp2.x;
}
Lectangles L[10001]; // Max of number of lectangle is 10,000
Tree treeY[20001];
Tree treeX[20001];

int x_size;
int y_size;
int N;
int WWW,HHH; // it is result of input data
int look_maxY(int left,int right,int size)// size 는 현재 쳐다보는  
{

	if(treeY[size].left<=left && treeY[size].right>=right)//안에 있을경우 
	{
		return max(look_maxY(left,right,size*2),look_maxY(left,right,size*2+1));
	}
	else if(left<=treeY[size].left && right>= treeY[size].right) // 포함할경우 
	{ 
		return treeY[size].max;
	}
	
	return 0;
}

//bool Optimization[10001];
void Procedure()
{
//	int start=0;
//	int start_tmp=0;
	bool TR = true;
	int distance;
	int max_value;
	while(TR)
	{
		x_size=1;y_size=1;//세그먼트 트리 초기화 
		TR = false;

		//lower shift
		sort(L,L+N,YYY);

		for(int i=0;i<N;i++)
		{
			if(L[i].y == 0 ) 
			{
				continue;
			}
			max_value=0;
			for(int j =0 ; j < i ; j++)
			{
				if ( ((L[j].x >= L[i].x && L[j].x < L[i].p) || (L[j].p >L[i].x && L[j].p <= L[i].p)) || (L[j].x <= L[i].x && L[j].p >= L[i].p)) 
				{
					//겹치면 
					max_value = max(max_value,L[j].q);
				}
			}
			if(L[i].y == max_value)//움직이지 않았어요~ 
			{
			//	L[i].flgy = true;
				continue; // it is not fall 
			}  
	
			TR = true;
			distance = L[i].q - L[i].y;
			L[i].y = max_value;
			L[i].q = max_value + distance;
		}
		//left shift 
		sort(L,L+N,XXX);
		for(int i=0;i<N;i++)
		{
			if(L[i].x == 0) continue;
			max_value=0;
			for(int j =0 ; j< i ; j++)
			{
				
				if ( ( (L[j].q > L[i].y && L[j].q <= L[i].q)||(L[i].y <= L[j].y && L[j].y < L[i].q) ) || (L[j].y <= L[i].y && L[j].q >= L[i].q) ) 
				{
					//겹치면 
					max_value = max(max_value,L[j].p);
				}	
			}
			if(L[i].x == max_value) 
			{
			//	L[i].flgx = true;
				continue;
			}

			TR = true;
			distance = L[i].p - L[i].x;
			L[i].x = max_value;
			L[i].p = max_value + distance;
		}	
	}

	WWW=0;HHH=0;
	
	for( int i = 0 ; i < N ; i++)
	{
        HHH = max(HHH,L[i].q);
        WWW = max(WWW,L[i].p);

	}
}

int main(void)
{
	treeY[0].left=0;treeY[0].right=2000000000;
	treeX[0].left=0;treeX[0].right=2000000000;
	ifstream fin;
	ofstream fout;
	int T;
	int x,y;//lower-left vertex
	int p,q;//upeer-right vetex
	
	fin.open("block.inp");
	fout.open("block.out");
	
	fin>>T;
	
	for(int i=0;i<T;i++)
	{
		fin >> N; // number of lectangle
		for(int j=0;j<N;j++)
		{
			fin>>x;fin>>y; // Lower-left vertex
			fin>>p;fin>>q; // Upper-right vertex
			L[j].x = x;
			L[j].y = y;
			L[j].p = p;
			L[j].q = q;

		}
		Procedure();
		cout<< WWW << " " << HHH << endl;
		fout<< WWW << " " << HHH << endl;
			 
	}
}
