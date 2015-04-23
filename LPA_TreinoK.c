#include <stdio.h>

int i, n_pizzas;
double total, best_dif;

double min(double a, double b){
	if(a > b) return b;
	else if(b > a) return a;
	else return a;
}

double recursiva(double array_pizzas[], int index, double soma_1, double soma_2){
	

	if(index >= n_pizzas){
		if(soma_1 > soma_2){
			if(soma_1 - soma_2 < best_dif) best_dif = soma_1 - soma_2;
			return soma_1 - soma_2;
		} 
		else if(soma_2 > soma_1){
			if(soma_2 - soma_1 < best_dif) best_dif = soma_2 - soma_1;
			return soma_2 - soma_1;
		} 
		else return 0.0;
	} 
	else{
		double temp = recursiva(array_pizzas, index+1, soma_1+array_pizzas[index], soma_2);
		double temp2 = recursiva(array_pizzas, index+1, soma_1, soma_2+array_pizzas[index]);
		return min(temp, temp2);
	}

}

int main(){

	while(scanf("%d", &n_pizzas) != EOF){

		best_dif = 1000000.0;

		double array_pizzas[n_pizzas];

		for(i = 0; i < n_pizzas; i++){
			scanf("%lf", &array_pizzas[i]);
			total += array_pizzas[i];
		}

		recursiva(array_pizzas, 1, array_pizzas[0], 0.0);
		printf("%.2f\n", best_dif);

	}

	return 0;

}