#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <vector>
#include <cstddef>
using namespace std;

template <typename T, typename T2>
struct Tuple { T item1; T2 item2; };


class NeuralNetwork {

    public:
        template <typename T, typename T2>
        vector<Tuple<T, T2> > zip(vector<T>& arr1, vector<T2>& arr2);

        template <typename T, typename T2>
        string zipped_to_string(vector<Tuple<T, T2> >& zipped);
    
};

#include "NeuralNetwork.cpp" // for fixing linker issues with templates

#endif
