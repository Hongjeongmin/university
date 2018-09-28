#include<iostream>
#include<fstream>
using namespace std;
int T;
long long int N;//column
long long int M;//width
long long int H;//height
class Volume//-1 is that there are no hole;
{
	public:
		int left=-1;
		int right=-1;
		int top=-1;
		int bottom=-1;
		int volume;
};


Volume volume[1002][1002];

void processing(int i,int j)
{
//---------------------------left case--------------------------	
	if(volume[i][j].volume>volume[i][j].left)
	{
		if(volume[i][j-1].volume <volume[i][j].left)
		{
			volume[i][j].volume = volume[i][j].left;
			processing(i+1,j);processing(i-1,j);processing(i,j+1);
		}
		else
		{
			if(volume[i][j].volume>volume[i][j-1].volume)
			{
				volume[i][j].volume = volume[i][j-1].volume;
				processing(i+1,j);processing(i-1,j);processing(i,j+1);
			}
		}
	}
//---------------------------right case--------------------------	
	if(volume[i][j].volume>volume[i][j].right)
	{
		if(volume[i][j+1].volume <volume[i][j].right)
		{
			volume[i][j].volume = volume[i][j].right;
			processing(i+1,j);processing(i-1,j);processing(i,j-1);
		}
		else
		{
			if(volume[i][j].volume>volume[i][j+1].volume)
			{
				volume[i][j].volume = volume[i][j+1].volume;
				processing(i+1,j);processing(i-1,j);processing(i,j-1);
			}
		}
	}	
//---------------------------top case--------------------------	
	if(volume[i][j].volume>volume[i][j].top)
	{
		if(volume[i-1][j].volume <volume[i][j].top)
		{
			volume[i][j].volume = volume[i][j].top;
			processing(i,j+1);processing(i,j-1);processing(i+1,j);
		}
		else
		{
			if(volume[i][j].volume>volume[i-1][j].volume)
			{
				volume[i][j].volume = volume[i-1][j].volume;
				processing(i,j+1);processing(i,j-1);processing(i+1,j);
			}
		}
	}
//---------------------------bottom case--------------------------	
	if(volume[i][j].volume>volume[i][j].bottom)
	{
		if(volume[i+1][j].volume <volume[i][j].bottom)
		{
			volume[i][j].volume = volume[i][j].bottom;
			processing(i,j+1);processing(i,j-1);processing(i-1,j);
		}
		else
		{
			if(volume[i][j].volume>volume[i+1][j].volume)
			{
				volume[i][j].volume = volume[i+1][j].volume;
				processing(i,j+1);processing(i,j-1);processing(i-1,j);
			}
		}
	}		
}
int main(void)
{
	int cnt;
	int w;
	ifstream fin;
	ofstream fout;
	
	fin.open("watertank.inp");
	fout.open("watertank.out");
	fin>> T;
	for(int i=1;i<=T;i++)
	{
		cnt=0;
		fin>>N;fin>>M;fin>>H; 
		for(int j=1;j<=N+1;j++)
		{
			for(int k=1;k<=M;k++)
			{
				fin>>volume[j-1][k].bottom;
				if(volume[j-1][k].bottom == -1)
				{
					volume[j-1][k].bottom=H;
				}
				volume[j][k].top = volume[j-1][k].bottom; 
			}
		}
		
		for(int j=1;j<=N;j++)
		{
			for(int k=1;k<=M+1;k++)
			{
				fin>>volume[j][k-1].right;
				if(volume[j][k-1].right==-1)
				{
					volume[j][k-1].right=H;
				}
				volume[j][k].left = volume[j][k-1].right;
			}
		}
		
		
		
		for(int j=1;j<=N;j++)
		{
			for(int k=1;k<=M;k++)
			{
				volume[j][k].volume = H;
			}
		}
	
//----------------------------------------------------------

		
//----------------------------------data handling----------
		if(volume[1][1].top<volume[1][1].left)
		{
			volume[1][1].volume = volume[1][1].top;
		}
		else
		{
			volume[1][1].volume = volume[1][1].left;
		}
		
		if(volume[1][M].top<volume[1][M].right)
		{
			volume[1][M].volume = volume[1][M].top;
		}
		else
		{
			volume[1][M].volume = volume[1][M].right;
		}
		
		if(volume[N][1].bottom<volume[N][1].left)
		{
			volume[N][1].volume = volume[N][1].bottom;
		}
		else
		{
			volume[N][1].volume = volume[N][1].left;
		}
		
		if(volume[N][M].bottom<volume[N][M].right)
		{
			volume[N][M].volume = volume[N][M].bottom;
		}
		else
		{
			volume[N][M].volume = volume[N][M].right;
		}				
		
		for(int j=2;j<=M-1;j++)
		{
			volume[1][j].volume = volume[1][j].top;
		}
		for(int j=2;j<=M-1;j++)
		{
			volume[N][j].volume = volume[N][j].bottom;
		}		
		for(int j=2;j<=N-1;j++)
		{
			volume[j][1].volume = volume[j][1].left;
		}
		for(int j=2;j<=N-1;j++)
		{
			volume[j][M].volume = volume[j][M].right;
		}				
//---------------------------------------------------------
		 
/////////////여기 재귀적으로 다시 짜야함. 
		//cout<<"processing after"<<endl;
		
		/*
		if(N>M)
		{
			w=N/4;
		}
		else
		{
			w=M/4;
		}
		*/
		for(int w=1;w<=150;w++)
		{
			for(int j=1;j<=N;j++)
			{
				for(int k=1;k<=M;k++)
				{
					processing(j,k);
				}
			}			
		}		


		
														
		/*
		for(int j=1;j<=N;j++)
		{
			for(int k=1;k<=M;k++)
			{
				cout<<volume[j][k].top<<endl;
				cout<<volume[j][k].bottom<<endl;
				cout<<volume[j][k].left<<endl;
				cout<<volume[j][k].right<<endl;
				cout<<volume[j][k].volume<<endl;
				cout<<"----------------------"<<endl;
			}
		}			
		cout<<"----------------------"<<endl;
		cout<<"----------------------"<<endl;
		*/
		
		
		for(int j=1;j<=N;j++)
		{
			for(int k=1;k<=M;k++)
			{
				cnt =cnt + volume[j][k].volume;
			}
		}
		
		cout<<cnt<<endl;
		fout<<cnt<<endl;
		
	}
	
}
