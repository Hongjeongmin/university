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
		int pastX;
		int pastY;
		
};
class Tree
{
	public:
		int left;
		int right;
		int max;
};
void Swap(Lectangles &tmp1,Lectangles &tmp2)
{
//	cout<<tmp1.x<<" "<<tmp1.y<<endl;
//	cout<<tmp2.x<<" "<<tmp2.y<<endl;
	Lectangles tmp = tmp1;
	tmp1 =tmp2;
	tmp2 = tmp;
}
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
int N;
int WWW,HHH; // it is result of input data

//bool Optimization[10001];
void Procedure()
{
	int distance;
	int max_value;
	bool TR = true;
	bool ok;
	int start = 0; 
	//여기서부턴 sort 최전화 해줍니다. 
//	int cnt=0;
	while(start<N)
	{
		//lower shift

		sort(L+start,L+N,YYY);
		for(int i=start;i<N;i++)
		{
			if(L[i].pastX == L[i].x && L[i].pastY == L[i].y) start++;
			else break;
		}

		for(int i=start;i<N;i++)
		{
			L[i].pastX = L[i].x;
			L[i].pastY = L[i].y;
			/*
			if(L[i].y == 0 ) 
			{
				continue;
			}
			*/
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
				continue; // it is not fall 
			}  
			//TR = true;
			distance = L[i].q - L[i].y;
			L[i].y = max_value;
			L[i].q = max_value + distance;
	
		}
		//left shift 
		sort(L+start,L+N,XXX);
		for(int i=start;i<N;i++)
		{
			/*
			if(L[i].x == 0) 
			{		
				continue;
			}
			*/
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
				continue;
			}
	//		TR = true;
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
	//	cout<< WWW << " " << HHH << endl;
		fout<< WWW << " " << HHH << endl;
			 
	}
}
