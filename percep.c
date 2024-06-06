#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEARNING_RATE 0.1
#define N_ITER 1000

typedef struct Perceptron {
    double *weights;
    double bias;
    int n_features;
} Perceptron;

Perceptron *create_perceptron(int n_features) {
    Perceptron *p = (Perceptron *)malloc(sizeof(Perceptron));
    p->n_features = n_features;
    p->weights = (double *)malloc(n_features * sizeof(double));
    p->bias = 0.0;

    // Initialize weights to small random values
    srand(time(NULL));
    for (int i = 0; i < n_features; i++) {
        p->weights[i] = (double)rand() / RAND_MAX - 0.5;
    }

    return p;
}

int activation_function(double x) {
    return x >= 0.0 ? 1 : 0;
}

void fit(Perceptron *p, double **X, int *y, int n_samples) {
    for (int i = 0; i < N_ITER; i++) {
        for (int s = 0; s < n_samples; s++) {
            double weighted_sum = p->bias;
            for (int f = 0; f < p->n_features; f++) {
                weighted_sum += p->weights[f] * X[s][f];
            }

            int prediction = activation_function(weighted_sum);
            int error = y[s] - prediction;

            // Update weights and bias
            for (int f = 0; f < p->n_features; f++) {
                p->weights[f] += LEARNING_RATE * error * X[s][f];
            }
            p->bias += LEARNING_RATE * error;
        }
    }
}

int predict(Perceptron *p, double *x) {
    double weighted_sum = p->bias;
    for (int i = 0; i < p->n_features; i++) {
        weighted_sum += p->weights[i] * x[i];
    }
    return activation_function(weighted_sum);
}

void free_perceptron(Perceptron *p) {
    free(p->weights);
    free(p);
}

int main() {
    // Example dataset: OR function
    int n_samples = 4;
    int n_features = 2;
    double X[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    int y[4] = {0, 1, 1, 1};

    // Convert array to pointers
    double *X_ptr[4];
    for (int i = 0; i < 4; i++) {
        X_ptr[i] = X[i];
    }

    // Create and train the perceptron
    Perceptron *p = create_perceptron(n_features);
    fit(p, X_ptr, y, n_samples);

    // Test the perceptron
    for (int i = 0; i < n_samples; i++) {
        printf("Prediction for [%f, %f]: %d\n", X[i][0], X[i][1], predict(p, X[i]));
    }

    // Free memory
    free_perceptron(p);

    return 0;
}
