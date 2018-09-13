#include<iostream>
#include<fstream>
using namespace std;
class Go
{
	public:
		char s;
		int c=-2; // 0:white Aria 1:blace Aria -1:empty -2:unkown 3:W 4:B
};
int main()
{
	int k;
	int cnt_B=0;
	int cnt_W=0;
	ifstream fin;
	ofstream fout;
	fin.open("go.inp");
	fout.open("go.out");
	fin>>k;
	Go **go = new Go*[k+2];
	for(int i=0;i<k+2;i++)
	{
		go[i] = new Go[k+2];
	}
	///////////////////////////////
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			fin>>go[i][j].s;
			if(go[i][j].s=='B')
			{
				go[i][j].c=4;	
			}
			else if(go[i][j].s=='W')
			{
				go[i][j].c=3;
			}
		}
	}
	fin.close();
///////////////////////////////////////////////////////////////////////	
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(go[i][j].s=='W')
			{
				if(go[i][j-1].c==-2)
				{
					go[i][j-1].c=0;
				}
				else if(go[i][j-1].c==1)
				{
					go[i][j-1].c=-1;
				}

				if(go[i-1][j].c==-2)
				{
					go[i-1][j].c=0;
				}
				else if(go[i-1][j].c==1)
				{
					go[i-1][j].c=-1;
				}

				if(go[i+1][j].c==-2)
				{
					go[i+1][j].c=0;
				}
				else if(go[i+1][j].c==1)
				{
					go[i+1][j].c=-1;
				}	
				
				if(go[i][j+1].c==-2)
				{
					go[i][j+1].c=0;
				}
				else if(go[i][j+1].c==1)
				{
					go[i][j+1].c=-1;
				}
															
			}
			else if(go[i][j].s=='B')
			{
				if(go[i][j-1].c==-2)
				{
					go[i][j-1].c=1;
				}
				else if(go[i][j-1].c==0)
				{
					go[i][j-1].c=-1;
				}

				if(go[i-1][j].c==-2)
				{
					go[i-1][j].c=1;
				}
				else if(go[i-1][j].c==0)
				{
					go[i-1][j].c=-1;
				}

				if(go[i+1][j].c==-2)
				{
					go[i+1][j].c=1;
				}
				else if(go[i+1][j].c==0)
				{
					go[i+1][j].c=-1;
				}	
				
				if(go[i][j+1].c==-2)
				{
					go[i][j+1].c=1;
				}
				else if(go[i][j+1].c==0)
				{
					go[i][j+1].c=-1;
				}				
			}
		}
	}
	for(int i=k;i>=1;i--)
	{
		for(int j=k;j>=1;j--)
		{
			if(go[i][j].s=='W')
			{
				if(go[i][j-1].c==-2)
				{
					go[i][j-1].c=0;
				}
				else if(go[i][j-1].c==1)
				{
					go[i][j-1].c=-1;
				}

				if(go[i-1][j].c==-2)
				{
					go[i-1][j].c=0;
				}
				else if(go[i-1][j].c==1)
				{
					go[i-1][j].c=-1;
				}

				if(go[i+1][j].c==-2)
				{
					go[i+1][j].c=0;
				}
				else if(go[i+1][j].c==1)
				{
					go[i+1][j].c=-1;
				}	
				
				if(go[i][j+1].c==-2)
				{
					go[i][j+1].c=0;
				}
				else if(go[i][j+1].c==1)
				{
					go[i][j+1].c=-1;
				}
															
			}
			else if(go[i][j].s=='B')
			{
				if(go[i][j-1].c==-2)
				{
					go[i][j-1].c=1;
				}
				else if(go[i][j-1].c==0)
				{
					go[i][j-1].c=-1;
				}

				if(go[i-1][j].c==-2)
				{
					go[i-1][j].c=1;
				}
				else if(go[i-1][j].c==0)
				{
					go[i-1][j].c=-1;
				}

				if(go[i+1][j].c==-2)
				{
					go[i+1][j].c=1;
				}
				else if(go[i+1][j].c==0)
				{
					go[i+1][j].c=-1;
				}	
				
				if(go[i][j+1].c==-2)
				{
					go[i][j+1].c=1;
				}
				else if(go[i][j+1].c==0)
				{
					go[i][j+1].c=-1;
				}				
			}
		}
	}
	for(int i=k;i>=1;i--)
	{
		for(int j=1;j<=k;j++)
		{
			if(go[i][j].s=='W')
			{
				if(go[i][j-1].c==-2)
				{
					go[i][j-1].c=0;
				}
				else if(go[i][j-1].c==1)
				{
					go[i][j-1].c=-1;
				}

				if(go[i-1][j].c==-2)
				{
					go[i-1][j].c=0;
				}
				else if(go[i-1][j].c==1)
				{
					go[i-1][j].c=-1;
				}

				if(go[i+1][j].c==-2)
				{
					go[i+1][j].c=0;
				}
				else if(go[i+1][j].c==1)
				{
					go[i+1][j].c=-1;
				}	
				
				if(go[i][j+1].c==-2)
				{
					go[i][j+1].c=0;
				}
				else if(go[i][j+1].c==1)
				{
					go[i][j+1].c=-1;
				}
															
			}
			else if(go[i][j].s=='B')
			{
				if(go[i][j-1].c==-2)
				{
					go[i][j-1].c=1;
				}
				else if(go[i][j-1].c==0)
				{
					go[i][j-1].c=-1;
				}

				if(go[i-1][j].c==-2)
				{
					go[i-1][j].c=1;
				}
				else if(go[i-1][j].c==0)
				{
					go[i-1][j].c=-1;
				}

				if(go[i+1][j].c==-2)
				{
					go[i+1][j].c=1;
				}
				else if(go[i+1][j].c==0)
				{
					go[i+1][j].c=-1;
				}	
				
				if(go[i][j+1].c==-2)
				{
					go[i][j+1].c=1;
				}
				else if(go[i][j+1].c==0)
				{
					go[i][j+1].c=-1;
				}				
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=k;j>=1;j--)
		{
			if(go[i][j].s=='W')
			{
				if(go[i][j-1].c==-2)
				{
					go[i][j-1].c=0;
				}
				else if(go[i][j-1].c==1)
				{
					go[i][j-1].c=-1;
				}

				if(go[i-1][j].c==-2)
				{
					go[i-1][j].c=0;
				}
				else if(go[i-1][j].c==1)
				{
					go[i-1][j].c=-1;
				}

				if(go[i+1][j].c==-2)
				{
					go[i+1][j].c=0;
				}
				else if(go[i+1][j].c==1)
				{
					go[i+1][j].c=-1;
				}	
				
				if(go[i][j+1].c==-2)
				{
					go[i][j+1].c=0;
				}
				else if(go[i][j+1].c==1)
				{
					go[i][j+1].c=-1;
				}
															
			}
			else if(go[i][j].s=='B')
			{
				if(go[i][j-1].c==-2)
				{
					go[i][j-1].c=1;
				}
				else if(go[i][j-1].c==0)
				{
					go[i][j-1].c=-1;
				}

				if(go[i-1][j].c==-2)
				{
					go[i-1][j].c=1;
				}
				else if(go[i-1][j].c==0)
				{
					go[i-1][j].c=-1;
				}

				if(go[i+1][j].c==-2)
				{
					go[i+1][j].c=1;
				}
				else if(go[i+1][j].c==0)
				{
					go[i+1][j].c=-1;
				}	
				
				if(go[i][j+1].c==-2)
				{
					go[i][j+1].c=1;
				}
				else if(go[i][j+1].c==0)
				{
					go[i][j+1].c=-1;
				}				
			}
		}
	}			
/////////////////////////////////////////////////////////////////////
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(go[i][j].c==0)
			{
				if(go[i-1][j].c==1)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==1)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==1)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==1)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}								
			}
			else if(go[i][j].c==1)
			{
				if(go[i-1][j].c==0)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==0)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==0)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==0)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}					
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=k;j>=1;j--)
		{
			if(go[i][j].c==0)
			{
				if(go[i-1][j].c==1)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==1)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==1)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==1)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}								
			}
			else if(go[i][j].c==1)
			{
				if(go[i-1][j].c==0)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==0)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==0)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==0)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}					
			}
		}
	}
	for(int i=k;i>=1;i--)
	{
		for(int j=1;j<=k;j++)
		{
			if(go[i][j].c==0)
			{
				if(go[i-1][j].c==1)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==1)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==1)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==1)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}								
			}
			else if(go[i][j].c==1)
			{
				if(go[i-1][j].c==0)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==0)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==0)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==0)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}					
			}
		}
	}	
	for(int i=k;i>=1;i--)
	{
		for(int j=k;j>=1;j--)
		{
			if(go[i][j].c==0)
			{
				if(go[i-1][j].c==1)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==1)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==1)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==1)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}								
			}
			else if(go[i][j].c==1)
			{
				if(go[i-1][j].c==0)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==0)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==0)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==0)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}					
			}
		}
	}
	for(int j=1;j<=k;j++)
	{
		for(int i=1;i<=k;i++)
		{
			if(go[i][j].c==0)
			{
				if(go[i-1][j].c==1)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==1)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==1)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==1)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}								
			}
			else if(go[i][j].c==1)
			{
				if(go[i-1][j].c==0)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==0)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==0)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==0)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}					
			}
		}
	}
	for(int j=1;j<=k;j++)
	{
		for(int i=k;i>=1;i--)
		{
			if(go[i][j].c==0)
			{
				if(go[i-1][j].c==1)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==1)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==1)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==1)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}								
			}
			else if(go[i][j].c==1)
			{
				if(go[i-1][j].c==0)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==0)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==0)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==0)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}					
			}
		}
	}
	for(int j=k;j>=1;j--)
	{
		for(int i=1;i<=k;i++)
		{
			if(go[i][j].c==0)
			{
				if(go[i-1][j].c==1)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==1)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==1)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==1)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}								
			}
			else if(go[i][j].c==1)
			{
				if(go[i-1][j].c==0)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==0)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==0)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==0)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}					
			}
		}
	}	
	for(int j=k;j>=1;j--)
	{
		for(int i=k;i>=1;i--)
		{
			if(go[i][j].c==0)
			{
				if(go[i-1][j].c==1)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==1)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==1)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==1)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}								
			}
			else if(go[i][j].c==1)
			{
				if(go[i-1][j].c==0)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==0)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==0)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==0)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}					
			}
		}
	}			
