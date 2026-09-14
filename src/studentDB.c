#include "studentDB.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Student Struct
typedef struct {
    int ID;
    char name[MAX_NAME_LEN];
    float grade;
} Student;

// Student Database Struct
typedef struct {
    Student students[MAX_STUDENTS];
    int count;
} DataBase;


// Initialize the DataBase
void initDB(DataBase *db){
    db->count = 0;
}


// Add a user
int addStudent(DataBase *db, int ID, char name[MAX_NAME_LEN], float grade){
    // Check edge case where database is full
    if (db->count > MAX_STUDENTS){
        printf("DataBase Full");
        return NULL;
    }

    // Add user details
    Student s = &db->students[db->count];

    s->ID = ID;
    strncpy(s->name, name, MAX_STUDENTS-1);
    s->name[MAX_STUDENTS - 1] = '\0';
    s->grade = grade;

    db->count ++;
}

void printStudents(DataBase *db){

    Student 
    for (int i = 0; i < db->count; i++){
        printf("| ID | NAME | GRADE |");
        printf("%d %c %f", )
    }
}
