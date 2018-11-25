#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#define INF 987654321
using namespace std;

class Lectangles
{
	public:
		int x;
		int y;
		int p;
		int q;
};
class Tree
{
	public:
		int left;
		int right;
		int max;
		bool exist;
};

bool XXX(const Lectangles& tmp1,const Lectangles& tmp2)
{
	if(tmp1.x != tmp2.x) return tmp1.x < tmp2.x;
	return tmp1.y<tmp2.y;
}
bool YYY(const Lectangles& tmp1,const Lectangles& tmp2)
{
	if(tmp1.y != tmp2.y) return tmp1.y<tmp2.y;
	return tmp1.x < tmp2.x;
}
Lectangles L[10001]; // Max of number of lectangle is 10,000
Tree treeY[50001];
Tree treeX[50001];
int Max_scaleX;
int Max_scaleY;
int x_size;
int y_size;
int N;
int WWW,HHH; // it is result of input data
int look_maxY(int left,int right,int location)// size 는 현재 쳐다보는  
{
	// look at the maxY in the segment_tree and store sgment_tree
	if(left<=treeY[location].left && right>=treeY[location].right)
	{
		return treeY[location].max;
	}
	else if(left>treeY[location].left && right<treeY[location].right && treeY[location].exist == false)
	{
		return treeY[location].max;
	}
	else if(left==treeY[location].left && right<treeY[location].right && treeY[location].exist == false)
	{
		return treeY[location].max;
	}
	else if(left>treeY[location].left && right==treeY[location].right && treeY[location].exist == false)
	{
		return treeY[location].max;
	}	
	else if(left>treeY[location].left && right<treeY[location].right && treeY[location].exist == true)
	{
		return max(look_maxY(left,right,location*2),look_maxY(left,right,location*2+1));
	}
	else if(left==treeY[location].left && right<treeY[location].right && treeY[location].exist == true)
	{
		return max(look_maxY(left,right,location*2),look_maxY(left,right,location*2+1));
	}
	else if(left>treeY[location].left && right==treeY[location].right && treeY[location].exist == true)
	{
		return max(look_maxY(left,right,location*2),look_maxY(left,right,location*2+1));
	}
	else if(left<treeY[location].left && right>treeY[location].left && right<treeY[location].right && treeY[location].exist== false)
	{
		return treeY[location].max;
	}
	else if(left>treeY[location].left && left<treeY[location].right && right>treeY[location].right && treeY[location].exist== false)	
	{
		return treeY[location].max;
	}
	else if(left<treeY[location].left && right>treeY[location].left && right<treeY[location].right && treeY[location].exist== true)
	{
		return max(look_maxY(left,right,location*2),look_maxY(left,right,location*2+1));
	}
	else if(left>treeY[location].left && left<treeY[location].right && right>treeY[location].right && treeY[location].exist== true)
	{
		return max(look_maxY(left,right,location*2),look_maxY(left,right,location*2+1));
	}
	
	return 0;
}