/////////////////////////////////////////////////////////////////////
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(go[i][j].c==-1)
			{
				if(!(go[i-1][j].c==3||go[i-1][j].c==4))
				{
					go[i-1][j].c=-1;
				}
				if(!(go[i][j-1].c==3||go[i][j-1].c==4))
				{
					go[i][j-1].c=-1;
				}
				if(!(go[i+1][j].c==3||go[i+1][j].c==4))
				{
					go[i+1][j].c=-1;
				}
				if(!(go[i][j+1].c==3||go[i][j+1].c==4))
				{
					go[i][j+1].c=-1;
				}												
			}
		}
	}
	for(int i=k;i>=1;i--)
	{
		for(int j=k;j>=1;j--)
		{
			if(go[i][j].c==-1)
			{
				if(!(go[i-1][j].c==3||go[i-1][j].c==4))
				{
					go[i-1][j].c=-1;
				}
				if(!(go[i][j-1].c==3||go[i][j-1].c==4))
				{
					go[i][j-1].c=-1;
				}
				if(!(go[i+1][j].c==3||go[i+1][j].c==4))
				{
					go[i+1][j].c=-1;
				}
				if(!(go[i][j+1].c==3||go[i][j+1].c==4))
				{
					go[i][j+1].c=-1;
				}												
			}
		}
	}
	for(int i=k;i>=1;i--)
	{
		for(int j=1;j<=k;j++)
		{
			if(go[i][j].c==-1)
			{
				if(!(go[i-1][j].c==3||go[i-1][j].c==4))
				{
					go[i-1][j].c=-1;
				}
				if(!(go[i][j-1].c==3||go[i][j-1].c==4))
				{
					go[i][j-1].c=-1;
				}
				if(!(go[i+1][j].c==3||go[i+1][j].c==4))
				{
					go[i+1][j].c=-1;
				}
				if(!(go[i][j+1].c==3||go[i][j+1].c==4))
				{
					go[i][j+1].c=-1;
				}												
			}
		}
	}
	for(int i=k;i<=1;i++)
	{
		for(int j=1;j>=1;j--)
		{
			if(go[i][j].c==-1)
			{
				if(!(go[i-1][j].c==3||go[i-1][j].c==4))
				{
					go[i-1][j].c=-1;
				}
				if(!(go[i][j-1].c==3||go[i][j-1].c==4))
				{
					go[i][j-1].c=-1;
				}
				if(!(go[i+1][j].c==3||go[i+1][j].c==4))
				{
					go[i+1][j].c=-1;
				}
				if(!(go[i][j+1].c==3||go[i][j+1].c==4))
				{
					go[i][j+1].c=-1;
				}												
			}
		}
	}
	for(int j=1;j<=k;j++)
	{
		for(int i=1;i<=k;i++)
		{
			if(go[i][j].c==-1)
			{
				if(!(go[i-1][j].c==3||go[i-1][j].c==4))
				{
					go[i-1][j].c=-1;
				}
				if(!(go[i][j-1].c==3||go[i][j-1].c==4))
				{
					go[i][j-1].c=-1;
				}
				if(!(go[i+1][j].c==3||go[i+1][j].c==4))
				{
					go[i+1][j].c=-1;
				}
				if(!(go[i][j+1].c==3||go[i][j+1].c==4))
				{
					go[i][j+1].c=-1;
				}												
			}
		}
	}	
