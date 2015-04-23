#include <stdio.h>
#include <string.h>

int flip_right[] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 1, 2, 3, 4, 18, 19, 20, 17, 22, 23, 24, 21};
int flip_left[] = {13, 14, 15, 16, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 20, 17, 18, 19, 24, 21, 22, 23};
int flip_up[] = {21, 24, 23, 22, 6, 7, 8, 5, 19, 20, 17, 18, 16, 13, 14, 15, 1, 2, 3, 4, 11, 10, 9, 12};
int flip_down[] = {17, 18, 19, 20, 8, 5, 6, 7, 23, 22, 21, 24, 14, 15, 16, 13, 11, 12, 9, 10, 1, 4, 3, 2};
int spins_max;
int best_cont = 5;
char resposta[500] = "";

void recursiva(int a, int b, int c, int d, int cont, char current[], char answer[500]){

	char temp[500];
	strcpy(temp, answer);
	if(cont >  1){
		strcat(temp, " ");
	}
	strcat(temp, current);
	
	if(cont <= spins_max && (a != 1 || b != 1 || c != 1 || d != 1) && cont < best_cont 
			&& ((a != 6 && a != 16 && a != 19 && a != 21) 
			|| (b != 6 && b != 16 && b != 19 && b != 21) 
			|| (c != 6 && c != 16 && c != 19 && c != 21) 
			|| (d != 6 && d != 16 && d != 19 && d != 21))){

		cont = cont + 1;

		recursiva(flip_left[a-1], flip_left[b-1], c, d, cont, "L1", temp);
		recursiva(flip_right[a-1], flip_right[b-1], c, d, cont, "R1", temp);
		recursiva(a, b, flip_left[c-1], flip_left[d-1], cont, "L2", temp);
		recursiva(a, b, flip_right[c-1], flip_right[d-1], cont, "R2", temp);
		recursiva(flip_up[a-1], b, flip_up[c-1], d, cont, "U1", temp);
		recursiva(flip_down[a-1], b, flip_down[c-1], d, cont, "D1", temp);
		recursiva(a, flip_up[b-1], c, flip_up[d-1], cont, "U2", temp);
		recursiva(a, flip_down[b-1], c, flip_down[d-1], cont, "D2", temp);

	}
	else if(cont <= spins_max && a == 1 && b == 1 && c == 1 && d == 1){

		if(cont < best_cont){
			strcpy(resposta, temp);
			best_cont = cont;
			
		}
		else if(cont == best_cont){
			if(strcmp(resposta, temp) > 0){
				strcpy(resposta, temp);
			}
			else if(strcmp(resposta, "") == 0) strcpy(resposta, temp);
		}
		else return;

	}
	else return;

}

int main(){

	int a, b, c, d;

	scanf("%d", &spins_max);
	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);

	recursiva(flip_left[a-1], flip_left[b-1], c, d, 1, "L1", "");
	recursiva(flip_right[a-1], flip_right[b-1], c, d, 1, "R1", "");
	recursiva(a, b, flip_left[c-1], flip_left[d-1], 1, "L2", "");
	recursiva(a, b, flip_right[c-1], flip_right[d-1], 1, "R2", "");
	recursiva(flip_up[a-1], b, flip_up[c-1], d, 1, "U1", "");
	recursiva(flip_down[a-1], b, flip_down[c-1], d, 1, "D1", "");
	recursiva(a, flip_up[b-1], c, flip_up[d-1], 1, "U2", "");
	recursiva(a, flip_down[b-1], c, flip_down[d-1], 1, "D2", "");

	printf("%s \n", resposta);

	return 0;
}


