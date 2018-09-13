#include<iostream>
#include<fstream>
using namespace std;

int main(void)
{
	ifstream fin;
	ofstream fout;
	char p1[6];
	char p2[6];
	char a[4];
	char b[4];
	char tmp[6];
	int cnt=0;
	int tr;
	int r=0;
	int i=0;
	int j=0;
	
	fin.open("cube.inp");
	fout.open("cube.out");
	while(true)
	{
		//r++;
		//cout<<"R:"<<r<<endl;
		tr=0;
		for(i=0;i<6;i++)
		{
			fin>>p1[i];
		}
		if(fin.eof()==true) break;		
		a[0]=p1[1];a[1]=p1[3];a[2]=p1[4];a[3]=p1[2];
		for(i=0;i<6;i++)
		{
			fin>>p2[i];
		}

		
		if(p1[0]==p2[0]&&p1[5]==p2[5]&&tr==0)
		{
			//cout<<"case1"<<endl;
			b[0]=p2[1];b[1]=p2[3];b[2]=p2[4];b[3]=p2[2];
			for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
				{
					if(a[(i+j)%4]==b[j])
					{
						//cout<<"cnt++"<<endl;
						cnt++;
					}
					else
					{
						cnt=0;
						break;
					}
				}
				if(cnt==4)
				{
					cnt=0;
				//	cout<<"cnt4!!!"<<endl;
					tr=1;
					break;
				}
			}
		}
		if(p1[0]==p2[1]&&p1[5]==p2[4]&&tr==0)
		{
		//	cout<<"case2"<<endl;
			b[0]=p2[3];b[1]=p2[0];b[2]=p2[2];b[3]=p2[5];
			for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
				{
					if(a[(i+j)%4]==b[j])
					{
						cnt++;
					}
					else
					{
						cnt=0;
						break;
					}
				}
				if(cnt==4)
				{
					cnt=0;
				//	cout<<"cnt4!!!"<<endl;
					tr=1;
					break;
				}
			}			
		}
		if(p1[0]==p2[2]&&p1[5]==p2[3]&&tr==0)
		{
		//	cout<<"case3"<<endl;
			b[0]=p2[5];b[1]=p2[1];b[2]=p2[0];b[3]=p2[4];
			for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
				{
					if(a[(i+j)%4]==b[j])
					{
						cnt++;
					}
					else
					{
						cnt=0;
						break;
					}
				}
				if(cnt==4)
				{
					cnt=0;
				//	cout<<"cnt4!!!"<<endl;
					tr=1;
					break;
				}
			}
		}
		if(p1[0]==p2[5]&&p1[5]==p2[0]&&tr==0)
		{
		//	cout<<"case4"<<endl;
			b[0]=p2[2];b[1]=p2[4];b[2]=p2[3];b[3]=p2[1];
			for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
				{
					if(a[(i+j)%4]==b[j])
					{
						cnt++;
					}
					else
					{
						cnt=0;
						break;
					}
				}
				if(cnt==4)
				{
					cnt=0;
				//	cout<<"cnt4!!!"<<endl;
					tr=1;
					break;
				}
			}
		}
		if(p1[0]==p2[4]&&p1[5]==p2[1]&&tr==0)
		{
			//cout<<"case5"<<endl;
			b[0]=p2[5];b[1]=p2[2];b[2]=p2[0];b[3]=p2[3];
			for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
				{
					if(a[(i+j)%4]==b[j])
					{
						cnt++;
					}
					else
					{
						cnt=0;
						break;
					}
				}
				if(cnt==4)
				{
					cnt=0;
				//	cout<<"cnt4!!!"<<endl;
					tr=1;
					break;
				}
			}
		}
		if(p1[0]==p2[3]&&p1[5]==p2[2]&&tr==0)
		{
		//	cout<<"case6"<<endl;
			b[0]=p2[4];b[1]=p2[0];b[2]=p2[1];b[3]=p2[5];
			for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
				{
					if(a[(i+j)%4]==b[j])
					{
						cnt++;
					}
					else
					{
						cnt=0;
						break;
					}
				}
				if(cnt==4)
				{
					cnt=0;
				//	cout<<"cnt4!!!"<<endl;
					tr=1;
					break;
				}
			}
		}
		
		if(tr==1)
		{
			fout<<"TRUE"<<endl;		
		}		
		else
		{
			fout<<"FALSE"<<endl;
		}
		
	}
	fin.close();
	fout.close();
	return 0;
	
}