////////////////////////////////////////////////
	
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(go[i][j].c==0) // white Area
			{
				if(go[i-1][j].c==-2)
				{
					go[i-1][j].c = 0;
				}
				if(go[i+1][j].c==-2)
				{
					go[i+1][j].c = 0;
				}
				if(go[i][j-1].c==-2)
				{
					go[i][j-1].c = 0;
				}
				if(go[i][j+1].c==-2)
				{
					go[i][j+1].c = 0;
				}												
			}
			else if(go[i][j].c==1) // Black Area
			{
				if(go[i-1][j].c==-2)
				{
					go[i-1][j].c = 1;
				}
				if(go[i+1][j].c==-2)
				{
					go[i+1][j].c = 1;
				}
				if(go[i][j-1].c==-2)
				{
					go[i][j-1].c = 1;
				}
				if(go[i][j+1].c==-2)
				{
					go[i][j+1].c = 1;
				}					
			}
		}
	}
	for(int i=k;i>=1;i--)
	{
		for(int j=k;j>=1;j--)
		{
			if(go[i][j].c==0) // white Area
			{
				if(go[i-1][j].c==-2)
				{
					go[i-1][j].c = 0;
				}
				if(go[i+1][j].c==-2)
				{
					go[i+1][j].c = 0;
				}
				if(go[i][j-1].c==-2)
				{
					go[i][j-1].c = 0;
				}
				if(go[i][j+1].c==-2)
				{
					go[i][j+1].c = 0;
				}												
			}
			else if(go[i][j].c==1) // Black Area
			{
				if(go[i-1][j].c==-2)
				{
					go[i-1][j].c = 1;
				}
				if(go[i+1][j].c==-2)
				{
					go[i+1][j].c = 1;
				}
				if(go[i][j-1].c==-2)
				{
					go[i][j-1].c = 1;
				}
				if(go[i][j+1].c==-2)
				{
					go[i][j+1].c = 1;
				}					
			}
		}
	}	
