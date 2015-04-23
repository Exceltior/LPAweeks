#include <stdio.h>

int max = 5000;
int num_topics;
int num_precedences;
int max_topics;
int i, j;
int dependentes[5000][5000+2];
int precendentes[5000][5000+2];

int main(){

	scanf("%d %d %d", &num_topics, &num_precedences, &max_topics);
	
	int max_works = 0;
	int stuffy_days = 0;
	int aux;

	int temp1, temp2;

	for(i = 0; i < num_precedences; i++){

		scanf("%d %d", &temp1, &temp2);

		if(temp1 != temp2){

			dependentes[temp2][0]++;
		
			aux = precendentes[temp1][0];
			precendentes[temp1][0]++;
			precendentes[temp1][aux+1] = temp2;

		}

	}
	
	int check = 0;
	int num_works = 0;
	int permissoes[num_topics];
	int temp = 0;

	while(1){

		num_works = 0;

		for(i = 0; i < num_topics; i++){
			
			if(dependentes[i][0] == 0){

				temp = 1;

				permissoes[i] = (-1);

			}
			else if(dependentes[i][0] > 0){
				permissoes[i] = 1;
				check = 1;
			}

		}

		if(temp == 0){
			break;
		}

		temp = 0;

		for(i = 0; i < num_topics; i++){

			if(permissoes[i] == -1){

				permissoes[i] = (-2);

				dependentes[i][0] = (-1);

				num_works++;

				if(precendentes[i][0] != 0){

					for(j = 1; j < (precendentes[i][0] + 1); j++){
						dependentes[precendentes[i][j]][0]--;
					}

				}

			}

		}

		if(num_works > max_works) max_works = num_works;
		if(num_works > max_topics) stuffy_days++;

		if(check == 0) break;
		else check = 0;

	}

    printf("%d %d\n", max_works, stuffy_days);
	
    return 0;
}