int look_maxX(int left,int right,int location)// size 는 현재 쳐다보는  
{
	// look at the maxY in the segment_tree and store sgment_tree
	if(left<=treeX[location].left && right>=treeX[location].right)
	{
		return treeX[location].max;
	}
	else if(left>treeX[location].left && right<treeX[location].right && treeX[location].exist == false)
	{
		return treeX[location].max;
	}
	else if(left==treeX[location].left && right<treeX[location].right && treeX[location].exist == false)
	{
		return treeX[location].max;
	}
	else if(left>treeX[location].left && right==treeX[location].right && treeX[location].exist == false)
	{
		return treeX[location].max;
	}	
	else if(left>treeX[location].left && right<treeX[location].right && treeX[location].exist == true)
	{
		return max(look_maxX(left,right,location*2),look_maxX(left,right,location*2+1));
	}
	else if(left==treeX[location].left && right<treeX[location].right && treeX[location].exist == true)
	{
		return max(look_maxX(left,right,location*2),look_maxX(left,right,location*2+1));
	}
	else if(left>treeX[location].left && right==treeX[location].right && treeX[location].exist == true)
	{
		return max(look_maxX(left,right,location*2),look_maxX(left,right,location*2+1));
	}
	else if(left<treeX[location].left && right>treeX[location].left && right<treeX[location].right && treeX[location].exist== false)
	{
		return treeX[location].max;
	}
	else if(left>treeX[location].left && left<treeX[location].right && right>treeX[location].right && treeX[location].exist== false)	
	{
		return treeX[location].max;
	}
	else if(left<treeX[location].left && right>treeX[location].left && right<treeX[location].right && treeX[location].exist== true)
	{
		return max(look_maxX(left,right,location*2),look_maxX(left,right,location*2+1));
	}
	else if(left>treeX[location].left && left<treeX[location].right && right>treeX[location].right && treeX[location].exist== true)
	{
		return max(look_maxX(left,right,location*2),look_maxX(left,right,location*2+1));
	}
	
	return 0;
}

void make_Ytree(int left,int right, int distance,int location)// left : 좌측 범위 , right : 우측 범위 , distance : 사각형의 높이 , location : 현재 노드 위치 
{		
	if(treeY[location].left<left && treeY[location].right > right && treeY[location].exist == false) // 범위 안에 들어오고 자식이 없을 때 
	{		
		
		treeY[location*2].left = treeY[location].left;
		treeY[location*2].right = left;
		treeY[location*2].max = treeY[location].max;
		treeY[location*2].exist = false;
		
		treeY[location*2+1].left = left;
		treeY[location*2+1].right = treeY[location].right;
		treeY[location*2+1].max = max(distance,treeY[location].max);
		treeY[location*2+1].exist = true;
		
		treeY[(location*2+1)*2].left = left;
		treeY[(location*2+1)*2].right = right;
		treeY[(location*2+1)*2].max = distance;
		treeY[(location*2+1)*2].exist = false;
		
		treeY[(location*2+1)*2+1].left = right;
		treeY[(location*2+1)*2+1].right = treeY[location].right;
		treeY[(location*2+1)*2+1].max = treeY[location].max;
		treeY[(location*2+1)*2+1].exist = false;		
			
		treeY[location].exist = true;// 자식을 만든다! 
		treeY[location].max = max(distance,treeY[location].max); // 큰값을 max값으로 반환!
	}
	else if(left == treeY[location].left && right < treeY[location].right && treeY[location].exist == false)//왼쪽에 걸쳐서 범위안에 들어올때 그리고 자식이 없을때 
	{
		treeY[location*2].left = left;
		treeY[location*2].right = right;
		treeY[location*2].max = distance;
		treeY[location*2].exist = false;
		
		treeY[location*2+1].left = right;
		treeY[location*2+1].right = treeY[location].right;
		treeY[location*2+1].max = treeY[location].max;
		treeY[location*2+1].exist = false;	
		
		treeY[location].exist = true;// 자식을 만든다! 
		treeY[location].max = max(distance,treeY[location].max); // 큰값을 max값으로 반환!
	}
	else if(left > treeY[location].left && right == treeY[location].right && treeY[location].exist == false)//오른쪽에 걸쳐서 범위안에 들어올때 그리고 자식이 없을때 
	{
		treeY[location*2].left = treeY[location].left;
		treeY[location*2].right = left;
		treeY[location*2].max = treeY[location].max;
		treeY[location*2].exist = false;
		
		treeY[location*2+1].left = left;
		treeY[location*2+1].right = right;
		treeY[location*2+1].max = distance;
		treeY[location*2+1].exist = false;	
		
		treeY[location].exist = true;// 자식을 만든다! 
		treeY[location].max = max(distance,treeY[location].max); // 큰값을 max값으로 반환!		
		
	}
	else if(treeY[location].left>=left && treeY[location].right<=right)// 범위 초과해서 있을 때 
	{
		treeY[location].max = distance;
		treeY[location].exist = false;	
	}
	else if(treeY[location].left<=left && treeY[location].right >= right && treeY[location].exist == true)// 범위 안에 있고 자식존재 
	{
		treeY[location].max = max(distance,treeY[location].max);
		make_Ytree(left,right,distance,location*2);
		make_Ytree(left,right,distance,location*2+1);
	}
	else if(left<treeY[location].left && right>treeY[location].left && right<treeY[location].right && treeY[location].exist== true) // 왼쪽 초과 오른쪽 겹침 자식존재 
	{
		treeY[location].max = max(distance,treeY[location].max);
		make_Ytree(treeY[location].left,right,distance,location*2);
		make_Ytree(treeY[location].left,right,distance,location*2+1);
	}
	else if(left>treeY[location].left && left<treeY[location].right && right>treeY[location].right && treeY[location].exist== true) // 오른쪽 초과 왼쪽 겹침 자식 존재 
	{
		treeY[location].max = max(distance,treeY[location].max);
		make_Ytree(left,treeY[location].right,distance,location*2);
		make_Ytree(left,treeY[location].right,distance,location*2+1);	
	}
	else if(left<treeY[location].left && right>treeY[location].left && right<treeY[location].right && treeY[location].exist== false)
	{
	//왼쪽은 초과하고 오른쪽은 겹쳐잇을때 자식이 없을경우 
		treeY[location*2].left = treeY[location].left;
		treeY[location*2].right = right;
		treeY[location*2].max = distance;
		treeY[location*2].exist = false;
		
		treeY[location*2+1].left = right;
		treeY[location*2+1].right = treeY[location].right;
		treeY[location*2+1].max = treeY[location].max;
		treeY[location*2+1].exist = false;
		
		treeY[location].exist=true;
		treeY[location].max = max(distance,treeY[location].max);
	}
	else if(left>treeY[location].left && left<treeY[location].right && right>treeY[location].right && treeY[location].exist== false)
	{
	//오른쪽은 초과하고 왼쪽은 겹처잇을때 자식이 없을 경우 
		treeY[location*2].left = treeY[location].left;
		treeY[location*2].right = left;
		treeY[location*2].max =treeY[location].max;
		treeY[location*2].exist = false;
		
		treeY[location*2+1].left = left;
		treeY[location*2+1].right = treeY[location].right;
		treeY[location*2+1].max = distance;
		treeY[location*2+1].exist = false;	
		
		treeY[location].exist=true;
		treeY[location].max = max(distance,treeY[location].max);
	}	
	//그이외에는 처리안합니다 ^^ 
}

