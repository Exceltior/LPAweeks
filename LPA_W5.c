#include <stdio.h>
#include <stdlib.h>

int sizeof_batch;
int processing_time;
int num_pair_shoes;
int total_time;

int sortfunc (const void * a, const void * b){ return ( *(int*)a - *(int*)b ); }

int arrive_time[1000];
int array_temp[1000];

void calculate(){
    
    int i, pos = 0;
    int flag = 1, counter = 0, dif = 0;

    qsort(arrive_time, num_pair_shoes, sizeof(int), sortfunc);
    
    for(i = num_pair_shoes - 1; i > -1; i--){
        
        if(counter == sizeof_batch){
            flag = 1;
            counter = 0;
        }
        
        if(flag == 1){
            array_temp[pos] = arrive_time[i];
            pos++;
            flag = 0;
        }

        counter++;

    }
    
    total_time = array_temp[pos-1];
    
    for(i = pos-1; i > -1; i--){
        
        if(i != 0){

            dif = array_temp[i-1] - (total_time + (2 * processing_time));
            if(dif < 0) dif = 0;
            total_time += dif + (2 * processing_time);
            
        }
        else if(i == 0) total_time += processing_time;
 
    }

}

int main(){
    
    int i;
    
    while(scanf("%d %d %d", &sizeof_batch, &num_pair_shoes, &processing_time) > 0){
        
        for(i = 0; i < num_pair_shoes; i++) scanf("%d", &arrive_time[i]);
        
        calculate();

    	printf("%d\n",total_time);
        
    }
    
    return 0;

}

