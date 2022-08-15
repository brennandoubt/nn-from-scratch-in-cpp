#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "NeuralNetwork.h"

//#include <typeinfo>

template <typename T, typename T2>
vector<Tuple<T, T2> > NeuralNetwork::zip(vector<T>& arr1, vector<T2>& arr2) {

    vector<Tuple<T, T2> > zipped_arr;

    size_t idx = 0;
    while (idx < arr1.size() && idx < arr2.size()) {
        // make new tuple to hold i-th arr1 and arr2 values
        Tuple<T, T2> tup;
        tup.item1 = arr1[idx]; 
        tup.item2 = arr2[idx];

        // then add tuple to array
        zipped_arr.push_back(tup);

        idx++;
    }

    return zipped_arr;
}

template <typename T, typename T2>
string NeuralNetwork::zipped_to_string(vector<Tuple<T, T2> >& zipped) {

    ostringstream vecOSS;

    // for adding closing bracket after last tuple in string buffer
    size_t last_idx = zipped.size() - 1;

    vecOSS << '[';
    for (size_t i = 0; i < zipped.size(); i++) {

        vecOSS << '(' << zipped[i].item1 << ", " << zipped[i].item2 << ')';

        if (i < last_idx) {
            vecOSS << ", ";
        }
    }
    vecOSS << ']';

    return vecOSS.str();
}

string NeuralNetwork::zipped_matrix_to_string(vector<Tuple<vector<double>, double> >& zipped) {

    ostringstream vecOSS;

    size_t last_idx = zipped.size() - 1;

    vecOSS << '[';
    for (size_t i = 0; i < zipped.size(); i++) {

        // list out each value inside the i-th column of the matrix
        vecOSS << '(' << '[';
        vector<double> matrix_col = zipped[i].item1;
        size_t last_matrix_idx = matrix_col.size() - 1;
        for (size_t j = 0; j < matrix_col.size(); j++) {

            vecOSS << matrix_col[j];

            if (j < last_matrix_idx) {
                vecOSS << ", ";
            }
        }
        // then list the i-th separate single value in the same tuple
        vecOSS << ']' << ", " << zipped[i].item2 << ')';

        if (i < last_idx) {
            vecOSS << ", ";
        }
    }
    vecOSS << ']';

    return vecOSS.str();
}