#include "linear_regression.h"

int linear_fit(double* x, double* y, size_t length, struct linear_model* model) {

    double sums_x = 0;
    double sums_x2 = 0;
    double sums_y = 0;
    double sums_xy = 0;

    model->a = 0;
    model->b = 0;

    for(unsigned int i = 0; i < length; i++) {
        sums_x  += x[i];
        sums_x2 += x[i] * x[i];
        sums_y  += y[i];
        sums_xy += x[i] * y[i]; 
    }

    model->b = (length * sums_xy - sums_x * sums_y) / (length * sums_x2 - sums_x * sums_x);
    model->a = (sums_y - (model->b) * sums_x) / length;

    return 0;
}

double predict(struct linear_model *model, double observation) {
    return model->a + model->b * observation;
}