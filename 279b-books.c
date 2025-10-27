/*
* Problem: Find continuous numbers who is equal to or less than target
*
* */

#include <stdio.h>
#include <stdlib.h>

int solution(int time, int *books, int books_count);

int solution(int time, int *books, int books_count) {
    int window = 0;
    int result = 0;
    int left = 0;
    int right = 0;
    while (right < books_count) {
        window += books[right];
        while (window > time) {
            window -= books[left];
            left++;
        }
        if (right - left + 1 > result) {
            result = right - left + 1;
        }
        right++;
    }
    return result;
}


int main() {
    int books, time;
    scanf("%d %d", &books, &time);

    int *book = (int *)malloc(books * sizeof(int));
    if (book == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }
    for(int itr = 0; itr < books; itr++) {
        scanf("%d", &book[itr]);
    }
    
    printf("%d", solution(time, book, books));
    free(book);
    book = NULL;

    return 0;
}
