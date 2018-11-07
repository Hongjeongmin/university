#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include <stdlib.h>
using namespace std;
int heap[1000000];
int size=0;
void PUSH(int p)
{
	heap[size] = p;
	
	int current = size;
	int parent =(size-1)/2;
	
	while(current > 0 && heap[current] > heap[parent])
	{
		swap(heap[current],heap[parent]);
		current = parent;
		parent = (parent -1) /2;
	}
	
	size++;
}
void POP()
{
	heap[0] = heap[size-1];
	heap[size-1] = 0;
	size--;
	if(size<0) size=0;		
	for(int i=0; i* 2 + 1 <=size;)
	{
		if(heap[i] >= heap[i * 2 +1] && heap[i] >= heap[i * 2 + 2])
			break;
		if(heap[i * 2 + 1] > heap[i * 2 + 2])
		{
			swap(heap[i], heap[i * 2 + 1]);
			i = i * 2 + 1;
		}
		else
		{
			swap(heap[i],heap[i * 2 + 2]);
			i = i * 2 + 2;
		}
	}
}

void Report(ofstream &fout)
{
	int s=0;
	while(s<size)
	{
		
		fout<<heap[s]<<" ";
//		cout<<heap[s]<<" ";
		s = s*2 +1;//0   1   2   4   8   16
	}
	fout<<endl;
//	cout<<endl;
}
int main(void)
{
	ifstream fin;
	ofstream fout;
	
	fin.open("queue.inp");
	fout.open("queue.out");
	
	string c;
	
	 
	while(true)
	{
		fin>>c;
		
		if(c=="r")// report
		{
			Report(fout);
		}
		else if(c=="d")// delete
		{
			POP();
		}
		else if(c=="q")//quit
		{
			break;
		}
		else
		{
			PUSH(atoi(c.c_str()));
		}
	}
	fin.close();
	fout.close();
}
