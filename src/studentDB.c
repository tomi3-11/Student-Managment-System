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
void addStudent(DataBase *db, int ID, const char *name, float grade){
    // Check edge case where database is full
    if (db->count > MAX_STUDENTS){
        printf("DataBase Full");
        return;
    }

    // Add user details
    Student *s = &db->students[db->count];

    s->ID = ID;
    strncpy(s->name, name, MAX_NAME_LEN-1);
    s->name[MAX_NAME_LEN- 1] = '\0';
    s->grade = grade;

    db->count ++;
}

void printStudents(const DataBase *db){

    printf("----------Student List------------");
    for (int i = 0; i < db->count; i++){
        printf("| ID: %d | NAME: %-20s | GRADE: %.2f |", db->students[i].ID, db->students[i].name, db->students[i].grade);
    }
}

int main(){
    DataBase db; 

    initDB(&db);
    addStudent(&db, 12, "Tom", 89.8);
    printStudents(&db);
    return 0;
}