///////////////////////////////////////////////////////////
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(go[i][j].c==0)
			{
				if(go[i-1][j].c==1)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==1)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==1)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==1)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}								
			}
			else if(go[i][j].c==1)
			{
				if(go[i-1][j].c==0)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==0)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==0)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==0)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}					
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=k;j>=1;j--)
		{
			if(go[i][j].c==0)
			{
				if(go[i-1][j].c==1)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==1)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==1)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==1)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}								
			}
			else if(go[i][j].c==1)
			{
				if(go[i-1][j].c==0)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==0)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==0)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==0)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}					
			}
		}
	}
	for(int i=k;i>=1;i--)
	{
		for(int j=1;j<=k;j++)
		{
			if(go[i][j].c==0)
			{
				if(go[i-1][j].c==1)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==1)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==1)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==1)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}								
			}
			else if(go[i][j].c==1)
			{
				if(go[i-1][j].c==0)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==0)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==0)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==0)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}					
			}
		}
	}	
	for(int i=k;i>=1;i--)
	{
		for(int j=k;j>=1;j--)
		{
			if(go[i][j].c==0)
			{
				if(go[i-1][j].c==1)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==1)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==1)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==1)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}								
			}
			else if(go[i][j].c==1)
			{
				if(go[i-1][j].c==0)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==0)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==0)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==0)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}					
			}
		}
	}
	for(int j=1;j<=k;j++)
	{
		for(int i=1;i<=k;i++)
		{
			if(go[i][j].c==0)
			{
				if(go[i-1][j].c==1)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==1)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==1)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==1)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}								
			}
			else if(go[i][j].c==1)
			{
				if(go[i-1][j].c==0)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==0)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==0)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==0)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}					
			}
		}
	}
	for(int j=1;j<=k;j++)
	{
		for(int i=k;i>=1;i--)
		{
			if(go[i][j].c==0)
			{
				if(go[i-1][j].c==1)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==1)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==1)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==1)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}								
			}
			else if(go[i][j].c==1)
			{
				if(go[i-1][j].c==0)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==0)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==0)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==0)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}					
			}
		}
	}
	for(int j=k;j>=1;j--)
	{
		for(int i=1;i<=k;i++)
		{
			if(go[i][j].c==0)
			{
				if(go[i-1][j].c==1)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==1)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==1)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==1)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}								
			}
			else if(go[i][j].c==1)
			{
				if(go[i-1][j].c==0)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==0)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==0)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==0)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}					
			}
		}
	}	
	for(int j=k;j>=1;j--)
	{
		for(int i=k;i>=1;i--)
		{
			if(go[i][j].c==0)
			{
				if(go[i-1][j].c==1)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==1)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==1)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==1)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}								
			}
			else if(go[i][j].c==1)
			{
				if(go[i-1][j].c==0)
				{
					go[i-1][j].c=-1;
					go[i][j].c=-1;
				}
				if(go[i+1][j].c==0)
				{
					go[i+1][j].c=-1;
					go[i][j].c=-1;
				}				
				if(go[i][j-1].c==0)
				{
					go[i][j-1].c=-1;
					go[i][j].c=-1;
				}
				if(go[i][j+1].c==0)
				{
					go[i][j+1].c=-1;
					go[i][j].c=-1;
				}					
			}
		}
	}