void make_Xtree(int left,int right, int distance,int location)// left : 좌측 범위 , right : 우측 범위 , distance : 사각형의 높이 , location : 현재 노드 위치 
{		
	if(treeX[location].left<left && treeX[location].right > right && treeX[location].exist == false) // 범위 안에 들어오고 자식이 없을 때 
	{		
		
		treeX[location*2].left = treeX[location].left;
		treeX[location*2].right = left;
		treeX[location*2].max = treeX[location].max;
		treeX[location*2].exist = false;
		
		treeX[location*2+1].left = left;
		treeX[location*2+1].right = treeX[location].right;
		treeX[location*2+1].max = max(distance,treeX[location].max);
		treeX[location*2+1].exist = true;
		
		treeX[(location*2+1)*2].left = left;
		treeX[(location*2+1)*2].right = right;
		treeX[(location*2+1)*2].max = distance;
		treeX[(location*2+1)*2].exist = false;
		
		treeX[(location*2+1)*2+1].left = right;
		treeX[(location*2+1)*2+1].right = treeX[location].right;
		treeX[(location*2+1)*2+1].max = treeX[location].max;
		treeX[(location*2+1)*2+1].exist = false;		
			
		treeX[location].exist = true;// 자식을 만든다! 
		treeX[location].max = max(distance,treeX[location].max); // 큰값을 max값으로 반환!
	}
	else if(left == treeX[location].left && right < treeX[location].right && treeX[location].exist == false)//왼쪽에 걸쳐서 범위안에 들어올때 그리고 자식이 없을때 
	{
		treeX[location*2].left = left;
		treeX[location*2].right = right;
		treeX[location*2].max = distance;
		treeX[location*2].exist = false;
		
		treeX[location*2+1].left = right;
		treeX[location*2+1].right = treeX[location].right;
		treeX[location*2+1].max = treeX[location].max;
		treeX[location*2+1].exist = false;	
		
		treeX[location].exist = true;// 자식을 만든다! 
		treeX[location].max = max(distance,treeX[location].max); // 큰값을 max값으로 반환!
	}
	else if(left > treeX[location].left && right == treeX[location].right && treeX[location].exist == false)//오른쪽에 걸쳐서 범위안에 들어올때 그리고 자식이 없을때 
	{
		treeX[location*2].left = treeX[location].left;
		treeX[location*2].right = left;
		treeX[location*2].max = treeX[location].max;
		treeX[location*2].exist = false;
		
		treeX[location*2+1].left = left;
		treeX[location*2+1].right = right;
		treeX[location*2+1].max = distance;
		treeX[location*2+1].exist = false;	
		
		treeX[location].exist = true;// 자식을 만든다! 
		treeX[location].max = max(distance,treeX[location].max); // 큰값을 max값으로 반환!		
		
	}
	else if(treeX[location].left>=left && treeX[location].right<=right)// 범위 초과해서 있을 때 
	{
		treeX[location].max = distance;
		treeX[location].exist = false;	
	}
	else if(treeX[location].left<=left && treeX[location].right >= right && treeX[location].exist == true)// 범위 안에 있고 자식존재 
	{
		treeX[location].max = max(distance,treeX[location].max);
		make_Xtree(left,right,distance,location*2);
		make_Xtree(left,right,distance,location*2+1);
	}
	else if(left<treeX[location].left && right>treeX[location].left && right<treeX[location].right && treeX[location].exist== true) // 왼쪽 초과 오른쪽 겹침 자식존재 
	{
		treeX[location].max = max(distance,treeX[location].max);
		make_Xtree(treeX[location].left,right,distance,location*2);
		make_Xtree(treeX[location].left,right,distance,location*2+1);
	}
	else if(left>treeX[location].left && left<treeX[location].right && right>treeX[location].right && treeX[location].exist== true) // 오른쪽 초과 왼쪽 겹침 자식 존재 
	{
		treeX[location].max = max(distance,treeX[location].max);
		make_Xtree(left,treeX[location].right,distance,location*2);
		make_Xtree(left,treeX[location].right,distance,location*2+1);	
	}
	else if(left<treeX[location].left && right>treeX[location].left && right<treeX[location].right && treeX[location].exist== false)
	{
	//왼쪽은 초과하고 오른쪽은 겹쳐잇을때 자식이 없을경우 
		treeX[location*2].left = treeX[location].left;
		treeX[location*2].right = right;
		treeX[location*2].max = distance;
		treeX[location*2].exist = false;
		
		treeX[location*2+1].left = right;
		treeX[location*2+1].right = treeX[location].right;
		treeX[location*2+1].max = treeX[location].max;
		treeX[location*2+1].exist = false;
		
		treeX[location].exist=true;
		treeX[location].max = max(distance,treeX[location].max);
	}
	else if(left>treeX[location].left && left<treeX[location].right && right>treeX[location].right && treeX[location].exist== false)
	{
	//오른쪽은 초과하고 왼쪽은 겹처잇을때 자식이 없을 경우 
		treeX[location*2].left = treeX[location].left;
		treeX[location*2].right = left;
		treeX[location*2].max =treeX[location].max;
		treeX[location*2].exist = false;
		
		treeX[location*2+1].left = left;
		treeX[location*2+1].right = treeX[location].right;
		treeX[location*2+1].max = distance;
		treeX[location*2+1].exist = false;	
		
		treeX[location].exist=true;
		treeX[location].max = max(distance,treeX[location].max);
	}	
	//그이외에는 처리안합니다 ^^ 
}
//bool Optimization[10001];
void test()
{
	treeY[1].right = 1000;// 갱신 해줘야한다.
	treeY[1].max = 0;
	treeY[1].exist = false;
	int left=90;
	int right=100;
	int max_value;
	make_Ytree(0,1000,10,1);
	make_Ytree(100,200,20,1);
	make_Ytree(150,250,15,1);
//	make_Ytree(100,120,320,1);
//	make_Ytree(70,80,100,1);
	max_value = look_maxY(left,right,1);
	cout<<"결과: "<<max_value<<endl;
	int tmp=15;		
	cout<<"결과 "<<treeY[tmp].left <<" "<<treeY[tmp].right<<" "<<treeY[tmp].max<<" "<<treeY[tmp].exist<<endl;		
}
void Procedure()
{

	bool TR = true;
	int distance;
	int max_value;
	
	while(TR)
	{
		TR = false;
	//	cout<<"Max_scaleY:"<<Max_scaleY<<endl;
		treeY[1].right = Max_scaleY;// 갱신 해줘야한다.
		treeY[1].max = 0;
		treeY[1].exist = false;
				
		//lower shift
		
		sort(L,L+N,YYY);

		for(int i=0;i<N;i++)
		{
			max_value = look_maxY(L[i].x,L[i].p,1);//범위에서 제일큰값 반환하자 
		
			distance = L[i].q - L[i].y;
			make_Ytree(L[i].x,L[i].p,distance + max_value,1);
			
			if(L[i].y == max_value)	continue; // it is not fall 
			
			TR = true;
			L[i].y = max_value;
			L[i].q = max_value + distance;
		}
		
		Max_scaleY = treeY[1].max;
		//left shift 

		sort(L,L+N,XXX);
		
		treeX[1].right = Max_scaleX;// 갱신 해줘야한다. 
		treeX[1].max = 0;
		treeX[1].exist = false;		
	//	cout<<"Max_scaleX:"<<Max_scaleX<<endl;
		for(int i=0;i<N;i++)
		{
			max_value = look_maxX(L[i].y,L[i].q,1); //범위에서 제일큰값 반환하자
			
			distance = L[i].p - L[i].x;
			make_Xtree(L[i].y,L[i].q,distance + max_value,1);
			
			if(L[i].x == max_value) continue;
			
			TR = true;
			L[i].x = max_value;
			L[i].p = max_value + distance;
		}	
		Max_scaleX = treeX[1].max;
	}

}

int main(void)
{
	ifstream fin;
	ofstream fout;
	treeX[1].left = 0;
	treeY[1].left = 0;
	int T;
	int x,y;//lower-left vertex
	int p,q;//upeer-right vetex
	
	fin.open("block.inp");
	fout.open("block.out");
	
	fin>>T;
	
	for(int i=0;i<T;i++)
	{
		fin >> N; // number of lectangle
		Max_scaleX = 0;
		Max_scaleY = 0;
		for(int j=0;j<N;j++)
		{
			fin>>x;fin>>y; // Lower-left vertex
			fin>>p;fin>>q; // Upper-right vertex
			Max_scaleX = max(Max_scaleX,p);
			Max_scaleY = max(Max_scaleY,q);
			L[j].x = x;
			L[j].y = y;
			L[j].p = p;
			L[j].q = q;
		}
		Procedure();
		cout<< Max_scaleX << " " << Max_scaleY << endl;
		fout<< Max_scaleX << " " << Max_scaleY << endl;
			 
	}
	//test();
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
