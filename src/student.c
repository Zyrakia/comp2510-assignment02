#include "student.h"
#include <stdlib.h>

/**
 * Returns the general info of the specified student, which is the shared info
 * between all types of students.
 *
 * @param student a pointer to a student
 * @return a pointer to the general info, or NULL
 */
AllStudentInfo *get_general_info(const Student *student) {
    if (student->type == DOMESTIC) {
        return student->domestic.general_info;
    } else if (student->type == INTERNATIONAL) {
        return student->international.general_info;
    } else
        return NULL;
}

unsigned int get_birth_year(const Student *student) {
    const AllStudentInfo *info = get_general_info(student);
    if (info == NULL) return 0;
    return info->birth_year;
}

unsigned short int get_birth_month(const Student *student) {
    const AllStudentInfo *info = get_general_info(student);
    if (info == NULL) return 0;
    return info->birth_month;
}

unsigned short int get_birth_day(const Student *student) {
    const AllStudentInfo *info = get_general_info(student);
    if (info == NULL) return 0;
    return info->birth_day;
}

char *get_first_name(const Student *student) {
    const AllStudentInfo *info = get_general_info(student);
    if (info == NULL) return NULL;
    return info->first_name;
}

char *get_last_name(const Student *student) {
    const AllStudentInfo *info = get_general_info(student);
    if (info == NULL) return NULL;
    return info->last_name;
}

double get_gpa(const Student *student) {
    const AllStudentInfo *info = get_general_info(student);
    if (info == NULL) return MIN_GPA;
    return info->gpa;
}

unsigned short int get_toefl(const Student *student) {
    if (student->type == INTERNATIONAL) {
        return student->international.toefl;
    } else
        return MIN_TOEFL;
}

void free_student(Student *student) {
    if (student == NULL) return;

    AllStudentInfo *info = NULL;

    if (student->type == DOMESTIC) {
        info = student->domestic.general_info;
    } else if (student->type == INTERNATIONAL) {
        info = student->international.general_info;
    }

    if (info != NULL) {
        free(info->first_name);
        free(info->last_name);
        free(info);
    }

    free(student);
}