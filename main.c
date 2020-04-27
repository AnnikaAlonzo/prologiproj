//
//  main.c
//  OnlineTuitionFeePaymentAndScholarshipPre-Eval
//
//  Created by Annika Alonzo on 4/13/20.
//  Copyright ¬© 2020 Annika Alonzo. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include "studentIDCheck.h"
#include <string.h>

void studentLogin(void);
void option(void);
void payEnrollmentFees(void);
void scholarship(void);
int calculation(int, int, int, int);

int main(int argc, const char * argv[]) {
    
    printf("=====Online Tuition Fee Payment and Scholarship Pre-Evaluation=====\n");
    printf("%36s \n", "Welcome!");
    
    studentLogin();
    option();
    
    
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
    
    char userChoice;
    
    printf("\n----------------------------------------------------------------\n\n");
    printf("Choose an option: \n");
    printf("\t[1] Pay Enrollment Fees\n");
    printf("\t[2] Scholarship Pre-Evaluation\n");
    printf("\t[3] Exit\n");
    
    printf("\tInput choice: ");
    scanf("%s", &userChoice);
    
    switch(userChoice)
    {
        case '1':
            payEnrollmentFees();
            break;
            
        case '2':
            scholarship();
            break;
            
        case '3':
            printf("\n\nThank you for using our Online Tuition Fee Payment and Scholarship Pre-Evaluation!\n");
            break;
            
        default:
            printf("\n\nInvalid Input!");
            option();
            break;
            
    }
    
}

