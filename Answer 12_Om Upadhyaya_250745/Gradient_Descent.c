#include <stdio.h>
#include <math.h>

int M = 0, C = 0;

float grad_descent(int rows, float * X, float * Y, float L){

    float m = 0.0, c = 0.0, J = 0.0, J_old = 0.0, J_new = 0.0;

    /*
    Calculate yi(pred) = h(xi) = mxi + c
    Calculate J = (1/2)sum((h(xi) - yi)^2)
    Update m := m - Lsum((h(xi)-yi)*xi)
    Update c := c - Lsum((h(xi)-yi))
    Repeat. Check if J is getting lower. If yes, then repeat until J < 0.1.
    */
    for (int i = 0; i < rows; i++){
        J = J + 0.5*((m*X[i] + c - Y[i]) * (m*X[i] + c - Y[i]));
    }
    printf("Initial J = %f", J);

        J_old = J;
        J_new = 0;
        while (fabs(J_new - J_old) > 0.001){
            J_old = J_new;
            float dm = 0.0, dc = 0.0;
            for(int i = 0; i <rows; i++){
                dm = dm - (m*X[i] + c - Y[i]) * X[i];
                dc = dc - (m*X[i] + c - Y[i]);
        }
            m -= L * dm;
            c -= L * dc;
            J_new = 0;
            for (int i = 0; i < rows; i++){
                J_new = J_new + 0.5*((m*X[i] + c - Y[i]) * (m*X[i] + c - Y[i]));
            }
        }
    M = m;
    C = c;
}

void Test(float * test_x, float * test_y, int rows){
    float J = 0;
    int trues = 0, falses = 0;
    for (int i < 0; i < rows; i++){
        pred = M * test_x[i] + C;

        J = J + 0.5*((pred - test_y[i]) * (pred - test_y[i]));
    }
    printf("\nLoss: %f", J);
}