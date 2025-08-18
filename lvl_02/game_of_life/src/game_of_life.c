#include "game_of_life.h"

/* ALLOCATE WITH MALLOC A MATRIX WITH PARAMETERS HEIGHT AND WIDHT */
char **get_matrix(int height, int width) {
    char **matrix = (char **)calloc((height + 1 ), sizeof(char *));
    int row = 0;
    while (row < height) {
        matrix[row] = (char *)calloc(sizeof(char), (width + 1));
        row++;
    }
    row = 0;
    int col = 0;
    while (row < height) {
        col = 0;
        while (col < width) {
            matrix[row][col] = DEAD;
            col++;
        }
        matrix[row][col] = '\0';
        row++;
    }
    return matrix;
}

/* GET LIST OF COMMANDS FROM STDIN WITH READ */
char *get_commands(void) {
    char *cmds = malloc(1);
    if (!cmds)
        return NULL;
    cmds[0] = '\0';

    char buf[128];
    int bytes_read, size = 0;
    char *temp;

    while ((bytes_read = read(0, buf, sizeof(buf))) > 0) {
        temp = realloc(cmds, size + bytes_read + 1);
        if (!temp) {
            free(cmds);
            return NULL;
        }
        cmds = temp;
        for (int i = 0; i < bytes_read; i++)
            cmds[size + i] = buf[i];
        size += bytes_read;
        cmds[size] = '\0';
    }
    return cmds;
}

/* INITIALIZE STRUCT T_GAME */
t_game *init_struct(char **av) {

    t_game *game = (t_game *)calloc(1, sizeof(t_game));
    game->width = atoi(av[1]);
    game->height = atoi(av[2]);
    game->iter = atoi(av[3]);
    game->matrix = get_matrix(atoi(av[2]), atoi(av[1]));
    game->temp = get_matrix(atoi(av[2]), atoi(av[1]));
    game->cmds = get_commands();

    return game;
}

/* INITIALIZE MATRIX WITH COMMANDS FROM STDIN */
void init_matrix(t_game *game) {
    int it = 0;
    int row = 0;
    int col = 0;
    bool pen = false;
    while (game->cmds[it] != '\0') {
        char c = game->cmds[it];
        if (c == 'x'){
            pen = !pen;
            if (pen && row >= 0 && row < game->height && col >= 0 && col < game->width)
                game->matrix[row][col] = ALIVE;
        }
        else if (c == 'a' && col > 0)
        {
            --col;
            if (pen)
                game->matrix[row][col] = ALIVE;
        }
        else if (c == 'd' && col < game->width - 1)
        {
            ++col;
            if (pen)
                game->matrix[row][col] = ALIVE;
        }
        else if (c == 'w' && row > 0)
        {
            --row;
            if (pen)
                game->matrix[row][col] = ALIVE;
        }
        else if (c == 's' && row < game->height - 1)
        {
            ++row;
            if (pen)
                game->matrix[row][col] = ALIVE;
        }
        it++;
    }
}

/* PRINT MATRIX USING FT_PUTSTR */
void print_matrix(char **matrix) {
    int row = 0;
    int col = 0;
    while (matrix[row]) {
        col = 0;
        while (matrix[row][col]) {
            putchar(matrix[row][col]);
            col++;
        }
        putchar('\n');
        row++;
    }
}

/* RETURN IF CURRENT CELL IS ALIVE OR DEAD */
int get_count(t_game *game, int row, int col) {

    if ((row >= 0 && row < game->height) && (col >= 0 && col < game->width)) {
        if (game->matrix[row][col] == ALIVE)
            return 1;
    }
    return 0;
}

/* RETURN TOTAL NUMBER OF ALIVE NEIGHBOURS AROUND EACH CELL */
int neighbours_count(t_game *game, int row, int col) {
    int count = 0;
    count += get_count(game, row -1, col -1);
    count += get_count(game, row -1, col   );
    count += get_count(game, row -1, col +1);
    count += get_count(game, row   , col -1);
    count += get_count(game, row   , col +1);
    count += get_count(game, row +1, col -1);
    count += get_count(game, row +1, col   );
    count += get_count(game, row +1, col +1);

    return count;
}

/* COPY TEMP TO MATRIX */
void copy_temp_to_matrix(t_game *game) {

    int row = 0;
    int col = 0;

    while (row < game->height) {
        col = 0;
        while (col < game->width) {
            game->matrix[row][col] = game->temp[row][col];
            col++;
        }
        row++;
    }
}

/* PERFORM THE ITERATIONS BASED ON ALIVE NEIGHBOURS COUNT */
void run_game(t_game *game) {
    int row = 0;
    int col = 0;
    int count = 0;

    while (row < game->height) {
        col = 0;
        while (col < game->width) {
            count = neighbours_count(game, row, col);
            if (game->matrix[row][col] == ALIVE) {
                if (count == 2 || count == 3)
                    game->temp[row][col] = ALIVE;
                else
                    game->temp[row][col] = DEAD;
            }
            else if (game->matrix[row][col] == DEAD) {
                if (count == 3)
                    game->temp[row][col] = ALIVE;
                else
                    game->temp[row][col] = DEAD;
            }
            col++;
        }
        row++;
    }
}

/* FREE ALL MEMORY ALLOCATED */
void free_game(t_game *game) {
    if (game->cmds)
        free(game->cmds);

    int row = 0;
    while (row < game->height) {
        free(game->matrix[row]);
        free(game->temp[row]);
        row++;
    }
    free(game->matrix);
    free(game->temp);
    free(game);
}

int main(int ac, char **av) {
    
    if (ac == 4) {
        t_game *game = init_struct(av);
        init_matrix(game);
        while (game->iter > 0) {
            run_game(game);
            copy_temp_to_matrix(game);
            game->iter--;
        }
        print_matrix(game->matrix);
        free_game(game);
    }
    return 0;
}