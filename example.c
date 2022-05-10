#include <stddef.h>
#include <stdio.h>

#include "linear_regression.h"

int main() {
    // Some example data
    size_t data_length = 4;

    double obs_y[4] = {  53,     63,     68,   68.6};
    double obs_x[4] = {1.95,   1.57,   1.40,   1.38};

    struct linear_model model;

    double predition = 0;
    double observation = 1.35;
   
   int res = linear_fit(obs_x, obs_y, data_length, &model);

    // y = a + b x

    predition = predict(&model, observation);

    printf("======= Input data =========\n");
    printf("X: ");
    for (int i = 0; i < data_length; i++) {
        printf("%f\t", obs_x[i]);
    }
    printf("\n");

    printf("Y: ");
    for (int i = 0; i < data_length; i++) {
        printf("%f\t", obs_y[i]);
    }
    printf("\n");

    printf("========== Results =========\n");
    printf("Best fit: y = %g + %g X\n", model.a, model.b);
    printf("Predition for %f => %f\n", observation, predition);
    printf("============================\n");

    return 0;
}