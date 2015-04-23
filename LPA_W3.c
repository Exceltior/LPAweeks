#include <stdio.h>

int t_cases;
int i, j, cont;
int max_points;

void recursiva(int array_teste[], int points, int temp, int ini, int fim, int eliminados){

	int y, z, cont = 0, new_temp = temp-eliminados;
	int new_array[new_temp], new_check[new_temp];

	if(new_temp > 1){

		for(y = 0; y < temp; y++){
			if(y<ini || y>fim){
				new_array[cont] = array_teste[y];

				if(cont != 0 && new_array[cont-1] == new_array[cont]){
					new_check[cont-1] = 1;
					new_check[cont] = 1;
				}
				else if(cont != 0){
					new_check[cont-1] = 0;
					new_check[cont] = 0;
				}
				cont++;
			}
		}

		for(z = 0; z < new_temp; z++){

			cont = 1;

			if(new_check[z] == 1){

				while(1){

					if(new_array[z+cont] == new_array[z] && (z+cont) < new_temp){

						if(cont == 1) new_check[z] = 0;
						new_check[z+cont] = 0;
						cont++;

					}
					else break;

				}

				recursiva(new_array, points+(cont*(cont+1)), new_temp, z, (z+(cont-1)), cont);

				z += (cont-1);

			}

		}

	}

	if(points>max_points) max_points = points;

}

int main(){

	scanf("%d", &t_cases);

	for(i = 0; i < t_cases; i++){

		int temp;
		scanf("%d", &temp);
		int array_teste[temp];
		int array_check[temp];

		for(j = 0; j < temp; j++){
			scanf("%d", &array_teste[j]);
			if(array_teste[j-1] == array_teste[j] && j != 0) array_check[j-1] = 1;
		}

		for(j = 0; j < temp; j++){

			cont = 1;

			if(array_check[j] == 1){

				while(1){

					if(array_teste[j+cont] == array_teste[j]){

						if(cont == 1) array_check[j] = 0;
						array_check[j+cont] = 0;
						cont++;

					}
					else break;

				}

				recursiva(array_teste, cont*(cont+1), temp, j, j+(cont-1), cont);

				j += (cont-1);

			}

		}

		if(max_points == 2) max_points = 0;

		printf("%d\n", max_points);

		max_points = 0;

	}

	return 0;

}

