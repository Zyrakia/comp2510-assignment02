#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Entry point for Assignment 2 of COMP2510.
 *
 * @param argc the command line argument count
 * @param argv the command line arguments
 * @return the program exit code
 */
int main(const int argc, const char *const *argv) {
    AllStudentInfo *info = malloc(sizeof(AllStudentInfo));
    if (info == NULL) {
        fprintf(stderr, "Unable to allocate memory for student info struct.\n");
        exit(EXIT_FAILURE);
    }

    info->birth_day = 10;
    info->birth_month = 12;
    info->birth_year = 2000;
    info->gpa = MAX_GPA;

    char *first_name = strdup("Norman");
    if (first_name == NULL) {
        free(info);

        fprintf(stderr, "Unable to allocate memory for student first name.\n");
        exit(EXIT_FAILURE);
    }
    info->first_name = first_name;

    char *last_name = strdup("Fielding");
    if (last_name == NULL) {
        free(first_name);
        free(info);

        fprintf(stderr, "Unable to allocate memory for student last name.\n");
        exit(EXIT_FAILURE);
    }
    info->last_name = last_name;

    DomesticStudent domestic_student = {.general_info = info};

    Student *student = malloc(sizeof(Student));
    if (student == NULL) {
        free(first_name);
        free(last_name);
        free(info);

        fprintf(stderr, "Unable to allocate memory for student struct.\n");
        exit(EXIT_FAILURE);
    }
    student->type = DOMESTIC;
    student->domestic = domestic_student;

    printf("%s %s has a GPA of %.2f and was born on %u-%u-%u!\n",
           get_first_name(student), get_last_name(student), get_gpa(student),
           get_birth_day(student), get_birth_month(student),
           get_birth_year(student));

    free_student(student);
    return EXIT_SUCCESS;
}