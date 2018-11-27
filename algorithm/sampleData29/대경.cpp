#include <stdio.h>

typedef struct JOB{
   int index;
   int income;
   int time;
   int flag;
   float unit_time;
}job;

int Max_Income;

job * job_input;

void sort(int count);
int inputData();
void job_funtion(int count);

void sort(int count){
   int i, j;
   job temp;
   
   for(i = 1; i<count; i++){
      temp = job_input[i];
      j = i;
      
      while((j>0) && job_input[j-1].unit_time<temp.unit_time){
         job_input[j] = job_input[j-1];
         j = j-1;   
      }

      job_input[j] = temp;
   }

  // printf("\n\n");
   for(i = 0; i<count; i++){
    //  printf("%d %d %d %f\n", job_input[i].index, job_input[i].income, job_input[i].time, job_input[i].unit_time);
   }
}

void sort_return(int count){
   int i, j;
   job temp;
   
   for(i = 1; i<count; i++){
      temp = job_input[i];
      j = i;
      
      while((j>0) && job_input[j-1].index>temp.index){
         job_input[j] = job_input[j-1];
         j = j-1;   
      }

      job_input[j] = temp;
   }
/*
   printf("\n\n");
   for(i = 0; i<count; i++){
      printf("%d %d %d %f\n", job_input[i].index, job_input[i].income, job_input[i].time, job_input[i].unit_time);
   }
   */
}

int inputData(){
   FILE * fp1;
   int i;
   int count;

   fp1 = fopen("freelancer.inp", "r");
   
   fscanf(fp1, "%d %d\n", &count, &Max_Income);
 //  printf("count : %d, Max_Input : %d\n", count, Max_Income);

   job_input = new job[count];
   
   for(i = 0; i<count; i++){
      fscanf(fp1, "%d %d\n", &job_input[i].income, &job_input[i].time);
      job_input[i].unit_time = (float)job_input[i].income / (float)job_input[i].time;
      job_input[i].index = i+1;
      job_input[i].flag = 0;
   }

/*
   for(i = 0; i<count; i++){
      printf("%d %d %d %f\n", job_input[i].index, job_input[i].income, job_input[i].time, job_input[i].unit_time);
   }
*/
   sort(count);
   
   return count;
}

int job_funtion(int count, int sum, int time, int index){
   int i;

   for(i = index; i<count; i++){
      if(sum > Max_Income){
         break;
      }
      else if(sum == Max_Income){
         break;
      }
      else{   
         sum = sum + job_input[i].income;
         time = time + job_input[i].time;
         //job_input[i].flag = 1;
         job_funtion(count, sum, time, i+1);
        printf("index : %d sum : %d\n", i, sum);
      }
   }

  // printf("sum : %d, time : %d\n", sum, time);
/*
   sort_return(count);

   for(i = 0; i<10; i++){
      if(job_input[i].flag == 0)
         printf("0 ");
      else
         printf("1 ");
   }
   printf("\n");
   */
   return sum;
}

int main(){
   int count;
   count = inputData();
   job_funtion(count, 0, 0, 0);
   return 0;
}
