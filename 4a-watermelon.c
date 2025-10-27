/*
 * Problem: Figure out if number is even or not
 * */

#include <stdio.h>

int solution(int num);

int solution(int num) {
    if ((num & 1) == 0) {
        return 1;
    }
    return 0;
}

int main() {
    int number;
    scanf("%d", &number);
    if (number > 2 && solution(number) == 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
