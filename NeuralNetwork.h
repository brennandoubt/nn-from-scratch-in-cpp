#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <vector>
#include <cstddef>
#include <string>
using namespace std;

template <typename T, typename T2>
struct Tuple { T item1; T2 item2; };


class NeuralNetwork {

    public:
        template <typename T, typename T2>
        vector<Tuple<T, T2> > zip(vector<T>& arr1, vector<T2>& arr2);

        // computes dot product of two matrices (represented as vectors storing vectors of doubles) -- assumes matrices are always of same size?
        vector<vector<double> > matrix_product(vector<vector<double> >& matrix1, vector<vector<double> >& matrix2);

        template <typename T, typename T2>
        string zipped_to_string(vector<Tuple<T, T2> >& zipped);

        string zipped_matrix_to_string(vector<Tuple<vector<double>, double> >& zipped);

        string doubles_vec_to_string(vector<double>& v);
    
};

#include "NeuralNetwork.cpp" // for fixing linker issues with templates

#endif
