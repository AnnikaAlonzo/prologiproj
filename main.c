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
#include "tuitionCalculation.h"

void studentLogin(void);
void option(void);
void payEnrollmentFees(void);

int main(int argc, const char * argv[]) {
    
    printf("=====Online Tuition Fee Payment and Scholarship Pre-Evaluation=====\n");
    printf("%36s \n", "Welcome!");
    
    studentLogin();
    option();
    payEnrollmentFees();
    
    printf("end\n");
    
}

void studentLogin() {
    
    char name[100], email[100];
    int studentID;
    bool id = false;
    
    printf("\nPlease input the following: \n\n");
    printf("\tName: ");
    fgets(name, sizeof(name), stdin);
    
    while (id == false) {
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

void payEnrollmentFees() {
    
    int numClasses, i;
    char ch_arr[10];
    const int totalFees = 16223;
    int tuition = 46852;
    int labFees = 0;
    bool class = false;

    
    printf("\n\n=====Pay Enrollment Fees=====\n\n");
    printf("You have chosen ‘Pay Enrollment Fees’\n");
    
    while (class == false) {
        
        printf("\n\nHow many courses will you be taking next term?");
        printf("\nInput: ");
        scanf("%d", &numClasses);
        
        if (numClasses >= 8 && numClasses <= 10) {
            
            printf("\n\nPlease list down the courses you are taking: ");
            
            for (i = 0; i < numClasses; i++){
            
                printf("\n> ");
                scanf("%s", &ch_arr[i]);
                
                if (strcmp(&ch_arr[i], "lby") != 0 && strcmp(&ch_arr[i], "LBY") != 0){
                    
                    labFees += 0;
                    
                } else{
                    
                    labFees += 3600;
                    
                }
                
            }
            class = true;
            calculation(labFees, tuition, totalFees, numClasses);
            
            
            printf("\n\nYour tuition for next term will be: ₱%d\n", calculation(labFees, tuition, totalFees, numClasses));
            
        } else {
            
            printf("The minimum number of classes is 8 and the maximum is 10.\n");
            
        }
        
    }
}
