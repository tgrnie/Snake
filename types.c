#include <ncurses.h>
#include "types.h"
#include "definitions.h"


void init_game(game_t *game_state, int start_len) {
    /* game state constructor */
    game_state->over = false;
    game_state->level = 1;
    game_state->pause = INIT_PAUSE;
    game_state->score = 0;

    /* snake constructor */
    game_state->snake.dir = RIGHT;
    game_state->snake.len = start_len;
    for (int i=0; i<start_len; ++i) {
        game_state->snake.arr[i].x = (game_state->border.x2+game_state->border.x1)/2 - i;
        game_state->snake.arr[i].y = (game_state->border.y2+game_state->border.y1)/2;
    }
    
    // init ball
    game_state->ball.x = -1; game_state->ball.y = -1;
    game_state->ball.flag = 1;
}

void update_border(game_t *game_state, pt_t *SCREEN_MAX) {
    /* this must be called before init_game */
    game_state->border.x1 = (SCREEN_MAX->x/2) - GAME_MAX_DIM/2;
    game_state->border.x2 = (SCREEN_MAX->x/2) + GAME_MAX_DIM/2;
    game_state->border.y1 = 5;
    game_state->border.y2 = (SCREEN_MAX->y - 5) < GAME_MAX_DIM ? (SCREEN_MAX->y-5) : GAME_MAX_DIM;

}

// Colour init
void initialise_colour_pairs() {
    /* set colour pairs to number defined above */
    init_pair(RED, COLOR_RED, COLOR_BLACK);
    init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);

    init_pair(SNAKE_COLOUR, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(BORDER_COLOUR, COLOR_WHITE, COLOR_WHITE);
    init_pair(SNAKE_COLOUR_HEAD, COLOR_BLACK, COLOR_GREEN);
}