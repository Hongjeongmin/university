#include<iostream>
#include<fstream>
#include<algorithm>
#include<stdio.h>
#include<vector>
#define INF 987654321
using namespace std;
int n;
typedef struct
{
	int x;
	int y;
	int p;
	int q;
	//int order;
}Data;
bool tmp(int& tmp1,int& tmp2)
{
	if(tmp1 < tmp2) return true;
	else if(tmp1 == tmp2)
	{
		tmp2=INF;
		return tmp1 < tmp2;
	}
	else return false; 
}


int completed_blind=0;
int parted_blind=0;
int non_blind=0;

Data paper[2002];
int map[4002][4002]; // 색종이 2000개 x값 x+w 값 하면 최대 4000개의 좌표
int X_modul[4002]; //압축된 좌표들의 번호 즉 인덱스 번호 
int Y_modul[4002]; // 압축된 좌표들의 번호 즉 인덱스 번호 
int paper_cnt[2002];
void Save_data(ifstream &fin);
void Make_value();
void Print_value(ofstream &fout);
void Modulation();
int X_look(int first,int last,int target);
int Y_look(int first,int last,int target); 

int main(void)
{
	ifstream fin;
	ofstream fout;
	
	fin.open("paper.inp");
	fout.open("paper.out");
	
	Save_data(fin);
//	cout<<"Save_data"<<endl;
	Modulation();
//	cout<<"Modulation"<<endl;
	Make_value();
//	cout<<"Make_value"<<endl;
	Print_value(fout);
//	cout<<"Print_value"<<endl;
}
void Make_value()
{
	int x,p,y,q;
	//map 채우기
//	cout<<"make_value_start"<<endl;
	for(int i=1;i<=n;i++)
	{
		x = X_look(1,2*n,paper[i].x);
		y = Y_look(1,2*n,paper[i].y);
		p = X_look(1,2*n,paper[i].p);
		q = Y_look(1,2*n,paper[i].q);
		
		for(int j=y;j<q;j++)
		{
			for(int k=x;k<p;k++)
			{
				map[j][k] = i;
			}
		}	
	} 
//	cout<<"make_value_end"<<endl;
}
int X_look(int first,int last,int target)//X축평행 맵핑된 인덱스 찾기 
{
	int mid;
	int midVal;
	
	while(true)
	{
		mid = (first+last)/2;
		midVal = X_modul[mid];
		
		if(midVal < target)
			first = mid +1;
		else if(midVal >target)
			last = mid -1;
		else
			return mid;
	}
}
int Y_look(int first,int last,int const target)//Y축평행 맵핑된 인덱스 찾기 
{
	int mid;
	int midVal;
	
	while(true)
	{
	
		mid = (first+last)/2;
		midVal = Y_modul[mid];
	//	cout<<"target: "<<target<<"  mid: "<<mid<<" midVal: "<<midVal<<endl;	
		if(midVal < target)
			first = mid +1;
		else if(midVal >target)
			last = mid -1;
		else
			return mid;
	}
}
void Modulation()
{
	//x값 압축 
//	cout<<"n: "<<n<<endl;
	for(int i=1;i<=n;i++)
	{
		X_modul[i] = paper[i].x;
	}
	for(int i=1;i<=n;i++)
	{
		X_modul[i+n] = paper[i].p;
	}
	//y값 압축 
	for(int i=1;i<=n;i++)
	{
		Y_modul[i] = paper[i].y;
	}
	for(int i=1;i<=n;i++)
	{
		Y_modul[i+n] = paper[i].q;
	}

//	cout<<"sort시작"<<endl;
	sort(X_modul+1,X_modul+(2*n)+1); // 압축결과 
//	sort(X_modul+1,X_modul+(2*n)+1);
	sort(Y_modul+1,Y_modul+(2*n)+1); // 압축결과 
///	for(int i=1;i<=2*n;i++) cout<<Y_modul[i]<<" "<<"i= "<<i<<" "<<endl;
//	cout<<endl;	
//	sort(Y_modul+1,Y_modul+(2*n)+1);
//	cout<<"sort완료"<<endl;
}

void Save_data(ifstream &fin)
{
	fin>>n;
	int w;
	int h;

	for(int i=1;i<=n;i++)
	{
		fin>>paper[i].x;
		fin>>paper[i].y;
		fin>>w;
		fin>>h;
		paper[i].p = paper[i].x + w;
		paper[i].q = paper[i].y + h;
	}
}
void Print_value(ofstream &fout)
{
	for(int i=1;i<=2*n;i++)
	{
		for(int j=1;j<=2*n;j++)
		{
			if(map[i][j] != 0)
			{
				paper_cnt[map[i][j]] ++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(paper_cnt[i] == 0) completed_blind++;
		else if(paper_cnt[i] == ((X_look(1,2*n,paper[i].p) -X_look(1,2*n,paper[i].x)) * (Y_look(1,2*n,paper[i].q) -Y_look(1,2*n,paper[i].y))))
		{
			non_blind++;
		}
		else
		{
			parted_blind++;
		}
	}
//	cout<<completed_blind<<" "<<parted_blind<<" "<<non_blind<<endl;
	fout<<completed_blind<<" "<<parted_blind<<" "<<non_blind<<endl;
}
