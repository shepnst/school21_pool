#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void output(int **matrix, int n, int m);
void death_or_life(int **matrix, int n, int m);
int point_counter(int **matrix, int i, int j, int n, int m);
int check_if_zero(int **matrix, int n, int m);
int change_speed(char speed, int *flag, int time);
int main() {
    int h = 25;
    int w = 80;
    int flag = 1;
    int time_mili_sec = 500;
    int **matrix = malloc(h * sizeof(int *));  // columns
    for (int i = 0; i < h; ++i) {
        matrix[i] = malloc(w * sizeof(int));  // lines
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    if (freopen("/dev/tty", "r", stdin)) initscr();
    nodelay(stdscr, true);
    cbreak();
    start_color();
    echo();
    init_pair(1, COLOR_BLUE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_WHITE);
    while (flag != 0) {
        char speed = getch();
        if (check_if_zero(matrix, h, w) == 0) {
            printw("game is over");
            flag = 0;
            break;
        }
        time_mili_sec = change_speed(speed, &flag, time_mili_sec);
        clear();
        usleep(time_mili_sec * 1000);
        death_or_life(matrix, h, w);
        output(matrix, h, w);
        refresh();
    }
    for (int i = 0; i < h; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    endwin();
    return 0;
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 1) {
                attron(COLOR_PAIR(1));
                printw("%d", matrix[i][j]);
                attron(COLOR_PAIR(1));
            } else {
                attron(COLOR_PAIR(2));
                printw("%d", matrix[i][j]);
                attron(COLOR_PAIR(2));
            }
        }
        printw("\n");
    }
}

int point_counter(int **matrix, int i, int j, int n, int m) {
    int counter = 0;
    if (matrix[(i + n) % n][(j + m + 1) % m] == 1) {
        counter++;
    }
    if (matrix[(i + n) % n][(j + m - 1) % m] == 1) {
        counter++;
    }
    if (matrix[(i + n + 1) % n][(j + m + 1) % m] == 1) {
        counter++;
    }
    if (matrix[(i + n + 1) % n][(j + m - 1) % m] == 1) {
        counter++;
    }
    if (matrix[(i + n + 1) % n][(j + m) % m] == 1) {
        counter++;
    }
    if (matrix[(i + n - 1) % n][(j + m - 1) % m] == 1) {
        counter++;
    }
    if (matrix[(i + n - 1) % n][(j + m) % m] == 1) {
        counter++;
    }
    if (matrix[(i + n - 1) % n][(j + m + 1) % m] == 1) {
        counter++;
    }
    return counter;
}

void death_or_life(int **matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int counter = 0;
            counter = point_counter(matrix, i, j, n, m);
            if (matrix[i][j] == 1) {
                if (counter < 2 || counter > 3) {
                    matrix[i][j] = 0;
                }
            } else {
                if (counter == 3) {
                    matrix[i][j] = 1;
                }
            }
        }
    }
}

int check_if_zero(int **matrix, int n, int m) {
    int check = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            check += matrix[i][j];
        }
    }
    return check;
}

int change_speed(char speed, int *flag, int time_mili_sec) {
    if (speed == '1') {  // 3-variants of speed
        time_mili_sec = 800;
    } else if (speed == '2') {
        time_mili_sec = 400;
    } else if (speed == '3') {
        time_mili_sec = 100;
    } else if (speed == 'q') {  // q-quit the game(exit)
        *flag = 0;              // iteration will be killed
    }
    return time_mili_sec;
}
