#include <stdio.h>
#include <string.h>

int neighbours, min_inf;
int pop[1000][2], infectar[1000][1000], matrix[1000][1000];
int infected = 0, weeks = 1;

void espalha_virus(){
    
    /*****************************************************************
     * vou infectar a população x                                    *
     * se o meu vizinho não tiver a população infectada vou infectar *
     *****************************************************************/
    
    int i = 0, j, pos, x;
    
    while(infectar[i][0] != 0){                                        /*percorre infectar até não haver mais bairros para infectar*/
        
        pos = 0;
        for(j = 0; infectar[i][j] != 0; j++){                              /*vai percorrer cada linha até não haver mais bairros*/
            
            if(pop[infectar[i][j]][1] != -1){ /*se o bairro não foi infectado, infecta e soma população*/

                pop[infectar[i][j]][1] = -1;
                infected += pop[infectar[i][j]-1][0];
                
                if(infected >= min_inf)                                       /*se a população já chegou ao limite para*/
                    return;
                
                for(x = 0; matrix[infectar[i][j]-1][x] != 0; x++){
                   
                    infectar[i+1][pos] = matrix[infectar[i][j]-1][x]; /*mete vizinhos na próxima semana*/
                    pos++;

                }
                
            }
        }
        
        weeks++;
        i++;

    }
    
}

int main() {
    
    int i, j, n_vizinhos, temp;
    
    while(scanf("%d %d",&neighbours,&min_inf)==2){
        
        memset(pop, 0, sizeof(pop[0][0]) * 1000 * 2);
        memset(matrix, 0, sizeof(matrix[0][0]) * 1000 * 1000);
        memset(infectar, 0, sizeof(infectar)); /*mudar esta merda*/
        
        for(i = 0; i < neighbours; i++){

            scanf("%d %d", &pop[i][0], &n_vizinhos);
            
            for(j = 0; j < n_vizinhos; j++){
                scanf("%d ", &temp);
                matrix[i][j] = temp + 1; /*incementa valor para não dar erro com os 0s da matrix*/
            }
            
        }
        
        infectar[0][0] = 1;
        
        espalha_virus();
        
        if(infected >= min_inf)
            printf("%d\n", weeks);
        else
            printf("Safe!\n");

        weeks = 1;
        infected = 0;

    }

    return 0;

}