//////////////////////////////////////////////////////////
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(go[i][j].c==-1)
			{
				if(!(go[i-1][j].c==3||go[i-1][j].c==4))
				{
					go[i-1][j].c=-1;
				}
				if(!(go[i][j-1].c==3||go[i][j-1].c==4))
				{
					go[i][j-1].c=-1;
				}
				if(!(go[i+1][j].c==3||go[i+1][j].c==4))
				{
					go[i+1][j].c=-1;
				}
				if(!(go[i][j+1].c==3||go[i][j+1].c==4))
				{
					go[i][j+1].c=-1;
				}												
			}
		}
	}
	for(int i=k;i>=1;i--)
	{
		for(int j=k;j>=1;j--)
		{
			if(go[i][j].c==-1)
			{
				if(!(go[i-1][j].c==3||go[i-1][j].c==4))
				{
					go[i-1][j].c=-1;
				}
				if(!(go[i][j-1].c==3||go[i][j-1].c==4))
				{
					go[i][j-1].c=-1;
				}
				if(!(go[i+1][j].c==3||go[i+1][j].c==4))
				{
					go[i+1][j].c=-1;
				}
				if(!(go[i][j+1].c==3||go[i][j+1].c==4))
				{
					go[i][j+1].c=-1;
				}												
			}
		}
	}
	for(int i=k;i>=1;i--)
	{
		for(int j=1;j<=k;j++)
		{
			if(go[i][j].c==-1)
			{
				if(!(go[i-1][j].c==3||go[i-1][j].c==4))
				{
					go[i-1][j].c=-1;
				}
				if(!(go[i][j-1].c==3||go[i][j-1].c==4))
				{
					go[i][j-1].c=-1;
				}
				if(!(go[i+1][j].c==3||go[i+1][j].c==4))
				{
					go[i+1][j].c=-1;
				}
				if(!(go[i][j+1].c==3||go[i][j+1].c==4))
				{
					go[i][j+1].c=-1;
				}												
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=k;j>=1;j--)
		{
			if(go[i][j].c==-1)
			{
				if(!(go[i-1][j].c==3||go[i-1][j].c==4))
				{
					go[i-1][j].c=-1;
				}
				if(!(go[i][j-1].c==3||go[i][j-1].c==4))
				{
					go[i][j-1].c=-1;
				}
				if(!(go[i+1][j].c==3||go[i+1][j].c==4))
				{
					go[i+1][j].c=-1;
				}
				if(!(go[i][j+1].c==3||go[i][j+1].c==4))
				{
					go[i][j+1].c=-1;
				}												
			}
		}
	}
	for(int j=1;j<=k;j++)
	{
		for(int i=1;i<=k;i++)
		{
			if(go[i][j].c==-1)
			{
				if(!(go[i-1][j].c==3||go[i-1][j].c==4))
				{
					go[i-1][j].c=-1;
				}
				if(!(go[i][j-1].c==3||go[i][j-1].c==4))
				{
					go[i][j-1].c=-1;
				}
				if(!(go[i+1][j].c==3||go[i+1][j].c==4))
				{
					go[i+1][j].c=-1;
				}
				if(!(go[i][j+1].c==3||go[i][j+1].c==4))
				{
					go[i][j+1].c=-1;
				}												
			}
		}
	}
	for(int j=k;j>=1;j--)
	{
		for(int i=k;i>=1;i--)
		{
			if(go[i][j].c==-1)
			{
				if(!(go[i-1][j].c==3||go[i-1][j].c==4))
				{
					go[i-1][j].c=-1;
				}
				if(!(go[i][j-1].c==3||go[i][j-1].c==4))
				{
					go[i][j-1].c=-1;
				}
				if(!(go[i+1][j].c==3||go[i+1][j].c==4))
				{
					go[i+1][j].c=-1;
				}
				if(!(go[i][j+1].c==3||go[i][j+1].c==4))
				{
					go[i][j+1].c=-1;
				}												
			}
		}
	}
	for(int j=k;j>=1;j--)
	{
		for(int i=1;i<=k;i++)
		{
			if(go[i][j].c==-1)
			{
				if(!(go[i-1][j].c==3||go[i-1][j].c==4))
				{
					go[i-1][j].c=-1;
				}
				if(!(go[i][j-1].c==3||go[i][j-1].c==4))
				{
					go[i][j-1].c=-1;
				}
				if(!(go[i+1][j].c==3||go[i+1][j].c==4))
				{
					go[i+1][j].c=-1;
				}
				if(!(go[i][j+1].c==3||go[i][j+1].c==4))
				{
					go[i][j+1].c=-1;
				}												
			}
		}
	}
	for(int j=1;j<=k;j++)
	{
		for(int i=k;i>=1;i--)
		{
			if(go[i][j].c==-1)
			{
				if(!(go[i-1][j].c==3||go[i-1][j].c==4))
				{
					go[i-1][j].c=-1;
				}
				if(!(go[i][j-1].c==3||go[i][j-1].c==4))
				{
					go[i][j-1].c=-1;
				}
				if(!(go[i+1][j].c==3||go[i+1][j].c==4))
				{
					go[i+1][j].c=-1;
				}
				if(!(go[i][j+1].c==3||go[i][j+1].c==4))
				{
					go[i][j+1].c=-1;
				}												
			}
		}
	}	

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			//cout<<go[i][j].c<<" ";
			if(go[i][j].c==0)
			{
				cnt_W++;
			}
			else if(go[i][j].c==1)
			{
				cnt_B++;
			}
		}
	//	cout<<endl;
	}
	
	fout<<cnt_B<<" "<<cnt_W<<endl;
	fout.close();
	
	

	
	
}
