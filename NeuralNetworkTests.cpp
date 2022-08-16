
#include <vector>
#include <iostream>
#include <stdexcept>

#include "NeuralNetwork.h"

using namespace std;



void Test1() {

    NeuralNetwork nn1;

    // inputs into network
    vector<double> inputs;
    inputs.push_back(1);
    inputs.push_back(2);
    inputs.push_back(3);
    inputs.push_back(2.5);

    // initialization of weights vectors
    vector<double> weights1, weights2, weights3;
    weights1.push_back(0.2);
    weights1.push_back(0.8);
    weights1.push_back(-0.5);
    weights1.push_back(1.0);

    weights2.push_back(0.5);
    weights2.push_back(-0.91);
    weights2.push_back(0.26);
    weights2.push_back(-0.5);

    weights3.push_back(-0.26);
    weights3.push_back(-0.27);
    weights3.push_back(0.17);
    weights3.push_back(0.87);


    // making 2-D array holding all weights
    vector<vector<double> > weights;
    weights.push_back(weights1);
    weights.push_back(weights2);
    weights.push_back(weights3);


    vector<double> biases;
    biases.push_back(2);
    biases.push_back(3);
    biases.push_back(0.5);


    // now computing neuron layer's output...
    vector<double> layer_outputs;

    // matrix-doubles zip
    vector<Tuple<vector<double>, double> > zipped1 = nn1.zip<vector<double>, double>(weights, biases);

    cout << "Zipped a matrix and doubles...\n" << nn1.zipped_matrix_to_string(zipped1) << endl;

    // for neuron weights, neuron bias in zipped1 vector...
    for (size_t i = 0; i < zipped1.size(); i++) {
        vector<double> neuron_weights = zipped1[i].item1;
        double neuron_bias = zipped1[i].item2;

        double neuron_output = 0.0; // output of given neuron

        // doubles-doubles zip
        vector<Tuple<double, double> > zipped_inputs_weights = nn1.zip<double, double>(inputs, neuron_weights);
        
        for (size_t j = 0; j < zipped_inputs_weights.size(); j++) {
            double n_input = zipped_inputs_weights[j].item1;
            double weight = zipped_inputs_weights[j].item2;

            neuron_output += n_input*weight; // compute input*weight

        }
        neuron_output += neuron_bias; // then +bias to get neuron's final output
        layer_outputs.push_back(neuron_output);
    }

    cout << "NEURON LAYER OUTPUT: " << nn1.doubles_vec_to_string(layer_outputs) << endl; // values match with the Python code's results!

    // Or: the dot product of inputs vector and weights matrix, with the biases then added to their product
    // returns the neurons' outputs

}



void Test2() {

    NeuralNetwork nn;

    // using batches for generalizing data, avoiding overfitting

    // so now adding batches of inputs to network...
    vector<vector<double> > inputs = {
        {1, 2, 3, 2.5},
        {2.0, 5.0, -1.0, 2.0},
        {-1.5, 2.7, 3.3, -0.8}
    };

    vector<vector<double> > weights = {
        {0.2, 0.8, -0.5, 1.0},
        {0.5, -0.91, 0.26, -0.5},
        {-0.26, -0.27, 0.17, 0.87}
    };

    vector<double> biases = {2, 3, 0.5};

    vector<double> layer_outputs;

    layer_outputs = nn.dot(inputs, weights);
    cout << nn.doubles_vec_to_string(layer_outputs) << endl;

    /* // dear god what have i created here (getting each matrix column from both inputs and weights matrices...)
    for (Tuple<vector<double>, double> ith_columns : nn.zip<vector<double>, double>(weights, biases)) {
        // weights and bias info stored in Tuple object
        vector<double> neuron_weights = ith_columns.item1;
        double neuron_bias = ith_columns.item2;

        double neuron_output = 0.0;

        // for n_input, weight in zip(inputs, neuron_weights)
        for (Tuple<vector<double>, double> ith_rows : nn.zip<vector<double>, double>(inputs, neuron_weights)) {
            
        }


        
    } */
}





int main() {

    NeuralNetwork nn;

    vector<double> vec1;
    vec1.push_back(2.3);
    vec1.push_back(53.2);
    vec1.push_back(-2.7);

    vector<double> vec2;
    vec2.push_back(1.4);
    vec2.push_back(3.9);
    vec2.push_back(8.1);

    cout << "REACHED!" << endl;

    vector<Tuple<double, double> > zipped_vec = nn.zip<double, double>(vec1, vec2);

    cout << "Zipped doubles...\n" << nn.zipped_to_string<double, double>(zipped_vec) << endl;

    Test1();

    Test2();

    return 0;
}