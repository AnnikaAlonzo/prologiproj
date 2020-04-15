//
//  studentIDCheck.h
//  OnlineTuitionFeePaymentAndScholarshipPre-Eval
//
//  Created by Annika Alonzo on 4/13/20.
//  Copyright © 2020 Annika Alonzo. All rights reserved.
//

#ifndef studentIDCheck_h
#define studentIDCheck_h

#include <stdio.h>
#include <math.h>


int accumulate (int previous_acc, int current_input, int current_factor) {
    
    int sum = previous_acc + (current_input * current_factor);
    return sum;

}

int get_last_digit(int number) {
    
    int last_digit = number % 10;
    return last_digit;

}

int get_last_kth_digit(int number, int k) {
    
    int f = number / pow(10, k - 1);
    int last_kth_digit = get_last_digit(f);
    return last_kth_digit;

}

int weighted_sum_ID(int ID_number, int num_digit) {
    
    int sum = 0, currentNum;
    
    for (int i = 1; i <= num_digit; i++) {
        
        currentNum = get_last_kth_digit(ID_number, i);
        sum = accumulate(sum, currentNum, i);
        
    }
    
    return sum;

}

int verify_sum(int sum_of_ID_number, int secret_key) {
    
    if ((sum_of_ID_number % secret_key) == 0) {
        
        return 1;
        
    } else {
        
        return 0;
        
    }
    
}

int check_id(int id_number) {

    int idSum = weighted_sum_ID(id_number, 8);
    
    return verify_sum(idSum, 11);
    
}



#endif /* studentIDCheck_h */
