
#include <vector>
#include <iostream>

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


    // now computing neuron layer's output
    vector<double> layer_outputs;
    //vector<vector<double> > zipped1 = nn1.zip(weights, biases);

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

    vector<vector<double> > zipped_vec = nn.zip(vec1, vec2);

    cout << nn.zipped_to_string(zipped_vec) << endl;

    Test1();

    return 0;
}