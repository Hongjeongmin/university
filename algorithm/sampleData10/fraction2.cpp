#include<iostream>
#include<fstream>
using namespace std;
int cnt=0;
class Fraction
{
	public:
		int m;
		int n;
};
class HV
{
	public:
		int h;
		int v;
};
Fraction fraction[1000001];

int Look(int m,int n);//how numbuer?
void FR(Fraction left,Fraction right,int m,int n);
void HandV(int n,HV &hv);// if you insert n , you will get holizontality! 
int howv(int n);
int getn(int hv_h,int hv_v);

int main(void)
{
	int m,n; // m/n
	Fraction x,y;
	x.m=0;x.n=1;y.m=1;y.n=0;
	ifstream fin;
	ofstream fout;
	fin.open("fraction.inp");
	fout.open("fraction.out");
	HV hv;
	fraction[1].m=1; fraction[1].n=1;
	while(true)
	{
		//fin>>m;
		//fin>>n;
		cin>>m;
		cin>>n;
		cnt=0;
		if(m==1&&n==1) break;
		////////////////////////
		
		for(int i=2;;i++)
		{
			
			cout<<"49라인 실행중"<<endl;
			cout<<getn(i,1)<<endl;
			cout<<getn(i-1,1)<<endl;
			fraction[getn(i,1)].m = fraction[getn(i-1,1)].m;//0 + m
			cout<<"51완료"<<endl;
			fraction[getn(i,1)].n = 1 + fraction[getn(i-1,1)].n;// 1 + n
			cout<<"실행중"<<endl;
			
			cout<<fraction[getn(i,1)].m<<"/"<<fraction[getn(i,1)].n<<endl;
			if(fraction[getn(i,1)].m==m)
			{
				if(fraction[getn(i,1)].n)
				{
					cnt = getn(i,n);
					break;
				}
			}
			for(int j=2;j<howv(i);j++)
			{
				cout<<"j: "<<j<<endl;
				fraction[getn(i,j)].m = fraction[getn(i-1,(j+1)/2)].m + fraction[getn(i-2,(((j+1)/2)+1)/2)].m;
				fraction[getn(i,j)].n = fraction[getn(i-1,(j+1)/2)].n + fraction[getn(i-2,(((j+1)/2)+1)/2)].n;
				if(fraction[getn(i,j)].m==m)
				{
					if(fraction[getn(i,j)].n==n)
					{
						cnt = getn(i,j);
						break;
					}
				}
				
			
			}
			fraction[getn(i,howv(i))].m=fraction[getn(i-1,howv(i-1))].m +1;//m + 1
			fraction[getn(i,howv(i))].n= 1 + fraction[getn(i-1,howv(i-1))].n;// n + 0	
			if(fraction[getn(i,howv(i))].m==m)
			{
				if(fraction[getn(i,howv(i))].n==n)
				{
					cnt = getn(i,howv(i));
					break;
				}
			}		
		}
		
		////////////////////////
	}
	

	
	fout.close();
	fin.close();	
}

void FR(Fraction left,Fraction right,int m,int n)
{
	Fraction center;
	center.m=left.m+right.m;
	center.n=left.n+right.n;
}
int Look(int m,int n)
{
	
}
void HandV(int n,HV &hv)
{
	int i=1;
	int h=0;
	int v=0;
	int cnt=0;
	int cnt_=0;
	if(n==1)
	{
		hv.h = 1;
		hv.v = 1;
		return;
	}
	for(i;;i=i*2)
	{	
		h++;
		cnt=cnt_+i;
		if(cnt>=n)
		{
			break;	
		}
		else
		{
			cnt_=cnt;	
		}
		
	}
	hv.h = h;//행 
	hv.v = n-cnt_;//열 
}
int getn(int hv_h,int hv_v)
{
	cout<<"getn실행중"<<endl;
	int n=0;
	int cnt=0;
	for(int i=1;;i=i*2)
	{
		n=n+i;
		cnt++;
		if(cnt==hv_h-1) break;
	}
	
	return n+hv_v;// 행과 열주면 배열에 몇번째인지 
}
int howv(int n)
{
	int result=1;
	for(int i=1;i<n;i++)
	{
		result=result*2;
	}
	return result;
}
