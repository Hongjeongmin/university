#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef struct
{
	int k;
	long long int cost;
	unsigned long long int cnt;
	string path;
}dp;

typedef struct
{
	int right;
	int down;
	vector<dp> k;
	bool isK;
}maps;

const int INF = 300012345;

vector< vector<maps> > map; // 전체 맵

ifstream fin;
ofstream fout;
int M, N, K;

void algo();

int main()
{
	fin.open("path.inp");
	fout.open("out1.out");

	int T, C;
	fin >> T;
	C = T;
	while (T--)
	{
		fout << "Test Case No:" << C - T << endl;
		fin >> M >> N >> K;
		// 벡터 초기화
		map.assign(M, vector<maps>(N, maps()));
		// K 좌표 받기
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				map[i][j].isK = false;

		int m, n;
		for (int i = 0; i < K; i++)
		{
			fin >> m >> n;
			map[m][n].isK = true;
		}
		// 가로 코스트 받기
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N - 1; j++)
				fin >> map[i][j].right;

		// 세로 코스트 받기
		for (int i = 0; i < M - 1; i++)
			for (int j = 0; j < N; j++)
				fin >> map[i][j].down;

		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				map[i][j].k.push_back({ 0,INF,0,"" });

		map[0][0].k[0].cost = 0;

		// K별로 카운트 세기
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				// i나 j가 0일 때 처리 ( 가장 위나 왼쪽 )
				if (i == 0 || j == 0)
				{
					if (j > 0)
						if (map[i][j].k.size() < map[i][j - 1].k.size())
							while (map[i][j].k.size() < map[i][j - 1].k.size())
								map[i][j].k.push_back({ 0,INF,0,"" });
					
					if (i > 0)
						if (map[i][j].k.size() < map[i - 1][j].k.size())
							while (map[i][j].k.size() < map[i - 1][j].k.size())
								map[i][j].k.push_back({ 0,INF,0,"" });

					for (int kk = 0; kk < map[i][j].k.size() - 1; kk++)
						map[i][j].k[kk].cnt = 0;

					map[i][j].k[map[i][j].k.size() - 1].cnt = 1;

					if (map[i][j].isK)
					{
						map[i][j].k.push_back({ 0,INF,1,"" });
						map[i][j].k[map[i][j].k.size() - 2].cnt = 0;
					}
						
				}
				else // 그 외
				{
					if (map[i][j].k.size() < map[i][j - 1].k.size())
						while (map[i][j].k.size() < map[i][j - 1].k.size())
							map[i][j].k.push_back({ 0,INF,0,"" });

					if (map[i][j].k.size() < map[i - 1][j].k.size())
						while (map[i][j].k.size() < map[i - 1][j].k.size())
							map[i][j].k.push_back({ 0,INF,0,"" });
					
					/*
					//각 k패스 별 경로 갯수 배열 복사
					for (int k = 0; k <= temp_K; k++)
					{
						if (corner[i - 1][j].path_Many[k] == 0 && corner[i][j - 1].path_Many[k] == 0)
							continue;

						if ((corner[i - 1][j].path_Many[k] + corner[i][j - 1].path_Many[k]) % 1000000 == 0)
							corner[i][j].path_Many[k] = 100000;
						else
							corner[i][j].path_Many[k] = (corner[i - 1][j].path_Many[k] + corner[i][j - 1].path_Many[k]) % 1000000;

					}
					int MIN = min(map[i][j - 1].k.size(), map[i - 1][j].k.size());
					for (int m = 0; m < MIN; m++)
					{
						if (map[i - 1][j].k[m].cnt == 0 && map[i][j - 1].k[m].cnt == 0)
							continue;

						if ((map[i - 1][j].k[m].cnt + map[i][j - 1].k[m].cnt) % 1000000 == 0)
							map[i][j].k[m].cnt = 100000;
						else
							map[i][j].k[m].cnt = (map[i - 1][j].k[m].cnt + map[i][j - 1].k[m].cnt) % 1000000;
					}
					*/
					for (int kk = 0; kk < map[i - 1][j].k.size(); kk++)
					{
						if (map[i - 1][j].k[kk].cnt == 0)
							continue;

						if ((map[i - 1][j].k[kk].cnt + map[i][j].k[kk].cnt) % 1000000 == 0)
							map[i][j].k[kk].cnt = 100000;
						else
							map[i][j].k[kk].cnt = (map[i][j].k[kk].cnt + map[i - 1][j].k[kk].cnt) % 1000000;
					}

					for (int kk = 0; kk < map[i][j - 1].k.size(); kk++)
					{
						if (map[i][j - 1].k[kk].cnt == 0)
							continue;

						if ((map[i][j - 1].k[kk].cnt + map[i][j].k[kk].cnt) % 1000000 == 0)
							map[i][j].k[kk].cnt = 100000;
						else
							map[i][j].k[kk].cnt = (map[i][j].k[kk].cnt + map[i][j - 1].k[kk].cnt) % 1000000;
					}

					
					

					if (map[i][j].isK)
					{
						map[i][j].k.push_back({ 0,INF,0,"" });

						for (int kk = map[i][j].k.size() - 1; kk > 0; kk--)
						{
							map[i][j].k[kk].cnt = map[i][j].k[kk - 1].cnt;
						}
						
						map[i][j].k[0].cnt = 0;
					}
					
				}
			}
		}


		/*
		int maxK = map[M - 1][N - 1].k.size() - 1;
		std::cout << maxK << endl;
		*/
		
		// 경로 및 최소비용 ㄱㄱ
		algo();
		/*
		for(int q=0;q<map[M-1][N-1].k.size();q++)
		{
			cout<<"K: "<<q<<endl;
			for(int w=0;w<M;w++)
			{
				for(int e=0;e<N;e++)
				{
					cout<<map[w][e].k[q].cost<<" ";
				}
				cout<<endl;
			}
		}
		*/	
		/*
		for (int i = 0; i < map[M - 1][N - 1].k.size(); i++)
			std::cout << map[M - 1][N - 1].k[i].cost << endl;

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				std::cout << map[i][j].k.size() - 1 << " : (";
				for (int kk = 0; kk < map[i][j].k.size() - 1; kk++)
					std::cout << " " << map[i][j].k[kk].cnt;
				std::cout << " )\t";
			}
			std::cout << endl;
		}
		*/
		for (int i = 0; i < map[M - 1][N - 1].k.size(); i++)
		{
			unsigned long long int temp = map[M - 1][N - 1].k[i].cnt;
			int idx = 0;
			if (temp != 0 && temp % 100000 != 0)
			{
				fout << "k:" << i << " count:" << map[M - 1][N - 1].k[i].cnt % 100000 << " cost:" << map[M - 1][N - 1].k[i].cost << endl;
				int x = 0, y = 0;
				for (int j = 0; j < map[M - 1][N - 1].k[i].path.size(); j++)
				{
					fout << "(" << x << "," << y << ")";
					if (j != map[M - 1][N - 1].k[i].path.size() - 1)
					{
						fout << "->";
					}
					switch (map[M - 1][N - 1].k[i].path[j])
					{
						case 'r':
							y++;
							break;
						case 'd':
							x++;
							break;
					}
				}
				fout << "->(" << M - 1 << "," << N - 1 << ")" << endl;
			}
		}
		fout << endl;

		for (int i = 0; i < map.size(); i++)
			map[i].clear();
		map.clear();
	}

	fin.close();
	fout.close();
	return 0;
}

