#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>

#define board_size 8
int max_moves=board_size*board_size;
enum FieldState
{
    empty,
    not_empty
};

enum FieldState board[board_size][board_size] = {empty};
enum FieldState move_board[board_size][board_size] = {empty};

int a[8] =  {-1, -2, -2, -1, 1, 2, 2, 1};
int b[8] =	{2, 1, -1, -2, -2, -1, 1, 2};

bool is_valid_move(int x, int y);
void print_board(void);

bool solve_knight_tour(int move, int x, int y);

int main()
{
	
	int start_x, start_y, stop_value;
    do
	{
		printf("\nStart Position X ( 1-8 ): ");
		scanf("%d",&start_x);
		printf("\nStart Position Y ( 1-8 ): ");
		scanf("%d",&start_y);
		
	}while(start_x < 1 & start_x > 8 & start_y < 1 & start_y > 8);
	
    
    printf("\nStartposition: (%d, %d)\n", start_x, start_y);
    

    if (solve_knight_tour(1, start_x-1, start_y-1))
        print_board();
    else
    	printf("No Knight Tour.\n");
    return 0;
}

void print_board(void)
{
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            printf("%2d ", move_board[i][j]);
        }
        printf("\n");
    }
}

bool is_valid_move(int x, int y)
{
    return x >= 0 && x < board_size && y >= 0 && y < board_size && board[x][y] == empty;
}



bool solve_knight_tour(int move, int x, int y)
{
    // Update "move" and "no_empty"
    board[x][y] = not_empty;
    move_board[x][y] = move;

    // finish yet?????
    if (move == max_moves)
    {
        return true;
    }
    

    for (int i = 0; i < 8; i++)
    {
        int u = x + a[i];
        int v = y + b[i];
//        printf("%d %d\n",u,v);
        if (is_valid_move(u, v))
        {
//        	printf("%d %d\n",u,v);
//        	getch();
            if (solve_knight_tour(move + 1, u, v))
	        {
	            return true;
	        }
        }
    }
    board[x][y] = empty;
    return false;
}



