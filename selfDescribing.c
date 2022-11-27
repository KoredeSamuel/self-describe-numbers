#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    // --- open file ---
    FILE * file = fopen("self.in", "r");

    // --- if there's error opening file ---
    if (file == NULL){
        perror("Unable to read the file\n");
        exit(1);
    }
    
    int cases; // --- to store the number of test case ---
    fscanf(file, "%d", &cases);

    printf("Number Of Test Case: %d\n", cases);
    char num_entry_arr[cases][100]; // --- array variable declaration to store all the number entry from the file as a string---

    // --- to store all the number entry in the num_entry_arr array ---
    for (int c = 0; c < cases; c++){
        fscanf(file, "%s", num_entry_arr[c]);
    }

    char num_entry[40]; // --- to store each number entry in the file --

    // --- loop through the num_entry_arr array ---
    for (int b = 0; b < cases; b++){

        // --- get each of the number entry from the num_entry_arr array ---
        strcpy(num_entry, num_entry_arr[b]);
        printf("-------------------------\n");
        printf("%s\n", num_entry);

        bool check; // --- variable to indicate if it is a self-describing number or not --

        // --- to loop through each digit in the number entry ---
        for (int i = 0; i < strlen(num_entry); i++){ 
            
            // --- initialize variables. count represents the number of occurence of an index in the number. initialize it to 0. index variable represents the index of each digit in the number ---
            int count = 0;
            char current_digit = num_entry[i]; // --- variable to hold each digit value of the index ---

            // --- To check the number of occurence of the index in the number --- 
            for (int j = 0; j < strlen(num_entry); j++){
                if (num_entry[j] == i + '0'){
                    count += 1;
                }
            }

            // --- to check if the value of that index is equal to the number of times the index occurs in the number (count) ---
            if (current_digit == count + '0'){
                check = true;
            } else {
                check = false;
                break;
            }
        
        }
        
        // --- to print out whether it is a self describing number or not
        if (check == true){
            printf("It Is A Self Describing Number\n");
            // --- to print out the description of the self describing number ---
            
        } else {
            printf("Not a self describing number\n");
        }
    }

    // --- close file ---
    fclose(file);

    return 0;
}