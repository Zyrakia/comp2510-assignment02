/**
 * Represents the possible student types.
 */
typedef enum { DOMESTIC, INTERNATIONAL } StudentType;

/**
 * The minimum TOEFL score that can be achieved by a student.
 */
#define MIN_TOEFL 0

/**
 * The maximum TOEFL score that can be achieved by a student.
 */
#define MAX_TOEFL 120

/**
 * The minimum GPA that can be achieved by a student.
 */
#define MIN_GPA 0

/**
 * The maximum GPA that can be achieved by a student.
 */
#define MAX_GPA 4

/**
 * Holds the information that all students will have, regarding of the type
 * of student.
 */
typedef struct {
    unsigned int birth_year;
    unsigned short int birth_month;
    unsigned short int birth_day;
    char *first_name;
    char *last_name;
    double gpa;
} AllStudentInfo;

/**
 * Holds data associated with a domestic student.
 */
typedef struct {
    /**
     * A pointer to the shared student information for this domestic
     * student.
     */
    AllStudentInfo *general_info;
} DomesticStudent;

typedef struct {
    /**
     * A pointer to the shared student information for this international
     * student.
     */
    AllStudentInfo *general_info;

    /**
     * The TOEFL score for this student, is assumed to be an int between 0 and
     * 120 (inclusive).
     */
    unsigned short int toefl;
} InternationalStudent;

/**
 * Represents a student, either DOMESTIC or INTERNATIONAL, with
 * the details of the student under an embedded struct that is
 * accessed depending on the type of the student.
 */
typedef struct {
    /**
     * The type of student that this student represents.
     */
    StudentType type;

    union {
        /**
         * Holds the information about this student, if this student is a
         * domestic student.
         */
        DomesticStudent domestic;

        /**
         * Holds the information about this student, if this student is an
         * international student.
         */
        InternationalStudent international;
    };
} Student;

/**
 * Returns the birth year of the specified student.
 *
 * @param student a pointer to a student
 * @return the birth year of the student, or 0 by default
 */
unsigned int get_birth_year(const Student *student);

/**
 * Returns the birth month of the specified student.
 *
 * @param student a pointer to a student
 * @return the birth month of the student, or 0 by default
 */
unsigned short int get_birth_month(const Student *student);

/**
 * Returns the birth day of the specified student.
 *
 * @param student a pointer to a student
 * @return the birth day of the student, or 0 by default
 */
unsigned short int get_birth_day(const Student *student);

/**
 * Returns the first name of the specified student.
 *
 * @param student a pointer to a student
 * @return a pointer to the first name string of the student, or NULL
 */
char *get_first_name(const Student *student);

/**
 * Returns the last name of the specified student.
 *
 * @param student a pointer to a student
 * @return a pointer to the last name string of the student, or NULL
 */
char *get_last_name(const Student *student);

/**
 * Returns the GPA of the specified student.
 *
 * @param student a pointer to a student
 * @return the GPA, or MIN_GPA by default
 */
double get_gpa(const Student *student);

/**
 * Returns the TOEFL score of the specified student. If the student is domestic
 * or of an invalid type, a score of MIN_TOEFL is returned.
 *
 * @param student a pointer to a student
 * @return the TOEFL score, or MIN_TOEFL by default
 */
unsigned short int get_toefl(const Student *student);

/**
 * Deallocates memory associated with the given student. After invocation with a
 * student, that student is no longer safe to use, and a pointer to it should be
 * discarded.
 *
 * @param student a pointer to a dynamically allocated student
 */
void free_student(Student *student);