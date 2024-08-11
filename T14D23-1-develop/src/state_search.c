#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct my_struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
};

struct my_struct read_record_from_file(FILE *pfile, int index) {
    int offset = index * sizeof(struct my_struct);
    fseek(pfile, offset, SEEK_SET);
    struct my_struct record;
    fread(&record, sizeof(struct my_struct), 1, pfile);
    rewind(pfile);
    return record;
};

int get_records_count_in_file(FILE *pfile);
int search(char *path, int year, int month, int day);

int main() {
    char str[1024] = {0};
    scanf("%s", str);
    char up[1024] = "../";
    strcat(up, str);
    int year, month, day;
    char c;
    int result;
    int compare = scanf("%2d.%2d.%4d%c", &day, &month, &year, &c);
    if (compare == 4 && (c == '\n' || c == ' ')) {
        result = search(up, year, month, day);
        if (result != 0) {
            printf("%d", result);
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return size;
}

int get_records_count_in_file(FILE *pfile) {
    return get_file_size_in_bytes(pfile) / sizeof(struct my_struct);
}

int search(char *path, int year, int month, int day) {
    FILE *pf = fopen(path, "rb");

    int result = 0;
    if (pf == 0 || pf == NULL) {
        printf("n/a\n");
    } else {
        int size = get_records_count_in_file(pf);
        if (size == 0) {
            printf("n/a\n");
        } else {
            for (int i = 0; i < size; i++) {
                struct my_struct data = read_record_from_file(pf, i);
                if (data.year == year && data.month == month && data.day == day) {
                    result = data.code;
                    break;
                }
            }
        }
    }
    fclose(pf);
    return result;
}