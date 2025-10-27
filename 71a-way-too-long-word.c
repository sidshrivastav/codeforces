/*
 * Problem: Check count if not strictly more than 10 characters, return the word else {first_char|lenght-2|last_char}
 * */

#include <stdio.h>
#include <string.h>

#define MAX_ABBREV_LENGTH 15

char* way_too_long_word(const char* word){
    static char result[MAX_ABBREV_LENGTH];
    size_t len = strlen(word);

    if (len <= 10) {
        strncpy(result, word, MAX_ABBREV_LENGTH-1);
        result[MAX_ABBREV_LENGTH-1] = '\0';
        return result;
    }
    snprintf(result, MAX_ABBREV_LENGTH, "%c%d%c", word[0], (int)(len-2), word[len-1]);
    return result;
}

int main() {
    int tests;
    scanf("%d", &tests);
    for (int itr = 0; itr < tests; itr++) {
        char word[101];
        scanf("%100s", word);
        printf("%s\n", way_too_long_word(word));
    }
    return 0;
}


