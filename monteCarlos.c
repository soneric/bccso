#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float chutaPontoXY(int amostra, int *ptr){

	int i = 0;

	float alea, base,fine;
 
	for(i;i<amostra;i++){
		
	 	alea = RAND_MAX + 1.;
		base = rand() / alea;
		fine = rand() / alea;
		alea = base + fine/alea;
		
	ptr[i] = alea;
	
	}
	
}

main()
{
	int pid, pid2;
	int *ptrX;
	int *ptrY;
	float pontosDentroDoCirculo = 0;
	int iX;
	int iY;	
	int pontosParaOPai = 0;

	pid = fork();
	pid2 = fork();
	float amostras = 999999999;
	
	ptrX = malloc(amostras * sizeof(float));
	ptrY = malloc(amostras * sizeof(float)); 
	
	if(pid == 0){
		chutaPontoXY(amostras, ptrX);
	}
	if(pid2 == 0){
		chutaPontoXY(amostras, ptrY);
	}
	if(pid > 0){
		
		while(pontosParaOPai != amostras - 1){
			if(&ptrX[pontosParaOPai] != 0 && &ptrY[pontosParaOPai] != 0){

				if(pow(ptrX[pontosParaOPai], 2) + pow(ptrY[pontosParaOPai],2) <=1 ){
					pontosDentroDoCirculo ++;
				}
			pontosParaOPai++;				

			}			

		}
		printf("PI: %f" , 4*pontosDentroDoCirculo/amostras);
		
	}
}
