#include <stdio.h>
#include <string.h>

int num_rows, num_columns;

int kadane_algorithm(int array[]){

    int best = 0, best_temp = 0;
    int i;

    for(i = 0; i < num_columns; i++){

        best_temp = best_temp + array[i];

        if(best < best_temp) best = best_temp;
        if(best_temp < 0) best_temp = 0;

    }

    return best;

}

int find_best(int array[num_rows][num_columns]){

	int temp[num_columns];
    int max_sum = 0;
    int x, y, i;
 
    for(x = 0; x < num_rows; x++){

        memset(temp, 0, num_columns*sizeof(int));
 
        for (y = x; y < num_rows; y++){

            for (i = 0; i < num_columns; i++)
                temp[i] += array[y][i];

            int sum = kadane_algorithm(temp);
 
            if (sum > max_sum)
                max_sum = sum;

        }

    }
 
    return max_sum;

}

int main(){

	int i, j, best;
	
	scanf("%d %d", &num_rows, &num_columns);

	if(num_columns > num_rows){

		int array[num_rows][num_columns];

		for(i = 0; i < num_rows; i++){
			for(j = 0; j < num_columns; j++){
				scanf("%d", &array[i][j]);
			}
		}

		best = find_best(array);

	}
	else{
		
		int array[num_columns][num_rows];

		for(i = 0; i < num_rows; i++){
			for(j = 0; j < num_columns; j++){
				scanf("%d", &array[j][i]);
			}
		}

		int aux = num_columns;
		num_columns = num_rows;
		num_rows = aux;

		best = find_best(array);

	}

	printf("%d\n", best);

	return 0;

}