void algo()
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == M - 1 && j == N - 2)
			{
				if (map[i][j + 1].k[map[i][j].k.size() - 1].cost > map[i][j].k[map[i][j].k.size() - 1].cost + map[i][j].right)
				{
					map[i][j + 1].k[map[i][j].k.size() - 1].cost = map[i][j].k[map[i][j].k.size() - 1].cost + map[i][j].right;
					map[i][j + 1].k[map[i][j].k.size() - 1].path = map[i][j].k[map[i][j].k.size() - 1].path + "r";
				}
				else if (map[i][j + 1].k[map[i][j].k.size() - 1].cost == map[i][j].k[map[i][j].k.size() - 1].cost + map[i][j].right)
				{
					for (int m = 0; m < map[i][j + 1].k[map[i][j].k.size() - 1].path.size(); m++)
					{
						if (map[i][j].k[map[i][j].k.size() - 1].path[m] == 'd' &&
							map[i][j + 1].k[map[i][j].k.size() - 1].path[m] == 'r')
						{
							map[i][j + 1].k[map[i][j].k.size() - 1].path = map[i][j].k[map[i][j].k.size() - 1].path + "r";
							break;
						}
					}
				}
				for (int m = 0; m < map[i][j].k.size() - 1; m++)
				{
					if (map[i][j + 1].k[m].cost > map[i][j].k[m].cost + map[i][j].right)
					{
						map[i][j + 1].k[m].cost = map[i][j].k[m].cost + map[i][j].right;
						map[i][j + 1].k[m].path = map[i][j].k[m].path + "r";
					}
					else if (map[i][j + 1].k[m].cost == map[i][j].k[m].cost + map[i][j].right)
					{
						for (int n = 0; n < map[i][j + 1].k[m].path.size(); n++)
						{
							if (map[i][j].k[m].path[n] == 'd' &&
								map[i][j + 1].k[m].path[n] == 'r')
							{
								map[i][j + 1].k[m].path = map[i][j].k[m].path + "r";
								break;
							}
						}
					}
				}
			}
			// 오른쪽 검색
			else if (j < N - 1)// && (i != M - 1 && j != N - 2))
			{
				if (map[i][j + 1].isK)
				{
					// 코스트와 경로를 담자
					if (map[i][j + 1].k[map[i][j].k.size()].cost >= map[i][j].k[map[i][j].k.size() - 1].cost + map[i][j].right)
					{
						map[i][j + 1].k[map[i][j].k.size()].cost = map[i][j].k[map[i][j].k.size() - 1].cost + map[i][j].right;
						map[i][j + 1].k[map[i][j].k.size()].path = map[i][j].k[map[i][j].k.size() - 1].path + "r";
					}
					else if (map[i][j + 1].k[map[i][j].k.size()].cost == map[i][j].k[map[i][j].k.size() - 1].cost + map[i][j].right)
					{
						for (int m = 0; m < map[i][j + 1].k[map[i][j].k.size()].path.size(); m++)
						{
							if (map[i][j].k[map[i][j].k.size() - 1].path[m] == 'd' &&
								map[i][j + 1].k[map[i][j].k.size()].path[m] == 'r')
							{
								map[i][j + 1].k[map[i][j].k.size()].path = map[i][j].k[map[i][j].k.size() - 1].path + "r";
								break;
							}
						}
					}
					for (int m = 1; m <= map[i][j].k.size() - 1; m++)
					{
						if (map[i][j + 1].k[m].cost > map[i][j].k[m - 1].cost + map[i][j].right)
						{
							map[i][j + 1].k[m].cost = map[i][j].k[m - 1].cost + map[i][j].right;
							map[i][j + 1].k[m].path = map[i][j].k[m - 1].path + "r";
						}
						else if (map[i][j + 1].k[m].cost == map[i][j].k[m - 1].cost + map[i][j].right)
						{
							for (int n = 0; n < map[i][j + 1].k[m].path.size(); n++)
							{
								if (map[i][j].k[m - 1].path[n] == 'd' &&
									map[i][j + 1].k[m].path[n] == 'r')
								{
									map[i][j + 1].k[m].path = map[i][j].k[m - 1].path + "r";
									break;
								}
							}
						}
					}
				}
				else
				{
					if (map[i][j + 1].k[map[i][j].k.size() - 1].cost >= map[i][j].k[map[i][j].k.size() - 1].cost + map[i][j].right)
					{
						map[i][j + 1].k[map[i][j].k.size() - 1].cost = map[i][j].k[map[i][j].k.size() - 1].cost + map[i][j].right;
						map[i][j + 1].k[map[i][j].k.size() - 1].path = map[i][j].k[map[i][j].k.size() - 1].path + "r";
					}
					else if (map[i][j + 1].k[map[i][j].k.size() - 1].cost == map[i][j].k[map[i][j].k.size() - 1].cost + map[i][j].right)
					{
						for (int m = 0; m < map[i][j + 1].k[map[i][j].k.size() - 1].path.size(); m++)
						{
							if (map[i][j].k[map[i][j].k.size() - 1].path[m] == 'd' &&
								map[i][j + 1].k[map[i][j].k.size() - 1].path[m] == 'r')
							{
								map[i][j + 1].k[map[i][j].k.size() - 1].path = map[i][j].k[map[i][j].k.size() - 1].path + "r";
								break;
							}
						}
					}
					// 코스트와 경로를 담자
					for (int m = 0; m < map[i][j].k.size() - 1; m++)
					{
						if (map[i][j + 1].k[m].cost > map[i][j].k[m].cost + map[i][j].right)
						{
							map[i][j + 1].k[m].cost = map[i][j].k[m].cost + map[i][j].right;
							map[i][j + 1].k[m].path = map[i][j].k[m].path + "r";
						}
						else if (map[i][j + 1].k[m].cost == map[i][j].k[m].cost + map[i][j].right)
						{
							for (int n = 0; n < map[i][j + 1].k[m].path.size(); n++)
							{
								if (map[i][j].k[m].path[n] == 'd' &&
									map[i][j + 1].k[m].path[n] == 'r')
								{
									map[i][j + 1].k[m].path = map[i][j].k[m].path + "r";
									break;
								}
							}
						}
					}
				}
			}
			
			// 아래쪽 검색
			if (i < M - 1)
			{
				if (map[i + 1][j].isK)
				{
					// 코스트와 경로를 담자
					if (map[i + 1][j].k[map[i][j].k.size()].cost > map[i][j].k[map[i][j].k.size() - 1].cost + map[i][j].down)
					{
						map[i + 1][j].k[map[i][j].k.size()].cost = map[i][j].k[map[i][j].k.size() - 1].cost + map[i][j].down;
						map[i + 1][j].k[map[i][j].k.size()].path = map[i][j].k[map[i][j].k.size() - 1].path + "d";
					}
					for (int m = 1; m <= map[i][j].k.size() - 1; m++)
					{
						if (map[i + 1][j].k[m].cost > map[i][j].k[m - 1].cost + map[i][j].down)
						{
							map[i + 1][j].k[m].cost = map[i][j].k[m - 1].cost + map[i][j].down;
							map[i + 1][j].k[m].path = map[i][j].k[m - 1].path + "d";
						}
					}
				}
				else
				{
					// 코스트와 경로를 담자
					for (int m = 0; m <= map[i][j].k.size() - 1; m++)
					{
						if (map[i + 1][j].k[m].cost > map[i][j].k[m].cost + map[i][j].down)
						{
							map[i + 1][j].k[m].cost = map[i][j].k[m].cost + map[i][j].down;
							map[i + 1][j].k[m].path = map[i][j].k[m].path + "d";
						}
					}
				}
			}
		}
	}
}

