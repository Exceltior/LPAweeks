#include <stdio.h>
#include <string.h>

int lista_bancos[5000][5000], dividas[5000][5];
int nClusters = 0, clusterSize = 0, max = 0, num_bancos;
int ind;

void tarjan(int cluster[num_bancos], int n){

	int i;
	int count = 0;

	dividas[n][1] = ind;
	dividas[n][2] = ind;
	ind++;
	
	cluster[clusterSize++] = n;
	dividas[n][4] = 1;

	for(i = 0; i < dividas[n][3]; i++){

		if(dividas[lista_bancos[n][i]][1] == 0){
			
			tarjan(cluster,lista_bancos[n][i]);
			
			if(dividas[n][2] < dividas[lista_bancos[n][i]][2]){
				dividas[n][2] = dividas[n][2];
			}
			else{
				dividas[n][2] = dividas[lista_bancos[n][i]][2];
			}

		}
		else if(dividas[lista_bancos[n][i]][4] == 1){
			
			if(dividas[n][2] < dividas[lista_bancos[n][i]][1]){
				dividas[n][2] = dividas[n][2];
			}
			else{
				dividas[n][2] = dividas[lista_bancos[n][i]][1];
			}

		}

	}
	if(dividas[n][1] == dividas[n][2]){
		
		do{
			count+= dividas[cluster[clusterSize-1]][0];
			dividas[cluster[clusterSize-1]][4] = 0;
			clusterSize--;
		}
		while(cluster[clusterSize] != n);

		if(count > max && count != dividas[n][0]) 
			max = count;

	}

}

int main(int argc, char const *argv[]){

	int n;
	int i;
	int divida_total, bankOfDept;

	while(scanf("%d\n",&num_bancos)!= EOF){

		max = -9999999;
		
		ind = 1;
		clusterSize = 0;

		memset(lista_bancos,0,sizeof(lista_bancos));
		memset(dividas,0,sizeof(dividas));

		int cluster[num_bancos];

		for(i = 0; i < num_bancos; i++){

			scanf("%d\n",&n);

			while(1){

				scanf("%d\n",&divida_total);

				if(divida_total != 0){

					scanf("%d\n",&bankOfDept);
					
					lista_bancos[i][dividas[i][3]] = bankOfDept - 1;
					dividas[i][3]++;
					dividas[i][0]+= (divida_total*-1);
					dividas[bankOfDept-1][0]+= divida_total;

				}
				else break;

			}

		}
		for(i = 0; i < num_bancos; i++)
			if(dividas[i][1] == 0) 
				tarjan(cluster,i);

		if(max > -9999999)
			printf("%d\n", max);
		else
			printf("No cluster\n");

	}

	return 0;

}