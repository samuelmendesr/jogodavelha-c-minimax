/* 
	Jogo da Velha Interativo
	
	@autor Samuel Mendes Rodrigues

	data de criação: 08/06/2016
	ultima atualização: 27/08/2016
*/

#include <stdio.h>
#include <stdlib.h>
#include "jogo_da_velha.h"

#define MIN    -1
#define MAX     1

int main()
{
	int i, time, resultado = 0, continuar;
	char entrada, player_1, player_2;
	int *game;

	game = (int*)calloc(9, sizeof(int));

	//apresentação...

	i = 1;

	while(i)
	{
		printf("Como deseja marcar?[x/o]:~> ");
		scanf("%c", &entrada);

		getchar();

		switch(entrada)
		{
			case 'x' :
				player_1 = 'X';
				player_2 = 'O';
				i = 0;
				break;

			case 'o' :
				player_1 = 'O';
				player_2 = 'X';
				i = 0;
				break;

			case 'e' :
				exit(0);

			default :
				printf("comando invalido");			
		}
	}

	i = 1;

	while(i)
	{
		printf("Deseja começar?[s/n]:~> ");
		scanf("%c", &entrada);

		getchar();

		switch(entrada)
		{
			case 's' :
				continuar = 1;
				i = 0;
				break;

			case 'n' :
				continuar = 0;
				i = 0;
				break;

			case 'e' :
				exit(0);

			default :
				printf("comando invalido");			
		}
	}

	printf("\n[1][2][3]\n[4][5][6]\n[7][8][9]\n");

	time = 0;

	while(time < 9)
	{	
		while(continuar)
		{
			printf("\n~>");
			scanf("%c", &entrada);

			getchar();

			switch(entrada)
			{
				case '1' :
					if(!(*game))
					{ 
						*game = MIN;
						continuar = 0;
						time++;
						break;
					}
					else
					{
						printf("\ncomando invalido");
						break;
					}
				case '2' :
					if(!(*(game + 1)))
					{
						*(game + 1) = MIN;
						continuar = 0;
						time++;					
						break;
					}
					else
					{
						printf("\ncomando invalido");
						break;
					}
				case '3' :
					if(!(*(game + 2)))
					{
						*(game + 2) = MIN;
						continuar = 0;
						time++;					
						break;
					}
					else
					{
						printf("\ncomando invalido");
						break;
					}
				case '4' :
					if(!(*(game + 3)))
					{
						*(game + 3) = MIN;
						continuar = 0;
						time++;					
						break;
					}
					else
					{
						printf("\ncomando invalido");
						break;
					}
				case '5' :
					if(!(*(game + 4)))
					{
						*(game + 4) = MIN;
						continuar = 0;
						time++;					
						break;
					}
					else
					{
						printf("\ncomando invalido");
						break;
					}
				case '6' :
					if(!(*(game + 5)))
					{
						*(game + 5) = MIN;
						continuar = 0;
						time++;					
						break;
					}
					else
					{
						printf("\ncomando invalido");
						break;
					}
				case '7' :
					if(!(*(game + 6)))
					{
						*(game + 6) = MIN;
						continuar = 0;
						time++;					
						break;
					}
					else
					{
						printf("\ncomando invalido");
						break;
					}
				case '8' :
					if(!(*(game + 7)))
					{
						*(game + 7) = MIN;
						continuar = 0;
						time++;					
						break;
					}
					else
					{
						printf("\ncomando invalido");
						break;
					}
				case '9' :
					if(!(*(game + 8)))
					{
						*(game + 8) = MIN;
						continuar = 0;
						time++;					
						break;
					}
					else
					{
						printf("\ncomando invalido");
						break;
					}
				case 'e' :
					exit(0);

				default :
					printf("\ncomando invalido");			
				}	
		}

		if(time > 3)
			resultado = win(game);

		if(resultado)
		{
			continuar = 0;

			if(resultado == 1)
			{
				expor_jogo(game, player_1, player_2);

				printf("\nVoce perdeu!\n\n");
			}
			else
				printf("\nVoce venceu!\n\n");

			time = 9;
		}
		else if(time == 9)
		{
			continuar = 0;

			printf("\nEmpate!\n");
		}
		else
			continuar = 1;
		
		if(continuar)
		{
			i = computerMove(game);

			*(game + i) = MAX;

			expor_jogo(game, player_1, player_2);

			time++;
		}

		if(time > 3)
			resultado = win(game);

		if(resultado&&continuar)
		{
			continuar = 0;
			
			if(resultado)
			{
				expor_jogo(game, player_1, player_2);

				printf("\nVoce perdeu!\n\n");
			}
			else
				printf("\nVoce venceu!\n\n");

			time = 9;
		}
		else if((time == 9)&&continuar)
		{
			continuar = 0;

			printf("\nEmpate!\n");
		}
		else
			continuar = 1;
	}

	free(game);

	return 0;
}
