#include "stdio.h"
void Printfield(int ball_x, int ball_y, int rocket_left_pos, int rocket_right_pos, int score1, int score2);
int ball_move_x(int ball_x, int dir);
int ball_move_y(int ball_y, int dir);
int ball_top(int ball_y, int dir);
int ball_bot(int ball_y, int dir);
int left_rocket_colizion(int rocket_left_pos, int dir, int ball_x, int ball_y);
int right_rocket_colizion(int rocket_left_pos, int dir, int ball_x, int ball_y);
int rocket_left(int coord_left, int rock_step);
int rocket_right(int coord_right, int rock_step);
int score1(int sc1, int ball_x, int ball_y, int rocket_left_pos);
int score2(int sc2, int ball_x, int ball_y, int rocket_right_pos);
int left_rocket(char key);
int right_rocket(char key);
int right_dis(int rocket_y, int ball_x, int ball_y);
int main() {
    int ball_x = 40, ball_y = 13, ball_step_x = 1, ball_step_y = 1, sc1 = 0, sc2 = 0;
    int rocket_left_pos = 13, rocket_right_pos = 13, dir = 1;
    while (1) {
        char symbol, end;
        if (scanf("%c%c", &symbol, &end) == 2 && end == '\n') {
            if (symbol == 'A' || symbol == 'a' || symbol == 'Z' || symbol == 'z' || symbol == 'K' ||
                symbol == 'k' || symbol == 'M' || symbol == 'm' || symbol == ' ') {
                if (symbol == 'A' || symbol == 'a') {
                    rocket_left_pos = rocket_left(rocket_left_pos, -1);
                } else if (symbol == 'Z' || symbol == 'z') {
                    rocket_left_pos = rocket_left(rocket_left_pos, 1);
                } else if (symbol == 'K' || symbol == 'k') {
                    rocket_right_pos = rocket_right(rocket_right_pos, -1);
                } else if (symbol == 'M' || symbol == 'm') {
                    rocket_right_pos = rocket_right(rocket_right_pos, 1);
                }
                dir = ball_top(ball_y, dir);
                dir = ball_bot(ball_y, dir);
                dir = left_rocket_colizion(rocket_left_pos, dir, ball_x, ball_y);
                dir = right_rocket_colizion(rocket_right_pos, dir, ball_x, ball_y);
                ball_x = ball_move_x(ball_x, dir);
                ball_y = ball_move_y(ball_y, dir);
                Printfield(ball_x, ball_y, rocket_left_pos, rocket_right_pos, sc1, sc2);
            }
        }
        if ((ball_x == 77) && (ball_y != rocket_right_pos && ball_y != rocket_right_pos + 1 &&
                               ball_y != rocket_right_pos - 1)) {
            sc1 += 1;
            ball_x = 40;
            ball_y = 13;
        }
        if ((ball_x == 2) &&
            (ball_y != rocket_left_pos && ball_y != rocket_left_pos + 1 && ball_y != rocket_left_pos - 1)) {
            sc2 += 1;
            ball_x = 40;
            ball_y = 13;
        }
        if (sc1 >= 21 || sc2 >= 21) {
            if (sc1 >= 21) {
                printf("FIRST player WIN, 21 point");
            } else {
                printf("SECOND player WIN, 21 point");
            }
            break;
        }
    }
    return 0;
}
void Printfield(int ball_x, int ball_y, int rocket_left_pos, int rocket_right_pos, int score1, int score2) {
    for (int i = 0; i < 26; i++) {
        printf("\n");
    }
    printf("Player1 %d\n", score1);
    printf("Player2 %d\n", score2);
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            if (i == 0 || i == 24) {
                printf("-");
            } else if ((i > 0 && i < 24) && j == 0 || j == 79) {
                printf("*");
            } else if (j == 1 &&
                       (i == rocket_left_pos || i == rocket_left_pos + 1 || i == rocket_left_pos - 1)) {
                printf("|");
            } else if (j == 78 &&
                       (i == rocket_right_pos || i == rocket_right_pos + 1 || i == rocket_right_pos - 1)) {
                printf("|");
            } else if (i == ball_y && j == ball_x) {
                printf("o");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
int rocket_left(int coord_left, int rock_step) {
    if (coord_left < 23 && coord_left > 2) {
        coord_left += rock_step;
    } else if (coord_left >= 23) {
        coord_left = 23;
    } else if (coord_left <= 2) {
        coord_left = 2;
    }
    return coord_left;
}
int rocket_right(int coord_right, int rock_step) {
    if (coord_right < 23 && coord_right > 2) {
        coord_right += rock_step;
    } else if (coord_right >= 23) {
        coord_right = 23;
    } else if (coord_right <= 2) {
        coord_right = 2;
    }
    return coord_right;
}
int score1(int sc1, int ball_x, int ball_y, int rocket_left_pos) {
    if ((ball_x == 1) &&
        (ball_y != rocket_left_pos || ball_y != rocket_left_pos + 1 || ball_y != rocket_left_pos - 1)) {
        sc1 += 1;
    }
    return sc1;
}
int score2(int sc2, int ball_x, int ball_y, int rocket_right_pos) {
    if ((ball_x == 79) &&
        (ball_y != rocket_right_pos || ball_y != rocket_right_pos + 1 || ball_y != rocket_right_pos - 1)) {
        sc2 += 1;
    }
    return sc2;
}
int left_rocket(char key) {
    switch (key) {
        case 'A':
            return 1;
        case 'a':
            return 1;
        case 'Z':
            return -1;
        case 'z':
            return -1;
        default:
            return 0;
    }
}
int right_rocket(char key) {
    switch (key) {
        case 'K':
            return 1;
        case 'k':
            return 1;
        case 'M':
            return -1;
        case 'm':
            return -1;
        default:
            return 0;
    }
}
int ball_move_x(int ball_x, int dir) {
    if ((dir == 1 || dir == 2) && ball_x < 78) {
        ball_x += 1;
    }
    if ((dir == 3 || dir == 4) && ball_x > 2) {
        ball_x -= 1;
    }
    printf("ballx %d %d", ball_x, dir);
    return ball_x;
}
int ball_move_y(int ball_y, int dir) {
    if ((dir == 1 || dir == 3) && ball_y <= 23) {
        ball_y += 1;
    }
    if ((dir == 2 || dir == 4) && ball_y >= 2) {
        ball_y -= 1;
    }
    return ball_y;
}
int ball_top(int ball_y, int dir) {
    if (dir == 2 && ball_y <= 1) {
        dir = 1;
    }
    if (dir == 4 && ball_y <= 1) {
        dir = 3;
    }
    return dir;
}
int ball_bot(int ball_y, int dir) {
    if (dir == 1 && ball_y >= 23) {
        dir = 2;
    }
    if (dir == 3 && ball_y >= 23) {
        dir = 4;
    }
    return dir;
}
int left_rocket_colizion(int rocket_y, int dir, int ball_x, int ball_y) {
    if (dir == 3 && ball_x == 2 && (ball_y == rocket_y || ball_y == rocket_y + 1 || ball_y == rocket_y - 1)) {
        dir = 1;
    }
    if (dir == 4 && ball_x == 2 && (ball_y == rocket_y || ball_y == rocket_y + 1 || ball_y == rocket_y - 1)) {
        dir = 2;
    }
    return dir;
}

int right_rocket_colizion(int rocket_y, int dir, int ball_x, int ball_y) {
    if (dir == 1 && ball_x == 77 &&
        (ball_y == rocket_y || ball_y == rocket_y + 1 || ball_y == rocket_y - 1)) {
        dir = 3;
    } else if (dir == 2 && ball_x == 77 &&
               (ball_y == rocket_y || ball_y == rocket_y + 1 || ball_y == rocket_y - 1)) {
        dir = 4;
    }
    return dir;
}

int right_dis(int rocket_y, int ball_x, int ball_y) {
    if (ball_x == 77 && (ball_y == rocket_y || ball_y == rocket_y + 1 || ball_y == rocket_y - 1)) {
        ball_x = 40;
    }
    return ball_x;
}
