#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_STUDENTS_1 5
#define NUM_STUDENTS_2 4

struct studente {
    char *nome;
    char *cognome;
    int matricola;
};

struct studente *merge_students(struct studente *students1, int size1, struct studente *students2, int size2);

int main()
{
    // Create two sorted arrays of students
    struct studente students1[NUM_STUDENTS_1] = {
        {"Alice", "Smith", 123456},
        {"Bob", "Johnson", 234567},
        {"Charlie", "Williams", 345678},
        {"Dave", "Brown", 456789},
        {"Eve", "Jones", 567890}
    };
    struct studente students2[NUM_STUDENTS_2] = {
        {"Frank", "Miller", 678901},
        {"Gina", "Taylor", 789012},
        {"Henry", "Davis", 890123},
        {"Irina", "Rodriguez", 901234}
    };

    // Merge the two arrays of students
    int size1 = NUM_STUDENTS_1;
    int size2 = NUM_STUDENTS_2;
    struct studente *merged = merge_students(students1, size1, students2, size2);

    // Print the merged array of students
    int size = size1 + size2;
    printf("Merged array:\n");
    for (int i = 0; i < size; i++)
        printf("%s %s (matricola: %d)\n", merged[i].nome, merged[i].cognome, merged[i].matricola);

    // Free the merged array
    free(merged);

    return 0;
}


struct studente *merge_students(struct studente *students1, int size1, struct studente *students2, int size2)
{
    // Allocate a new array to hold the merged elements
    struct studente *merged = malloc((size1 + size2) * sizeof(struct studente));

    // Initialize the indices for the input arrays
    int i = 0, j = 0, k = 0;

    // Merge the elements from the input arrays into the new array
    while (i < size1 && j < size2)
    {
        // Compare the matricola fields of the current elements
        if (students1[i].matricola < students2[j].matricola)
        {
            // Add the element from the first array to the merged array
            merged[k++] = students1[i++];
        }
        else
        {
            // Add the element from the second array to the merged array
            merged[k++] = students2[j++];
        }
    }

    // Add the remaining elements from the first array, if any
    while (i < size1)
        merged[k++] = students1[i++];

    // Add the remaining elements from the second array, if any
    while (j < size2)
        merged[k++] = students2[j++];

    // Return the merged array
    return merged;
}