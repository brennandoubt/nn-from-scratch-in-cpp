#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <vector>
using namespace std;

class NeuralNetwork {

    public:

        vector<vector<double> > zip(vector<double>& arr1, vector<double>& arr2);

        string zipped_to_string(vector<vector<double> >& zipped);
    
};

#endif