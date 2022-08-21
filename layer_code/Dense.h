#ifndef DENSE_H
#define DENSE_H

#include "tensor_code/Tensor.h"
#include <random>

class Dense {

    public:
        // constructor (n_inputs, n_neurons)
        Dense(unsigned int n_inputs, unsigned int n_neurons);

        // compute layer output
        Tensor forward(Tensor& inputs);

        string to_string();
    
    private:
        Tensor weights;
        vector<double> biases;

};



#endif