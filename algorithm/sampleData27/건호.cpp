#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int INF = 10e8 + 777;

class PAIR
{
	public:
		int a;
		int b;

		PAIR(int a_, int b_) : a(a_), b(b_) {}
		bool operator <(PAIR &W);
		bool operator >(PAIR &W);
};

bool PAIR::operator<(PAIR &W)
{
	if (this->a < W.a)
		return true;
	else if (this->a == W.a && this->b < W.b)
		return true;
	else
		return false;
}

bool PAIR::operator>(PAIR &W) 
{
	if (this->a > W.a)
		return true;
	else if (this->a == W.a && this->b > W.b)
		return true;
	else
		return false;
}

ifstream fin;
ofstream fout;

vector<PAIR> n, nn;


int main()
{
	fin.open("light.inp");
	fout.open("light.out");

	n.push_back(PAIR(-INF, -INF));
	// 데이터를 입력받자
	int N, K, a, b, MAX = 0;
	fin >> N;
	for (int i = 0; i < N; i++)
	{
		fin >> a >> b;
		n.push_back(PAIR(a, b));
		if (MAX < b) MAX = b;
	}

	// 오름차순으로 정렬해주자
	sort(n.begin(), n.end());




	int idx, max, select, cnt;
	fin >> K;
	while(K--)
	{
		cnt = 0;
		nn = n;
		fin >> a >> b;
		while (true)
		{
			max = 0; select = -1;

			for (int j = 1; ; j++)
			{
				if (nn[j].a > a) break;
				if (max < nn[j].b)
				{
					max = nn[j].b;
					select = j;
				}
			}

			if (select == -1 || a == nn[select].b || MAX < b)
			{
				fout << -1 << endl;
				cout << -1 << endl;
				break;
			}


			a = nn[select].b;
			cnt++;
			
			if (a >= b)
			{
				fout << cnt << endl;
				cout << cnt << endl; 
				break;
			}
		}
	}
	



	return 0;
}
