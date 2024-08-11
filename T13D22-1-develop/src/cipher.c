#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int input_menu(int *num);
void read(char *path);
void write(char *path);
void caesar();
int main() {
    int num;
    char str[100];
    while (1) {
        int flag = input_menu(&num);
        if (flag) {
            if (num == -1) {
                break;
            } else if (num == 1) {
                scanf("%s", str);
                read(str);
            } else if (num == 2) {
                write(str);
            } else if (num == 3) {
                caesar();
            }
        } else {
            printf("n/a\n");
        }
    }
    return 0;
}

int input_menu(int *num) {
    char c;
    int res1 = scanf("%d%c", num, &c);
    int flag = 1;
    if ((res1 != 2) || (c != '\n')) {
        flag = 0;
    }
    return flag;
}

void read(char *path) {
    char buffer[256];
    FILE *fp = fopen(path, "r+");
    if (fp == NULL) {
        printf("n/a\n");
    } else {
        if (fgetc(fp) == EOF) {
            printf("n/a\n");
        } else {
            rewind(fp);
            while ((fgets(buffer, 256, fp)) != NULL) {
                printf("%s", buffer);
            }
            printf("\n");
        }
    }
}

void write(char *path) {
    char buffer[256];
    char string[256];
    fgets(string, 255, stdin);
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("n/a\n");
        fclose(fp);
    } else {
        fp = fopen(path, "a");
        fprintf(fp, "%s", string);
        fclose(fp);
        fp = fopen(path, "r");
        rewind(fp);
        while ((fgets(buffer, 256, fp)) != NULL) {
            printf("%s", buffer);
        }
    }
}

void caesar() {
    char *files[] = {"ai_modules/m1.c", "ai_modules/m2.c", "ai_modules/m1.h", "ai_modules/m2.h"};
    int shift;
    scanf("%d", &shift);
    FILE *fp;
    for (int i = 0; i < 4; i++) {
        size_t len = strlen(files[i]);
        if (files[i][len - 1] == 'h') {
            fp = fopen(files[i], "w");
            fclose(fp);
        } else {
            char symbol;
            fp = fopen(files[i], "r+");
            while ((symbol = fgetc(fp)) != EOF) {
                fseek(fp, -1, SEEK_CUR);
                fputc((symbol + shift), fp);
                fseek(fp, 0, SEEK_CUR);
            }
            fclose(fp);
        }
    }
}