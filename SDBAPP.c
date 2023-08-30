//
// Created by aabdu on 8/26/2023.
//
// Application Functions file

#include "STD.h"
#include "SDB.h"


enum {
    Exit,
    AddEntry ,
    UsedSize,
    ReadStudentData,
    ListIds,
    IdExist,
    DeleteData,
    IsDBFull
};



void SDB_APP()
{
    uint16 choice;

    // Database Initialization
    if(SDB_GetUsedSize() < MinStudents){

        printf("Please Enter First 3 Students to initialize database\n");
        for(uint8 i = 0; i < MinStudents; i++){
            SDB_AddEntry();
        }
    }

    do {
        printf("---------------------------- To Add entry, enter 1                       ---------------------------- \n");
        printf("---------------------------- To Get Used Size in Database, enter 2       ----------------------------\n");
        printf("---------------------------- To Read Student Data, enter 3               ----------------------------\n");
        printf("---------------------------- To Get the list of All Student IDs, enter 4 ----------------------------\n");
        printf("---------------------------- To Check is ID Exist, enter 5               ----------------------------\n");
        printf("---------------------------- To Delete Student Data, enter 6             ----------------------------\n");
        printf("---------------------------- To Check is Database is Full, enter 7       ----------------------------\n");
        printf("----------------------------          To Exit enter 0                    ----------------------------\n");
        printf("Enter Your choice : ");
        scanf("%hd",&choice);



        SDB_action(choice);
    } while (choice != 0);
}

void SDB_action(uint8 choice)
{

    uint8 usedSize;
    uint32 id ;
    uint8 count;
    uint32 idList[MaxStudents];
    uint32 checkId;
    uint32 deleteId;



    switch (choice) {
        case AddEntry:
            if (SDB_AddEntry()) {
                printf("********* Student is Added successfully *********\n\n");
            } else {
                printf("************* Student is not Added Please Try Again or Check Database Used size *************\n\n");
            }
            break;

        case UsedSize:
            usedSize = SDB_GetUsedSize();
            printf("********* The Number of Students in The Database is : %hhu *********\n\n", usedSize);
            break;

        case ReadStudentData:
            printf("Enter Student ID : ");
            scanf("%d",&id);
            printf("\n");
            printf("------------------ The Result For Searching  Student ID : %d ------------------\n", id);
            SDB_ReadEntry(id);
            break;

        case ListIds:

            SDB_GetList(&count, idList);
            printf("--------------------- Student ID List ---------------------\n");
            for (int8 i = count - 1; i >= 0; i--) {
                printf("%d\n",idList[i]);
            }

            break;

        case IdExist:

            printf("Please Enter Student ID You Want to Check : ");
            scanf("%d",&checkId);
            // SDB_IsIdExist(checkId);
            if(SDB_IsIdExist(checkId)){
                printf("The Student ID : %d Exists in the database.\n\n",checkId);
            }
            else{
                printf("The Student ID : %d does not Exist in the database.\n\n", checkId);
            }
            break;

        case DeleteData:
            printf("Please Enter Student ID You Want to Delete : ");
            scanf("%d",&deleteId);
            SDB_DeleteEntry(deleteId);
            break;

        case IsDBFull:
            if (SDB_IsFull()) {
                printf("-------------- DATABASE IS FULL --------------\n\n");
            } else {
                printf("-------------- DATABASE IS NOT FULL --------------\n\n");
            }
            break;

        case Exit:
            printf("/****************** Exiting ******************/\n\n");
            break;

        default:
            printf("---------------- INVALID CHOICE TRY AGAIN ----------------\n\n");
            break;
    }
}
