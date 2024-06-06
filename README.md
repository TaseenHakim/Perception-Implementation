Perceptron Implementation in C
 
This report presents a C implementation of a simple perceptron, a fundamental building block in neural networks. The perceptron is trained and tested on a small dataset representing the logical OR function. The report details the perceptron's structure, functionality, and performance.
 
 
The perceptron consists of weights, a bias, and an activation function. It computes a weighted sum of inputs, adds a bias, and applies an activation function to produce an output. In binary classification, this output is typically 0 or 1.
 
The perceptron updates its weights and bias based on the error between predicted and actual outputs. The learning rate controls the magnitude of these updates.
 
Algorithm Overview
Initialization: Weights and bias are initialized to small random values.
Activation Function: A step function returning 1 if the input is positive and 0 otherwise.
Training: The perceptron adjusts its weights and bias through iterative training over the dataset.
Dataset
The OR logical function is used as the dataset, consisting of four samples with binary inputs and outputs.
 
Implemented in C, the Perceptron struct contains weights, bias, and the number of features. Functions include create_perceptron, fit, predict, and free_perceptron.
 
create_perceptron: Allocates memory and initializes weights and bias.
fit: Adjusts weights and bias based on the learning rule.
predict: Computes the output for given inputs.
free_perceptron: Frees allocated memory.
 
The C code was compiled using GCC.
 
The perceptron successfully learned the OR function. Predictions matched expected outputs for all samples in the dataset.
 
The perceptron accurately modeled a simple logical function, demonstrating its effectiveness in linearly separable problems.
 
Limitations: The perceptron struggles with non-linearly separable functions, like XOR.
Improvements: Implementing multi-layer networks or alternative activation functions could be explored.
This project successfully demonstrates a basic perceptron's implementation and functionality in C. It underscores the perceptron's role as a cornerstone in neural network learning and its limitations in solving complex problems.
