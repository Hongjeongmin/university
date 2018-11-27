#include<iostream>
#include<fstream>
#include<algorithm>
#include<stdio.h>
#define INF 987654321
using namespace std;
int n;//개수 
int I;//수입의 한계

int result_time;
int result_import;
int  countw=0;
typedef struct
{
	int w;//수입  
	int t;//시간
	int order;
	double essence;
}Data;
/* 이소스는 시간당 무게값이 큰순으로 나열함. 
bool tmp(const Data& tmp1,const Data& tmp2)
{
	if(tmp1.essence != tmp2.essence) return tmp1.essence > tmp2.essence;
	return tmp1.w<tmp2.w;
}
*/
bool tmp(const Data& tmp1,const Data& tmp2)
{
	if(tmp1.essence != tmp2.essence) return tmp1.essence < tmp2.essence;
	return tmp1.t>tmp2.t;
}
Data fr[1001];
bool freelancer_tr[1001];
bool dfs(int limit_w,int limit_t,int x);
void Print_F(ofstream &fout);
void look();
int Min_time(int x,int t,int w);
int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("freelancer.inp");
	fout.open("freelancer.out");
	
	fin>>n;fin>>I;
	
	for(int i=1;i<=n;i++)
	{
		fin>>fr[i].w;
		fin>>fr[i].t;
		fr[i].order = i;
		//fr[i].essence = (double)fr[i].w/fr[i].t;// 시간당 웨잇값 
		fr[i].essence = (double)fr[i].t/fr[i].w;
	}
	
	sort(fr+1,fr+n+1,tmp);
	
//	for(int i=1;i<=n;i++)
//	{
//		cout<<fr[i].w<<" "<<fr[i].t<<" "<<fr[i].essence<<" "<<fr[i].order<<endl;
//	}

	look();
	Print_F(fout);
}

bool dfs(int limit_w,int limit_t,int x)
{
	 
//	if(countw++ >= 30000) 
//	{
//		cout<<"count달성"<<endl;
//		return true; 
//	}

	limit_w += fr[x].w;
	limit_t += fr[x].t;
	
	if(limit_w>=I)
	{
		if(result_time>limit_t)
		{
			result_import = limit_w;
			result_time = limit_t;
		//	cout<<result_time<<endl;		
		}
		return false;
	}
	
	if(x==n) return false;
	
	/*
	// 두번째 return
	int remainder_w = I - limit_w;
	int remainder_t = remainder_w / fr[x+1].essence + 1;
	
	if(limit_t + remainder_t >= result_time) return true;
	*/
	
	int Min_t = Min_time(x,limit_t,I-limit_w);
	if(Min_t>=result_time) 
	{
		cout<<"죽은노드:"<<countw++<<endl;
		return false;
	}
	
	for(int i=x+1;i<=n;i++)
	{
	//	cout<<"X: "<<x<<endl;
		dfs(limit_w,limit_t,i);
		if(Min_t>=result_time) 
		{	
		//	cout<<"dfs하차"<<endl;
			return false;
		}
	}
	
}
void look()
{
	result_time = INF;
	result_import = INF;
	int Min_t = Min_time(0,0,I);
	for(int x=1;x<=n;x++)
	{
		dfs(0,0,x);
		if(Min_t>=result_time) 
		{
			cout<<"look하차"<<endl;
			return;
		}
	}
}
int Min_time(int x,int t,int w)
{
	//cout<<"I-w: "<<w<<endl;
	while(true)
	{
	//	cout<<x<<endl;
		x++;
		if(x>n) return result_time+500;
		if(w>=fr[x].w)
		{
			w -= fr[x].w;
			t += fr[x].t;
		}
		else
		{
			t += (int)(w*fr[x].essence);
	//		cout<<"얻을수 있는 최저 t:"<<t<<"  현재t: "<<result_time<<endl;
			return t;
		}		
	}
}
void Print_F(ofstream &fout)
{
	fout<<result_time<<" "<<result_import<<endl;
	cout<<result_time<<" "<<result_import<<endl;
}
