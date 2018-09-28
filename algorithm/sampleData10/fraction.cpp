#include<iostream>
#include<fstream>

using namespace std;
int god,duf;//god=За duf=ї­ 
long long int m,n;
long long int m1,n1;
long long int left_m,left_n;
long long int right_m,right_n;
long long int tmp_m,tmp_n;

int main(void)
{
	 // m/n
	ifstream fin;
	ofstream fout;
	fin.open("fraction.inp");
	fout.open("fraction.out");
	while(true)
	{
		
		fin>>m;
		fin>>n;
		left_m=0;
		left_n=1;
		right_m=1;
		right_n=0;
		tmp_m=1;
		tmp_n=1;

			if(m==1&&n==1)
			{
				break;
			}
			else
			{		
				while(true)
				{
					//	cout<<"m: "<<m<<" n: "<<n<<endl;
					if(m == tmp_m && n == tmp_n)
					{
					//	cout<<endl;
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
						//cout<<"R";
					}
					else
					{
						right_m = tmp_m;
						right_n = tmp_n;
						tmp_m = left_m + right_m;
						tmp_n = left_n + right_n;
						fout<<"L";
						//cout<<"L";
					}
				}
			}		
	}
	fout.close();
	fin.close();
}

