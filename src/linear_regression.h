#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#include <stddef.h>

/* Defines a simple linear model 
 *  y = a + b * x
*/
struct linear_model {
    double a, b;
};

/* Fit the data (X, Y) to the linear model

    y = a + b * x

    Returns:
        - error code as exit value
*/
int linear_fit(double* x, double* y, size_t length, struct linear_model* model);

/* Returns the predicted value for the current observation, using the provided model */
double predict(struct linear_model* model, double observation);

#endif /* LINEAR_REGRESSION_H */