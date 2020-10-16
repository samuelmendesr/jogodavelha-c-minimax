#include <stdio.h>

#define MIN    -1
#define MAX     1

int win(int game[9]) 
{
    
    int wins[8][3] = {{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}};
    int i;
    
    for(i = 0; i < 8; ++i) 
    {
        if(game[wins[i][0]] + game[wins[i][1]] + game[wins[i][2]] == 3*MIN) 
            return MIN;
        if(game[wins[i][0]] + game[wins[i][1]] + game[wins[i][2]] == 3*MAX) 
            return MAX;
    }
    
    return 0;
}

int minimax(int game[9], int player) 
{
    
    int winner = win(game);
    if(winner != 0) 
        return winner*player;

    int move = -1;
    int score = -2;
    int i;
    
    for(i = 0; i < 9; ++i) 
    {
        if(game[i] == 0) 
        {
            game[i] = player; //testa a jogada
            int thisScore = -1*minimax(game, -1*player); //deve haver -1* para alternar o algoritimo
            
            if(thisScore > score) 
            {
                score = thisScore;
                move = i;
            }
            game[i] = 0;
        }
    }
    
    if(move == -1) //caso a jogada permaneça -1 é sinal de empate
        return 0;
    
    return score;
}

int computerMove(int game[9]) 
{
    int move = -1;
    int score = -2;
    int i;
    
    for(i = 0; i < 9; ++i) 
    {
        if(game[i] == 0) 
        {
            game[i] = MAX; //testa a jogada
            int tempScore = -1*minimax(game, MIN);
            game[i] = 0; 
            
            if(tempScore > score) 
            {
                score = tempScore;
                move = i;
            }
        }
    }
    
    return move;
}

void expor_jogo(int* game, char player_1, char player_2)
{
	int i;

	printf("\n");

	for(i = 0; i < 9; i++)
	{
        if((!(i%3))&&i)
            printf("\n");
		
		if(*(game+i) == MIN)
			printf("[%c]", player_1);
		else if(*(game+i) == MAX)
			printf("[%c]", player_2);
		else
			printf("[ ]");
    }
	
	printf("\n");

}
