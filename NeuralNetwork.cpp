#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "NeuralNetwork.h"


vector<vector<double> > NeuralNetwork::zip(vector<double>& arr1, vector<double>& arr2) {

    vector<vector<double> > zipped_arr;
    vector<double> empty_vec; // to expand zipped_arr

    size_t idx = 0;
    while (idx < arr1.size() && idx < arr2.size()) {
        zipped_arr.push_back(empty_vec); // placeholder for new tuple

        zipped_arr[idx].push_back(arr1[idx]);
        zipped_arr[idx].push_back(arr2[idx]);

        idx++;
    }

    return zipped_arr;
}


string NeuralNetwork::zipped_to_string(vector<vector<double> >& zipped) {

    ostringstream vecOSS;

    // for adding closing bracket after last tuple in string buffer
    size_t last_idx = zipped.size() - 1;

    vecOSS << '[';
    for (size_t i = 0; i < zipped.size(); i++) {
        vecOSS << '(' << zipped[i][0] << ", " << zipped[i][1] << ')';

        if (i < last_idx) {
            vecOSS << ", ";
        }
    }
    vecOSS << ']';

    return vecOSS.str();
}