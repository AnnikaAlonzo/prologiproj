//
//  main.c
//  OnlineTuitionFeePaymentAndScholarshipPre-Eval
//
//  Created by Annika Alonzo on 4/13/20.
//  Copyright © 2020 Annika Alonzo. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include "studentIDCheck.h"

void studentLogin(void);
void option(void);

int main(int argc, const char * argv[]) {
    
    printf("=====Online Tuition Fee Payment and Scholarship Pre-Evaluation=====\n");
    printf("%36s \n", "Welcome!");
    
    studentLogin();
    option();
    
    printf("end\n");
    
}

void studentLogin() {
    
    char name[100], email[100];
    int studentID;
    bool id = false;
    
    printf("\nPlease input the following: \n\n");
    printf("\tName: ");
    fgets(name, sizeof(name), stdin);
    
    while(id == false) {
        printf("\tStudent ID: ");
        scanf("%d", &studentID);
        
        if (check_id(studentID)) {
            
            printf("\tStudent Email: ");
            scanf("%s", email);
            printf("\nWelcome %s", name);
            id = true;
            
        } else {
            
            printf("\tThat is not a valid student ID. \n\n");
            
        }
    
    }
}

void option() {
    
    int userChoice;
    
    printf("\n----------------------------------------------------------------\n\n");
    printf("Choose an option: \n");
    printf("\t[1] Pay Enrollment Fees\n");
    printf("\t[2] Scholarship Pre-Evaluation\n");
    printf("\t[3] Exit\n");
    
    printf("\tInput choice: ");
    scanf("%d", &userChoice);
    
}

