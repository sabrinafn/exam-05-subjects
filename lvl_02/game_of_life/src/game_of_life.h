#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALIVE '0'
#define DEAD ' '

typedef struct s_game {

    int     height;
    int     width;
    int     iter;
    char    **matrix;
    char    **temp;
    char    *cmds;

}   t_game;

#include "game_of_life.h"

/* ALLOCATE WITH MALLOC A MATRIX WITH PARAMETERS HEIGHT AND WIDHT */
char **get_matrix(int height, int width);

/* GET LIST OF COMMANDS FROM STDIN WITH READ */
char *get_commands(void);

/* INITIALIZE STRUCT T_GAME */
t_game *init_struct(char **av);

/* INITIALIZE MATRIX WITH COMMANDS FROM STDIN */
void init_matrix(t_game *game);

/* PRINT MATRIX USING FT_PUTSTR */
void print_matrix(char **matrix);

/* RETURN IF CURRENT CELL IS ALIVE OR DEAD */
int get_count(t_game *game, int row, int col);

/* RETURN TOTAL NUMBER OF ALIVE NEIGHBOURS AROUND EACH CELL */
int neighbours_count(t_game *game, int row, int col);

/* COPY TEMP TO MATRIX */
void copy_temp_to_matrix(t_game *game);

/* PERFORM THE ITERATIONS BASED ON ALIVE NEIGHBOURS COUNT */
void run_game(t_game *game);

/* FREE ALL MEMORY ALLOCATED */
void free_game(t_game *game);

#endif