//
// Created by aabdu on 8/26/2023.
//
// Database Function Prototype file

#ifndef C_PROJECT_SDB_H
#define C_PROJECT_SDB_H

// standard type definitions
#include "STD.h"

#define  MinStudents 3   // minimum number of students in DB
#define  MaxStudents 10  // maximum number of students in DB

typedef struct SimpleDb  // Student Database variables
{
    uint32 Student_ID;
    uint32 Student_year;
    uint32 Course1_ID;
    uint32 Course1_grade;
    uint32 Course2_ID;
    uint32 Course2_grade;
    uint32 Course3_ID;
    uint32 Course3_grade;

} student;


// database function prototypes


bool  SDB_IsFull();                                         // check and return if DB is full or not
uint8 SDB_GetUsedSize();                                    // get and return how many students in DB
bool  SDB_AddEntry();                                       // Add Student in DB
void  SDB_DeleteEntry(uint32 id);                           // Delete Student from DB
bool  SDB_ReadEntry(uint32 id);                             // Read Student Data by ID
void  SDB_GetList (uint8 * count, uint32 * list);           // Get List of Students in DB
bool  SDB_IsIdExist (uint32 id);                            // Search if This ID Exist before
void  SDB_APP();                                            // Run APP Function
void  SDB_action(uint8);

#endif //C_PROJECT_SDB_H
