#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;
int god,duf;//god=�� duf=�� 
int m,n;
int left_m,left_n;
int right_m,right_n;
int tmp_m,tmp_n;
string s_m,s_n;
int main(void)
{
	 // m/n
	ifstream fin;
	ofstream fout;
	fin.open("fraction.inp");
	fout.open("fraction.out");
	while(true)
	{
		left_m=0;
		left_n=1;
		right_m=1;
		right_n=0;
		tmp_m=1;
		tmp_n=1;
		fin>>s_m;
		fin>>s_n;
		//cin>>m;
		//cin>>n;
		//cout<<"m: "<<m<<"  n: "<<n<<endl;
		
		
		if(s_m=="I"&& s_n== "I")
		{
			fout<<" "<<endl;
		//	cout<<" "<<endl;
		}
		else
		{
			m = atoi(s_m.c_str());
			n = atoi(s_n.c_str());
			if(m==1&&n==1) break;
			while(true)
			{
				//cout<<"2��° while"<<endl;
				if(m == tmp_m && n == tmp_n)
				{
			//		cout<<endl;
					fout<<endl;
					break;
				}
				
				if(m * tmp_n > n * tmp_m)//go right
				{
					left_m = tmp_m;
					left_n = tmp_n;
					tmp_m = left_m + right_m;
					tmp_n = left_n + right_n;
					fout<<"R";
				//	cout<<"R";
				}
				else
				{
					right_m = tmp_m;
					right_n = tmp_n;
					tmp_m = left_m + right_m;
					tmp_n = left_n + right_n;
					fout<<"L";
				//	cout<<"L";
				}
			}		
		}

		///////////////////////
		//cout<<"fraction[1][1]: "<<fraction[1][1].m<<"/"<<fraction[1][1].n<<endl;
	/*	
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
				
				if(j%2==0)//¦����� ó�� �������� �����~  
				{
					LR=1;//ó�� �������� ��� ������ �������� ����ΰ��� ���ϸ����~ 
				}
				else
				{
					LR=0;
				}
				god = i-1;
				duf = (j+1)/2;			
				while(true)
				{
	
					if(duf%2 == LR)//0�̸� ¦���ϱ� ���� 1�̸� Ȧ�� �ϱ� ������					
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
	*/
	
	}
	fout.close();
	fin.close();
}