void payEnrollmentFees() {
    
    int numClasses, i;
    float installment = 0;
    char ch_arr[10], userInput, cardDetails, pinNum;
    const int totalFees = 16223;
    float tuition = 46852;
    int labFees = 0;
    bool class = false;

    
    printf("\n\n=====Pay Enrollment Fees=====\n\n");
    printf("You have chosen 'Pay Enrollment Fees'\n");
    
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
            tuition = calculation(labFees, tuition, totalFees, numClasses);
            
            tuitionCheck:
            system("\n");
            
            printf("\n\nYour tuition for next term will be: PHP %.2f\n", tuition);
            
            back:
            system("\n");
            
            printf("\n\nProceed to payment? [Y/N]");
            printf("\n\tChoice: ");
            scanf("%s", &userInput);
            
            if (userInput == 'Y' || userInput == 'y') {
                
                printf("\n----------------------------------------------------------------\n\n");
                printf("Please choose the method of transaction: ");
                printf("\n\t[1] Credit Card");
                printf("\n\t[2] Debit Card");
                printf("\n\tChoice: ");
                scanf("%s", &userInput);
                
                printf("\nPlease enter the card details: ");
                scanf("%s", &cardDetails);
                
                printf("\nPlease enter the pin number: ");
                scanf("%s", &pinNum);
                
                payment:
                system("\n");
                
                printf("\n\nChoose the method of payment: ");
                printf("\n\t[1] Full Payment");
                printf("\n\t[2] Installment Basis");
                printf("\n\tChoice: ");
                scanf("%s", &userInput);
                
                if (userInput == '1') {
                    
                    printf("\nYou have chosen ‘Full Payment’");
                    
                    fpayment:
                    system("\n");
                    
                    printf("\n\nTotal cost of tuition: PHP %.2f", tuition);
                    printf("\n\tConfirmation: Y/N");
                    printf("\n\tChoice: ");
                    scanf("%s", &userInput);
                    
                    if (userInput == 'Y' || userInput == 'y') {
                        
                        tuition -= tuition;
                        printf("\nRemaining balance is: PHP %.2f\n", tuition);
                        printf("\n\nThank you for using our Online Tuition Fee Payment and Scholarship Pre-Evaluation!\n");
                        break;
                        
                    } else if (userInput == 'N' || userInput == 'n') {
                        
                        goto tuitionCheck;
                        
                    } else {
                        
                        printf("\n\nInvalid Input!\n");
                        goto fpayment;
                        
                    }
                    
                } else if (userInput == '2') {
                    
                    printf("\nYou have chosen ‘Installment Basis’");
                    
                    ibasis:
                    system("\n");
                    
                    printf("\n\nChoose the amount you are going to pay: ");
                    printf("\n\t[1] 50 percent");
                    printf("\n\t[2] 60 percent");
                    printf("\n\tChoice: ");
                    scanf("%s", &userInput);
                    
                    if (userInput == '1') {
                        
                        installment = tuition - (tuition * .5);
                        printf("\nTotal cost of tuition: PHP %.2f", tuition);
                        printf("\n\tConfirmation: Y/N");
                        printf("\n\tChoice: ");
                        scanf("%s", &userInput);
                        
                        if (userInput == 'Y' || userInput == 'y') {
                            
                            printf("\nYou will be paying PHP %.2f upfront, and another PHP %.2f before or during the middle of the term.", installment, installment);
                            printf("\n\nRemaining balance is: PHP %.2f\n", tuition - installment);
                            printf("\n\nThank you for using our Online Tuition Fee Payment and Scholarship Pre-Evaluation!\n");
                            break;
                            
                        } else if (userInput == 'N' || userInput == 'n') {
                            
                            goto tuitionCheck;
                            
                        } else {
                            
                            printf("\n\nInvalid Input!\n");
                            goto ibasis;
                            
                        }
                    } else if (userInput == '2') {
                        
                        installment = tuition - (tuition * .6);
                        printf("\nTotal cost of tuition: PHP %.2f", tuition);
                        printf("\n\tConfirmation: Y/N");
                        printf("\n\tChoice: ");
                        scanf("%s", &userInput);
                        
                        if (userInput == 'Y' || userInput == 'y') {
                            
                            printf("\nYou will be paying PHP %.2f upfront, and another PHP %.2f before or during the middle of the term.", tuition - installment, installment);
                            printf("\n\nRemaining balance is: PHP %.2f\n", installment);
                            printf("\n\nThank you for using our Online Tuition Fee Payment and Scholarship Pre-Evaluation!\n");
                            break;
                            
                        } else if (userInput == 'N' || userInput == 'n') {
                            
                            goto tuitionCheck;
                            
                        } else {
                            
                            printf("\n\nInvalid Input!\n");
                            goto payment;
                            
                        }
                        
                    }
                    
                } else {
                    
                    printf("\n\nInvalid Input!\n");
                    goto payment;
                    
                }
                
                
            } else if (userInput == 'N' || userInput == 'n') {
                
                jump:
                system("\n");
                
                printf("\nWould you like to go back to the options menu? [Y/N]");
                printf("\n\tChoice: ");
                scanf("%s", &userInput);
                
                if (userInput == 'Y' || userInput == 'y') {
                    
                    option();
                    
                } else if (userInput == 'N' || userInput == 'n') {
                    
                    printf("\n\nThank you for using our Online Tuition Fee Payment and Scholarship Pre-Evaluation!\n");
                    break;
                    
                } else {
                    
                    printf("\nInvalid Input!");
                    goto jump;
                    
                }
                
            } else {
                
                printf("\nInvalid Input!");
                goto back;
                
            }
            
        } else {
            
            printf("The minimum number of classes is 8 and the maximum is 10.\n");
            
        }
        
    }
}

int calculation(int a, int b, int c, int numClasses) {
    
    int total = 0;
    
    if (numClasses == 8) {
        
        total = a + b + c;
        
    } else if (numClasses == 9) {
        
        b += 10812;
        total = a + b + c;
        
    } else {
        
        b += 21624;
        total = a + b + c;
        
    }
    
    return total;

}


