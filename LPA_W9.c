#include <stdio.h>
#include <stdlib.h>

int num_cars;
int carros_array[500000][4];

int compare(const void *val_a, const void *val_b ){
    
    const int *a = val_a;
    const int *b = val_b;

    if (a[2] < b[2]) 
        return -1;

    return (b[2] < a[2]);

}

int main(int argc, char const *argv[]){

	scanf("%d",&num_cars);

	int i = 0;
	
	for(i = 0; i < num_cars; i++){

		scanf("%d %d %d",&carros_array[i][0],&carros_array[i][1],&carros_array[i][2]);

		carros_array[i][3] = 1;

	}

	qsort(carros_array, num_cars,sizeof(int)*4, compare);

	int j = 0;

	for(i = 0; i < num_cars; i++){
		
		for(j = i+1; j < num_cars; j++){
			
			if(carros_array[i][0] < carros_array[j][0] && carros_array[i][1] < carros_array[j][1] && carros_array[i][2] < carros_array[j][2]){

				carros_array[i][3] = 0;
				break;

			}

		}

	}
	

	for(i = num_cars; i > -1; i--){
		
		if(carros_array[i][3] == 1) printf("%d %d %d\n",carros_array[i][0],carros_array[i][1],carros_array[i][2]);

	}

	return 0;
}