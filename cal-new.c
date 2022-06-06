#include <stdio.h>
#include <string.h>
#include "function.h"

int cal(int commandNum, int var1, int var2) {


        if (commandNum == 1){
            solve_quadratic(var1,var2);
        }
        else if (commandNum == 2){
            find_triples(var1,var2);
        }
        else{
            modular_sum(var1,var2);
        }
    
    return 0;
}
