#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<fstream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>

#define inf 999999

using namespace std;
ifstream fin;
ofstream fout;

FILE *in, *out;

typedef struct Query
{
   int go_floor;
   int up_cost;
   int down_cost;

}query;

query qu[501];

typedef struct DP_node
{
   int sum;
   int query_cost[501];

}node;

node dp[201][201];

void take_Value(int n);
void make_DP(int n, int k);

int max_floor;

int main()
{
   //elevator.inp
   //elevator.out
   //D:/hwin.txt
   //D:/hwout.txt
   in = fopen("test.inp", "rt");
   out = fopen("elevator.out", "wt");

   int T, n, k;

   fscanf(in, "%d\n", &T);
   while (T--)
   {
      fscanf(in, "%d %d", &n, &k);
      take_Value(n);
      make_DP(n, k);
   }

   fclose(in);
   fclose(out);

   return 0;
}

void take_Value(int n)
{
   max_floor = 0;

   for (int i = 1; i <= n; i++)
   {
      fscanf(in, "%d %d %d", &qu[i].go_floor, &qu[i].down_cost, &qu[i].up_cost);

      if (qu[i].go_floor > max_floor)
         max_floor = qu[i].go_floor;

   }

}

void make_DP(int n, int k)
{
   for (int i = 0; i <= k; i++)
   {
      for (int j = 1; j <= max_floor; j++)
      {
         if (i == 0 && j == 1)//1행 0열 --> 1층 선택값
         {
            for (int k = 1; k <= n; k++)
            {
               dp[j][i].query_cost[k] = qu[k].up_cost * (qu[k].go_floor - 1);
               dp[j][i].sum += dp[j][i].query_cost[k];
          //     cout<<"dp[1][0].sum: "<<dp[j][i].sum<<endl;
            }

         }
         else if (i == 0 || j == 1)//초기 1행, 0열 --> 1층 선택값 복사
         {
            copy(dp[1][0].query_cost, dp[1][0].query_cost + n + 1, dp[j][i].query_cost);
            dp[j][i].sum = dp[1][0].sum;
         }
         else if (i == j - 1)//대각선 --> 무조건 한층 추가
         {
            int t_min = 0;

            for (int k = 1; k <= n; k++)
            {
               if (j < qu[k].go_floor)
               {
                  t_min = min(dp[j - 1][i - 1].query_cost[k], qu[k].up_cost * (qu[k].go_floor - j));
               }
               else if (j > qu[k].go_floor)
               {
                  t_min = min(dp[j - 1][i - 1].query_cost[k], qu[k].down_cost *(j - qu[k].go_floor));
               }
               else
                  t_min = 0;

               dp[j][i].query_cost[k] = t_min;
               dp[j][i].sum += t_min;
            }


         }
         else if (i >= j) // 층수보다 K값이 더 큰 경우
         {
            copy(dp[j][j - 1].query_cost, dp[j][j - 1].query_cost + n + 1, dp[j][i].query_cost);
            dp[j][i].sum = dp[j][j - 1].sum;
         }
         else
         {
            //바로 윗행의 배열을 복사할지, 
            //옆 열의 최솟값 + 해당 j 선택 감안한 값을 복사할지
            //더 작은 값 선택
            int t_max = dp[j - 1][i].sum;
            node temp_dp;

            int temp_num;

            //윗행에서 가져옴(윗 행 넣어 놓고 시작)
            dp[j][i].sum = dp[j - 1][i].sum;
            copy(dp[j - 1][i].query_cost, dp[j - 1][i].query_cost + n + 1, dp[j][i].query_cost);
            

            //옆에서 고르는 갯수
            for (int left = 1; left < j; left++)
            {

               int t_min = 0;

               temp_dp.sum = 0;

               for (int k = 1; k <= n; k++)
               {

                  if (j < qu[k].go_floor)
                  {
                     t_min = min(dp[left][i - 1].query_cost[k], qu[k].up_cost * (qu[k].go_floor - j));
                  }
                  else if (j > qu[k].go_floor)
                  {
                     t_min = min(dp[left][i - 1].query_cost[k], qu[k].down_cost *(j - qu[k].go_floor));
                  }
                  else
                     t_min = 0;

                  temp_dp.query_cost[k] = t_min;
                  temp_dp.sum += t_min;


               }

               if (t_max > temp_dp.sum)
               {
                  t_max = temp_dp.sum;

                  dp[j][i].sum = t_max;
                  copy(temp_dp.query_cost, temp_dp.query_cost + n + 1, dp[j][i].query_cost);

               }

               if (i == 1)
                  break;
            }

         }


      }//max floor
   }// k

	cout<<dp[max_floor][k].sum<<endl;
//	for(int q=0;q<=k;q++)
//	{
//		for(int w=1;w<=max_floor;w++)
//		{
//			cout<<dp[w][q].sum<<" ";
//		}
//		cout<<endl;
//	}
	
   fprintf(out, "%d\n", dp[max_floor][k].sum);

}
