//
//  tuitionCalculation.h
//  OnlineTuitionFeePaymentAndScholarshipPre-Eval
//
//  Created by Annika Alonzo on 4/23/20.
//  Copyright © 2020 Annika Alonzo. All rights reserved.
//

#ifndef tuitionCalculation_h
#define tuitionCalculation_h
#include <string.h>

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




#endif /* tuitionCalculation_h */
