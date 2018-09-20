#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int cnt=0;
string str;
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
Fraction fraction[1000][100000];
int howv(int n);
int check;
int LR=0;//0is left 1is right
int god,duf;//god=행 duf=열 

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
	fraction[1][1].m=1; fraction[1][1].n=1;
	while(true)
	{
		str.clear();
		//fin>>m;
		//fin>>n;
		cin>>m;
		cin>>n;
		cnt=0;
		check=0;
		if(m==1&&n==1) break;
		////////////////////////
		//cout<<"fraction[1][1]: "<<fraction[1][1].m<<"/"<<fraction[1][1].n<<endl;
		for(int i=2;;i++)
		{
			fraction[i][1].m = 1;
			fraction[i][1].n = 1 + fraction[i-1][1].n;
			//cout<<"fraction["<<i<<"][1]: "<<fraction[i][1].m<<"/"<<fraction[i][1].n<<endl;
			if(fraction[i][1].m==m)
			{
				if(fraction[i][1].n==n)
				{
					hv.h=i;hv.v=1;
					break;
				}
			}
			for(int j=2;j<howv(i);j++)
			{
				
				if(j%2==0)//짝수라면 처음 왼쪽으로 경로임~  
				{
					LR=1;//처음 왼쪽으로 경로 했으니 오른쪽인 경로인값을 더하면되죠~ 
				}
				else
				{
					LR=0;
				}
				god = i-1;
				duf = (j+1)/2;			
				while(true)
				{
	
					if(duf%2 == LR)//0이면 짝수니깐 왼쪽 1이면 홀수 니깐 오른쪽					
					{
						god = god-1;
						duf = (duf+1)/2;
						break;	
					}
					god = god-1;
					duf = (duf+1)/2;
								
				}
				fraction[i][j].m = fraction[i-1][(j+1)/2].m + fraction[god][duf].m;
				fraction[i][j].n = fraction[i-1][(j+1)/2].n + fraction[god][duf].n;
				
				
			//	cout<<"fraction["<<i<<"]["<<j<<"]: "<<fraction[i][j].m<<"/"<<fraction[i][j].n<<endl;
				if(fraction[i][j].m==m)
				{
					if(fraction[i][j].n==n)
					{
						hv.h=i;
						hv.v=j;
						check=1;
						break;
					}
				}
			}
			if(check == 1) break;
			
			
			fraction[i][howv(i)].m = fraction[i-1][howv(i)/2].m +1;
			fraction[i][howv(i)].n = 1;
			//cout<<"fraction["<<i<<"]["<<howv(i)<<"]: "<<fraction[i][howv(i)].m<<"/"<<fraction[i][howv(i)].n<<endl;
			if(fraction[i][howv(i)].m==m)
			{
				if(fraction[i][howv(i)].n==n)
				{
					hv.h=i;hv.v=howv(i);
					break;					
				}
			}		
		}
		cout<<"("<<hv.h<<" , "<<hv.v<<")"<<endl;
		god=hv.h;
		duf=hv.v;
		for(god;god>1;god--)
		{
			if(duf%2==0)
			{
				str.append("R");
			}
			else
			{
				str.append("L");
			}
			duf=(duf+1)/2;
		}
		for(int i=str.length()-1;i>=0;i--)
		{
			cout<<str[i];
			fout<<str[i];
		}
		fout<<endl;
		cout<<endl;
		
		////////////////////////
	}
	

	
	fout.close();
	fin.close();	
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
