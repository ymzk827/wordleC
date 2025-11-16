#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//ok

//print every element of array
void printArray(char arr[]) {
    for (int i = 0; i < 5; i++) {
        printf("%c", arr[i]);
    }
    printf("\n");
}

//Main program. Works in console
int main(void) {
    char input[8];
    //Word prepared by our game;
    char word[8];

    //Lets add attempts like in original Wordle game
    int a = 5;

    FILE *f = fopen("words.txt", "r");
    if (!f) {
        printf("Could not open words.txt\n");
        return 0;
    }

    // Count lines
    char buffer[64];
    int count = 0;
    while (fgets(buffer, sizeof(buffer), f)) {
        count++;
    }

    if (count == 0) {
        printf("words.txt is empty!\n");
        fclose(f);
        return 0;
    }

    // Pick random line
    srand(time(NULL));
    int target = rand() % count;


    rewind(f);
    int index = 0;
    while (fgets(buffer, sizeof(buffer), f)) {
        if (index == target) {
            buffer[strcspn(buffer, "\n")] = 0;
            strcpy(word, buffer);
            break;
        }
        index++;
    }
    char word_arr[8] = {'0','0','0','0','0','0'};
    //Convert our word to an array;
    strcpy(word_arr, word);

    char output[8] = {'0','0','0','0','0','0'};

    printf("Your word: \n");
    printArray(output);


    //Convert word from input to an array here to check if this word is same as word in our game
    char tmp[8] = {'0','0','0','0','0','0'};

    while (a !=0) {
        printf("Your attempts: %i \n", a);
        printf("Enter word: \n");
        scanf("%s", input);
        strcpy(tmp, input);

        if (strlen(input) !=5) {
            printf("Your word must contain 5 characters \n");
            continue;
        }


        for (int i = 0; i < 5; i++) {
            if (tmp[i] == word_arr[i]) {
                output[i] = word_arr[i];
            }
        }
    printArray(output);
        if (strcmp(output, word_arr) == 1) {
            printf("You won! The word is: %s", word);
            return 0;
        }
        else {
            a--;
            printf("Try again \n");
        }

    }

    printf("You lose this time! Try again later");
    return 0;


}