void scholarship()
{
    int choice, income;
    char yesNo;

    printf("\n\n=====Scholarship Pre-Evaluation=====\n\n");
    printf("\nYou have chosen Scholarship Pre-Evaluation\n");
    jump:
    system("\n");
    

    printf("\n----------------------------------------------------------------------\n\n");
    printf("||                                                                   ||\n");
    printf("||                              Programs                             ||\n");
    printf("||                                                                   ||\n");
    printf("||    1     Br. Andrew Gonzalez Academic Scholarship                 ||\n");
    printf("||    2     Archer Achiever Scholarship                              ||\n");
    printf("||    3     St. La Salle Financial Assistance Grant                  ||\n");
    printf("||    4     The Star Scholars Program                                ||\n");
    printf("||    5     Vaugirard Scholarship Program                            ||\n");
    printf("||    6     Gokongwei Grants                                         ||\n");
    printf("||    7     Brother President Scholarship Program (BPSP)             ||\n");
    printf("||    8     Centennial Scholarship Program (CSP)                     ||\n");
    printf("||    9     Scholarship for Children of Faculty (SCF)                ||\n");
    printf("||    10    Scholarship for Children of Co-Academic Personnel (SCC)  ||\n");
    printf("||    11    Military Scholarship (PD 577)                            ||\n");
    printf("||                                                                   ||\n");
    printf("\n----------------------------------------------------------------------\n");
    
    printf("\n\nWhich Scholarship Program would you like to apply for? \n");
    printf("\tChoice: ");
    scanf("%d", &choice);
    

    switch(choice)
    {
        case 1:
            printf("\nYou have chosen Br. Andrew Gonzalez Academic Scholarship!\n\n");
            printf("This Scholarship Program is granted to High school students who");
            printf(" ranked Top 1 (with highest honors) for each strand");
            printf(" (STEM, ABM, HUMMS) of La Salle district schools and have passed");
            printf(" the entrance exam will be awarded a full academic scholarship");
            printf(" (tuition and fees) starting in their freshman year.");
            
            printf("\n\nWere you ranked top 1 (with highest honors) for STEM/ABM/HUMMS in a La Salle district high school? [Y/N]");
            printf("\n\tChoice: ");
            scanf("%s", &yesNo);
                
            if ((yesNo == 'Y') || (yesNo == 'y'))
            {
                printf("\n\nDid you pass the entrance exam? [Y/N]");
                printf("\n\tChoice: ");
                scanf("%s", &yesNo);
                
                if ((yesNo == 'Y') || (yesNo == 'y'))
                {
                    printf("\nYou are qualified for this scholarship, you may proceed to securing the application portion!\n");
                    break;
                }
                else if ((yesNo == 'N') || (yesNo == 'n'))
                {
                    printf("\nYou are not qualified for this scholarship.");
                    
                    printf("\n\nWould you like to look at another scholarship program? [Y/N]");
                    printf("\n\tChoice: ");
                    scanf("%s", &yesNo);
                    
                    if ((yesNo == 'Y') || (yesNo == 'y'))
                    {
                        
                        goto jump;
                        
                    }
                    else if ((yesNo == 'N') || (yesNo == 'n'))
                    {
                        
                        printf("\n\nThank you for using our Online Tuition Fee Payment and Scholarship Pre-Evaluation!\n");
                        break;
                        
                    }
                }
            }
            else if ((yesNo == 'N') || (yesNo == 'n'))
                {
                    printf("\nYou are not qualified for this scholarship.");
                    
                    printf("\n\nWould you like to look at another scholarship program? [Y/N]");
                    printf("\n\tChoice: ");
                    scanf("%s", &yesNo);
                    
                    if ((yesNo == 'Y') || (yesNo == 'y'))
                    {
                        
                        goto jump;
                        
                    }
                    else if ((yesNo == 'N') || (yesNo == 'n'))
                    {
                        
                        printf("\n\nThank you for using our Online Tuition Fee Payment and Scholarship Pre-Evaluation!\n");
                        break;
                        
                    }
                }
            
        case 2:
            printf("\nYou have chosen Archer Achievers Scholarship!\n\n");
            printf("This Scholarship Program is granted to students who top the DLSU");
            printf(" College Admission Test. Qualified students will be automatically");
            printf(" awarded full tuition and fee waiver.This is available for");
            printf(" students who graduated from Philippine Private/Public and Science High Schools.");
            printf("\n\nRequirements:\n1. Must be among the top examinees from");
            printf(" a Philippine Private/Public and Science High Schools based on");
            printf(" the Weighted Admission.");
            printf("\n2. Must be a Filipino citizen.");
            
            printf("\n\nDid you graduate from a Philippine Private/Public school or a Science High School?  [Y/N]");
            printf("\n\tChoice: ");
            scanf("%s", &yesNo);
            
            if ((yesNo == 'Y') || (yesNo == 'y'))
            {
                printf("\nAre you among the top examinees of the DLSU College Admission Test?  [Y/N]");
                printf("\n\tChoice: ");
                scanf("%s", &yesNo);
                
                if ((yesNo == 'Y') || (yesNo == 'y'))
                {
                    printf("\nAre you a Filipino Citizen? [Y/N]");
                    printf("\n\tChoice: ");
                    scanf("%s", &yesNo);
                    
                    if ((yesNo == 'Y') || (yesNo == 'y'))
                    {
                        printf("\nYou are qualified for this scholarship, you may proceed to securing the application portion!\n");
                        break;
                    }
                    else if ((yesNo == 'N') || (yesNo == 'n'))
                    {
                        printf("\nYou are not qualified for this scholarship.");
                        
                        printf("\n\nWould you like to look at another scholarship program? [Y/N]");
                        printf("\n\tChoice: ");
                        scanf("%s", &yesNo);
                        
                        if ((yesNo == 'Y') || (yesNo == 'y'))
                        {
                            
                            goto jump;
                            
                        }
                        else if ((yesNo == 'N') || (yesNo == 'n'))
                        {
                            
                            printf("\n\nThank you for using our Online Tuition Fee Payment and Scholarship Pre-Evaluation!\n");
                            break;
                            
                        }
                    }
                }
                else if ((yesNo == 'N') || (yesNo == 'n'))
                    {
                    printf("\nYou are not qualified for this scholarship.");
                    
                    printf("\n\nWould you like to look at another scholarship program? [Y/N]");
                    printf("\n\tChoice: ");
                    scanf("%s", &yesNo);
                    
                    if ((yesNo == 'Y') || (yesNo == 'y'))
                    {
                        
                        goto jump;
                        
                    }
                    else if ((yesNo == 'N') || (yesNo == 'n'))
                    {
                        
                        printf("\n\nThank you for using our Online Tuition Fee Payment and Scholarship Pre-Evaluation!\n");
                        break;
                        
                    }
                }
            }
            else if ((yesNo == 'N') || (yesNo == 'n'))
                {
                    printf("\nYou are not qualified for this scholarship.");
                    
                    printf("\n\nWould you like to look at another scholarship program? [Y/N]");
                    printf("\n\tChoice: ");
                    scanf("%s", &yesNo);
                    
                    if ((yesNo == 'Y') || (yesNo == 'y'))
                    {
                        
                        goto jump;
                        
                    }
                    else if ((yesNo == 'N') || (yesNo == 'n'))
                    {
                        
                        printf("\n\nThank you for using our Online Tuition Fee Payment and Scholarship Pre-Evaluation!\n");
                        break;
                        
                    }
                }
            
        case 3:
            printf("\nYou have chosen St. La Salle Financial Assistance Grant!\n\n");
            printf("This Scholarship Program is granted to Filipino students who meet");
            printf("specific criteria for eligibility: ");
            printf("\n1. Financial Need. Only those whose annual family income is PhP 700,000 and below will be considered.");
            printf("\n2. Academic Competence. The Committee will take into");
            printf(" consideration the applicants high school grades and DLSU College");
            printf(" Admission Test (DLSU CAT) results.");
            
            printf("\n\nWhat is your annual family income? ");
            scanf("%d", &income);
            
            if (income < 700000)
            {
                printf("\nYou are qualified for this scholarship, you may proceed to securing the application portion!\n");
                break;
            }
            else
            {
                printf("\nYou are not qualified for this scholarship.");
                
                printf("\n\nWould you like to look at another scholarship program? [Y/N]");
                printf("\n\tChoice: ");
                scanf("%s", &yesNo);
                
                if ((yesNo == 'Y') || (yesNo == 'y'))
                {
                    
                    goto jump;
                    
                }
                else if ((yesNo == 'N') || (yesNo == 'n'))
                {
                    
                    printf("\n\nThank you for using our Online Tuition Fee Payment and Scholarship Pre-Evaluation!\n");
                    break;
                    
                }
            }
            
        case 4:
            printf("\nYou have chosen The Star Scholars Program!\n\n");
            printf("This Scholarship Program is granted to those high-achieving");
            printf(" students from around the country. Students selected for the");
            printf(" program have the unique opportunity to earn a masters degree or");
            printf(" go into medicine proper (BS Human Biology students) or enroll in");
            printf(" the College of Law on full scholarship after finishing their undergraduate degree.");
            
            printf("\n\nDo you fit into this Scholarship Program? [Y/N]");
            printf("\n\tChoice: ");
            scanf("%s", &yesNo);
            
            if ((yesNo == 'Y') || (yesNo == 'y'))
            {
                printf("\nYou are qualified for this scholarship, you may proceed to securing the application portion!\n");
                break;
            }
            else if ((yesNo == 'N') || (yesNo == 'n'))
            {
                printf("\nYou are not qualified for this scholarship.");
                
                printf("\n\nWould you like to look at another scholarship program? [Y/N]");
                printf("\n\tChoice: ");
                scanf("%s", &yesNo);
                
                if ((yesNo == 'Y') || (yesNo == 'y'))
                {
                    
                    goto jump;
                    
                }
                else if ((yesNo == 'N') || (yesNo == 'n'))
                {
                    
                    printf("\n\nThank you for using our Online Tuition Fee Payment and Scholarship Pre-Evaluation!\n");
                    break;
                    
                }
            }
            
        case 5:
            printf("\nYou have chosen the Vaugirard Scholarship Program!\n\n");
            printf("This Scholarship Program is granted to those students who");
            printf(" graduated from Philippine public high schools. The scholarship");
            printf(" program provides an opportunity for these students to access the");
            printf(" Lasallian education through any baccalaureate degree program at DLSU.");
            
            printf("\n\nDid you graduate from a public secondary school? [Y/N]");
            printf("\n\tChoice: ");
            scanf("%s", &yesNo);
            
            if ((yesNo == 'Y') || (yesNo == 'y'))
            {
                printf("\nYou are qualified for this scholarship, you may proceed to securing the application portion!\n");
                break;
            }
            else if ((yesNo == 'N') || (yesNo == 'n'))
            {
                printf("\nYou are not qualified for this scholarship.");
                
                printf("\n\nWould you like to look at another scholarship program? [Y/N]");
                printf("\n\tChoice: ");
                scanf("%s", &yesNo);
                
                if ((yesNo == 'Y') || (yesNo == 'y'))
                {
                    
                    goto jump;
                    
                }
                else if ((yesNo == 'N') || (yesNo == 'n'))
                {
                    
                    printf("\n\nThank you for using our Online Tuition Fee Payment and Scholarship Pre-Evaluation!\n");
                    break;
                    
                }
            }
            
        case 6:
            printf("\nYou have chosen the Gokongwei Grants!\n\n");
            printf("This Scholarship Program is granted to students who wish to");
            printf(" pursue priority fields of study in any undergraduate engineering");
            printf(" degree program as offered by the college. The scholarship");
            printf(" privileges are full tuition and fees waiver, monthly stipend, and book allowance.");
            
            printf("\n\nDo you wish to pursue a field of study in any undergraduate engineering degree program as offered by the college? [Y/N]");
            printf("\n\tChoice: ");
            scanf("%s", &yesNo);
            
            if ((yesNo == 'Y') || (yesNo == 'y'))
            {
                printf("\nYou are qualified for this scholarship, you may proceed to securing the application portion!\n");
                break;
            }
            else if ((yesNo == 'N') || (yesNo == 'n'))
            {
                printf("\nYou are not qualified for this scholarship.");
                
                printf("\n\nWould you like to look at another scholarship program? [Y/N]");
                printf("\n\tChoice: ");
                scanf("%s", &yesNo);
                
                if ((yesNo == 'Y') || (yesNo == 'y'))
                {
                    
                    goto jump;
                    
                }
                else if ((yesNo == 'N') || (yesNo == 'n'))
                {
                    
                    printf("\n\nThank you for using our Online Tuition Fee Payment and Scholarship Pre-Evaluation!\n");
                    break;
                    
                }
            }
            
        case 7:
            printf("\nYou have chosen the Brother President Scholarship Program (BPSP)!\n\n");
            printf("This program is awarded to the legitimate or legally-adopted");
            printf(" children of married, permanent and full-time faculty, and");
            printf(" administrative service personnel who joined DLSU in May 1987 or");
            printf(" after and have served the University for at least three years");
            printf(" and are in active University Service while availing of the grant.");
            printf("\n\nThese students should have passed the entrance requirements of");
            printf(" La Salle Green Hills, De La Salle-Santiago Zobel School, De La");
            printf(" Salle-Canlubang, De La Salle-Araneta University, De La Salle");
            printf(" University-Dasmarinas, De La Salle-College of St. Benilde, or De");
            printf(" La Salle University.");
            
            printf("\n\nDo you have parents that are permanent and full-time faculty or administrative service personnel who joined DLSU in May 1987 or after and have served the University for at least three years and are in active University Service? [Y/N]");
            printf("\n\tChoice: ");
            scanf("%s", &yesNo);
            
            if ((yesNo == 'Y') || (yesNo == 'y'))
            {
                printf("\nHave you passed in any of the schools listed above? ");
                printf("\n\tChoice: ");
                scanf("%s", &yesNo);
                
                if ((yesNo == 'Y') || (yesNo == 'y'))
                {
                    printf("\nYou are qualified for this scholarship, you may proceed to securing the application portion!\n");
                    break;
                }
                else if ((yesNo == 'N') || (yesNo == 'n'))
                {
                    printf("\nYou are not qualified for this scholarship.");
                    
                    printf("\n\nWould you like to look at another scholarship program? [Y/N]");
                    printf("\n\tChoice: ");
                    scanf("%s", &yesNo);
                    
                    if ((yesNo == 'Y') || (yesNo == 'y'))
                    {
                        
                        goto jump;
                        
                    }
                    else if ((yesNo == 'N') || (yesNo == 'n'))
                    {
                        
                        printf("\n\nThank you for using our Online Tuition Fee Payment and Scholarship Pre-Evaluation!\n");
                        break;
                        
                    }
                }
            }
            else if ((yesNo == 'N') || (yesNo == 'n'))
            {
                printf("\nYou are not qualified for this scholarship.");
                
                printf("\n\nWould you like to look at another scholarship program? [Y/N]");
                printf("\n\tChoice: ");
                scanf("%s", &yesNo);
                
                if ((yesNo == 'Y') || (yesNo == 'y'))
                {
                    
                    goto jump;
                    
                }
                else if ((yesNo == 'N') || (yesNo == 'n'))
                {
                    
                    printf("\n\nThank you for using our Online Tuition Fee Payment and Scholarship Pre-Evaluation!\n");
                    break;
                    
                }
            }
            
        case 8:
            printf("\nYou have chosen Centennial Scholarship Program (CSP)!\n\n");
            printf("This program was formulated to provide scholarships to qualified");
            printf(" children of full-time permanent faculty (teaching and academic");
            printf(" service faculty) and administrative service personnel (ASP) of the");
            printf(" University. Children of permanent and full-time faculty and ASP");
            printf(" must have passed the DLSU entrance requirements in order to");
            printf(" qualify for the scholarship that is only offered at DLSU-Manila.");
            
            printf("\n\nDo you have (a) parent(s) that are full-time permanent faculty of the university? [Y/N]");
            printf("\n\tChoice: ");
            scanf("%s", &yesNo);
            
            if ((yesNo == 'Y') || (yesNo == 'y'))
            {
                printf("\nHave you passed the DLSU entrance requirements? ");
                printf("\n\tChoice: ");
                scanf("%s", &yesNo);
                
                if ((yesNo == 'Y') || (yesNo == 'y'))
                {
                    printf("\nYou are qualified for this scholarship, you may proceed to securing the application portion!\n");
                    break;
                }
                else if ((yesNo == 'N') || (yesNo == 'n'))
                {
                    printf("\nYou are not qualified for this scholarship.");
                    
                    printf("\n\nWould you like to look at another scholarship program? [Y/N]");
                    printf("\n\tChoice: ");
                    scanf("%s", &yesNo);
                    
                    if ((yesNo == 'Y') || (yesNo == 'y'))
                    {
                        
                        goto jump;
                        
                    }
                    else if ((yesNo == 'N') || (yesNo == 'n'))
                    {
                        
                        printf("\n\nThank you for using our Online Tuition Fee Payment and Scholarship Pre-Evaluation!\n");
                        break;
                        
                    }
                }
            }
            else if ((yesNo == 'N') || (yesNo == 'n'))
            {
                printf("\nYou are not qualified for this scholarship.");
                
                printf("\n\nWould you like to look at another scholarship program? [Y/N]");
                printf("\n\tChoice: ");
                scanf("%s", &yesNo);
                
                if ((yesNo == 'Y') || (yesNo == 'y'))
                {
                    
                    goto jump;
                    
                }
                else if ((yesNo == 'N') || (yesNo == 'n'))
                {
                    
                    printf("\n\nThank you for using our Online Tuition Fee Payment and Scholarship Pre-Evaluation!\n");
                    break;
                    
                }
            }
            
        case 9:
            printf("\nYou have chosen the Scholarship for Children of Faculty (SCF)!\n\n");
            printf("This scholarship is granted to qualified children of full-time,");
            printf(" part-time, and retired faculty members who joined DLSU before May");
            printf(" 1987. Their children must have passed the entrance requirements");
            printf(" of DLSU, De La Salle-College of St. Benilde, La Salle Green Hills,");
            printf(" or De La Salle Santiago-Zobel School.");
            
            printf("\n\nDo you have a parent that is a full-time, part-time, or retired faculty member who joined DLSU before May 1987? [Y/N]");
            printf("\n\tChoice: ");
            scanf("%s", &yesNo);
            
            if ((yesNo == 'Y') || (yesNo == 'y'))
            {
                printf("\nHave you passed the entrance requirements of any of the schools listed above? ");
                printf("\n\tChoice: ");
                scanf("%s", &yesNo);
                
                if ((yesNo == 'Y') || (yesNo == 'y'))
                {
                    printf("\nYou are qualified for this scholarship, you may proceed to securing the application portion!\n");
                    break;
                }
                else if ((yesNo == 'N') || (yesNo == 'n'))
                {
                    printf("\nYou are not qualified for this scholarship.");
                    
                    printf("\n\nWould you like to look at another scholarship program? [Y/N]");
                    printf("\n\tChoice: ");
                    scanf("%s", &yesNo);
                    
                    if ((yesNo == 'Y') || (yesNo == 'y'))
                    {
                        
                        goto jump;
                        
                    }
                    else if ((yesNo == 'N') || (yesNo == 'n'))
                    {
                        
                        printf("\n\nThank you for using our Online Tuition Fee Payment and Scholarship Pre-Evaluation!\n");
                        break;
                        
                    }
                }
            }
            else if ((yesNo == 'N') || (yesNo == 'n'))
            {
                printf("\nYou are not qualified for this scholarship.");
                
                printf("\n\nWould you like to look at another scholarship program? [Y/N]");
                printf("\n\tChoice: ");
                scanf("%s", &yesNo);
                
                if ((yesNo == 'Y') || (yesNo == 'y'))
                {
                    
                    goto jump;
                    
                }
                else if ((yesNo == 'N') || (yesNo == 'n'))
                {
                    
                    printf("\n\nThank you for using our Online Tuition Fee Payment and Scholarship Pre-Evaluation!\n");
                    break;
                    
                }
            }
            
        case 10:
            printf("\nYou have chosen the Scholarship for Children of Co-Academic Personnel (SCC)!\n\n");
            printf("This scholarship is awarded to dependents of Co-Academic Personnel.");
            printf(" Their children should have passed the entrance requirements of De La Salle University.");
            
            printf("\n\nAre you a dependent of a Co-Academic Personnel? [Y/N]");
            printf("\n\tChoice: ");
            scanf("%s", &yesNo);
            if ((yesNo == 'Y') || (yesNo == 'y'))
            {
                printf("\nHave you passed the entrance requirements in De La Salle University? [Y/N]");
                printf("\n\tChoice: ");
                scanf("%s", &yesNo);
                
                if ((yesNo == 'Y') || (yesNo == 'y'))
                {
                    printf("\nYou are qualified for this scholarship, you may proceed to securing the application portion!\n");
                    break;
                }
                else if ((yesNo == 'N') || (yesNo == 'n'))
                {
                    printf("\nYou are not qualified for this scholarship.");
                    
                    printf("\n\nWould you like to look at another scholarship program? [Y/N]");
                    printf("\n\tChoice: ");
                    scanf("%s", &yesNo);
                    
                    if ((yesNo == 'Y') || (yesNo == 'y'))
                    {
                        
                        goto jump;
                        
                    }
                    else if ((yesNo == 'N') || (yesNo == 'n'))
                    {
                        
                        printf("\n\nThank you for using our Online Tuition Fee Payment and Scholarship Pre-Evaluation!\n");
                        break;
                        
                    }
                }
            }
            else if ((yesNo == 'N') || (yesNo == 'n'))
            {
                printf("\nYou are not qualified for this scholarship.");
                
                printf("\n\nWould you like to look at another scholarship program? [Y/N]");
                printf("\n\tChoice: ");
                scanf("%s", &yesNo);
                
                if ((yesNo == 'Y') || (yesNo == 'y'))
                {
                    
                    goto jump;
                    
                }
                else if ((yesNo == 'N') || (yesNo == 'n'))
                {
                    
                    printf("\n\nThank you for using our Online Tuition Fee Payment and Scholarship Pre-Evaluation!\n");
                    break;
                    
                }
            }
            
        case 11:
            printf("\nYou have chosen the Military Scholarship (PD 577)!\n\n");
            printf("This scholarship program is for those who are dependents of");
            printf(" military personnel who died or became incapacitated in the line");
            printf(" of duty. Scholars in this program will be exempted from the payment of tuition.");
            
            printf("\n\nDo you have any relative who are military personnel who died or became incapacitated in the line of duty? [Y/N]");
            printf("\n\tChoice: ");
            scanf("%s", &yesNo);
            
            if ((yesNo == 'Y') || (yesNo == 'y'))
            {
                printf("\nYou are qualified for this scholarship, you may proceed to securing the application portion!\n");
                break;
            }
            else if ((yesNo == 'N') || (yesNo == 'n'))
            {
                printf("\nYou are not qualified for this scholarship.");
                
                printf("\n\nWould you like to look at another scholarship program? [Y/N]");
                printf("\n\tChoice: ");
                scanf("%s", &yesNo);
                
                if ((yesNo == 'Y') || (yesNo == 'y'))
                {
                    
                    goto jump;
                    
                }
                else if ((yesNo == 'N') || (yesNo == 'n'))
                {
                    
                    printf("\n\nThank you for using our Online Tuition Fee Payment and Scholarship Pre-Evaluation!\n");
                    break;
                    
                }
            }
            
        default:
            printf("\nInvalid Input!\nPlease Try Again!\n");
            goto jump;
            break;
        }

}
