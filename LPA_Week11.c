#include <stdlib.h>
#include <stdio.h>
#include <string.h>                 

int num_streets, num_intercept;             
int adj[600][600], visited[600], path[600];                      
int queue[600], queue_front, queue_end;                                                      

int bfs(){

    int i, j;

    memset(visited, 0, num_intercept*sizeof(int));    
    
    queue_front = 0;                    
    queue_end = 1;
    visited[0] = 1;               
    path[0] = -1;

    while(queue_front != queue_end){         
    
        i = queue[queue_front];     
        queue_front++;                         

        for(j = 0; j < num_intercept; j++){
        
            if(visited[j] == 0 && adj[i][j] > 0){  
            
                queue[queue_end] = j;         
                queue_end++;
                path[j] = i;           
                visited[j] = 1;          

            }

        }

    }
    
    if(visited[num_intercept-1] == 1) return 1;            
    else return 0;
    

}

int main(int argc, char* argv[]){

    int max;
    int x, y;
    int i, j; 

    scanf("%d %d", &num_streets, &num_intercept);

    for(i = 0; i < num_streets; i++){

        scanf("%d %d", &x, &y);
        
        adj[x-1][y-1] ++;
        adj[y-1][x-1] ++;

    }

    while(bfs() == 1){
        
        for(i = num_intercept-1; i != 0; i = path[i]){
        
            j = path[i];

            adj[j][i] --;
            adj[i][j] ++;

        }

        max++;

    }

    printf("%d\n", max);

    return 0;

}

