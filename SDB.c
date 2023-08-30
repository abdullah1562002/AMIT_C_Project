//
// Created by aabdu on 8/26/2023.
//
// Database Functions File

#include "SDB.h"


typedef struct Node {
    student data;           // saved data in node
    struct Node* next;      // next node address
} Node;

static Node* database = NULL; // single linked head (start) address



/************************************** IsFull **************************************/

bool  SDB_IsFull()
{
    return SDB_GetUsedSize() >= MaxStudents; // Compare database size to max students

}


/************************************** GetUsedSize **************************************/

uint8 SDB_GetUsedSize()
{
    uint8 studentCount = 0;

    Node *ptr = NULL;
    ptr = database;
    while(ptr != NULL){
        studentCount++;
        ptr = ptr->next;
    }
//    printf("The Number of Students in the Database is : %d",studentCount); TESTING
    return studentCount;
}

/************************************** AddEntry **************************************/


bool  SDB_AddEntry()
{
    if (SDB_IsFull() == true) {
        return false;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        return false; // Memory allocation failed
    }

    // Initialize New student datatype
    student newStudent;

    // Get student data from user
    printf("------------------ Fill Required Student Data ------------------\n");
    printf(" Student_ID : ");
    scanf("%u", &newStudent.Student_ID);

    // Check if Student ID exists before getting other inputs

    if(SDB_IsIdExist(newStudent.Student_ID)){
        printf("The Student ID : %d Exists in the database before .\n\n",newStudent.Student_ID);
        printf("************* Please Check IDs in the Database And Try again with Valid Id *************\n");
        return false;
    }
    else{
        printf(" Student_year : ");
        scanf("%u", &newStudent.Student_year);
        printf(" Course1_ID : ");
        scanf("%u", &newStudent.Course1_ID);
        printf(" Course1_grade : ");
        scanf("%u", &newStudent.Course1_grade);
        printf(" Course2_ID : ");
        scanf("%u", &newStudent.Course2_ID);
        printf(" Course2_grade : ");
        scanf("%u", &newStudent.Course2_grade);
        printf(" Course3_ID : ");
        scanf("%u", &newStudent.Course3_ID);
        printf(" Course3_grade : ");
        scanf("%u", &newStudent.Course3_grade);
    }



    // insert at beginning
    newNode->data = newStudent; // Saving newStudent in Data
    newNode->next = database; // saving last node address as NULL
    database = newNode; // Saving datbase address to new node
    return true;
}


/************************************** DeleteEntry **************************************/


void SDB_DeleteEntry(uint32 id) {
    Node * temp;

    /* database is empty */
    if(database == NULL)
    {
        printf("Database  is empty \n");
        return;
    }

    /* check if database have min number of students before delete */
    if(SDB_GetUsedSize() == MinStudents)
    {
        printf("!!!!!!!!!!!!!!!!!! Student Database have the Minimum Required Number of Students. You Cant Delete !!!!!!!!!!!!!!!!!!\n\n");
        return;
    }

    /* Delete the first Node at the List */
    if(database->data.Student_ID == id)
    {
        temp  = database;
        database = database->next;
        free(temp);
        printf("********* Student with ID %d is Deleted Successfully *********\n\n",id);
        return;
    }

    /* Delete in between the Nodes or at the end */
    Node * ptr = database;
    while(ptr->next != NULL)
    {
        if(ptr->next->data.Student_ID == id)
        {
            temp = ptr->next;
            break;
        }
        ptr = ptr->next;
    }

    if(ptr->next == NULL)
    {
        printf("Student of ID %d is not in the List\n\n",id);
    }
    else
    {
        ptr->next = temp -> next;
        free(temp);
        printf("********* Student with ID %d is Deleted Successfully *********\n\n",id);
    }



}


/************************************** ReadEntry **************************************/

bool SDB_ReadEntry(uint32 id)
{

    Node *ptr = database;

    // Lopping Until Finding ID

    while (ptr != NULL && ptr->data.Student_ID != id) {
        ptr = ptr->next;
    }

    // Display  Data from Given ID

    if (ptr != NULL) {
        printf("Student Year : %u \n",ptr->data.Student_year);
        printf("Course_1_ID : %u \n",ptr->data.Course1_ID);
        printf("Course_1_Grade : %u \n",ptr->data.Course1_grade);
        printf("Course_2_ID : %u \n",ptr->data.Course2_ID);
        printf("Course_1_Grade : %u \n",ptr->data.Course2_grade);
        printf("Course_3_ID : %u \n",ptr->data.Course3_ID);
        printf("Course_3_Grade : %u \n\n",ptr->data.Course3_grade);
        return true;
    }
    else
    {
        // If ID Not Found
        printf("Student with ID %d Not Found.\n", id);
        return false;
    }
}






/************************************** GetList **************************************/

void SDB_GetList(uint8 *count, uint32 *list) {

    Node *ptr = database; // pointer to start from database head and loop through database
    *count = 0;

    // Saving Student IDs in Array by Lopping the Database
    while(ptr != NULL){
        list[*count] = ptr->data.Student_ID;
        ptr = ptr -> next;
        (*count)++;
    }

}


/************************************** IsIdExist **************************************/

bool SDB_IsIdExist(uint32 id) {

    Node *ptr = database; // pointer to start from database head and loop through database

    // Lopping Until Finding ID
    while (ptr != NULL && ptr->data.Student_ID != id) {
        ptr = ptr->next;
    }

    // ID Found Return True
    if (ptr != NULL) {
        return true;

    }
    // ID Not Found Return False
    else
    {
        return false;
    }

}