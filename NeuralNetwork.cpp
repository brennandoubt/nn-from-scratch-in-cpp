#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "NeuralNetwork.h"


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


// matrix multiplication
vector<vector<double> > NeuralNetwork::matrix_product(vector<vector<double> >& matrix1, vector<vector<double> >& matrix2) {

    // declaring a 2-D array (matrix) with dimensions R1 x C2 (rows in matrix 1 x columns in matrix 2)
    //double matrix3[matrix1[0].size()][matrix2.size()];

    vector<vector<double> > matrix3{matrix1.size()};
    //vector<double> emptyvec;

    
    for (size_t i = 0; i < matrix1.size(); i++) {
       //matrix3[i].resize(matrix2.size());
        //matrix3.push_back(emptyvec);
        //matrix3[i].resize(0);

        for (size_t j = 0; j < matrix2[0].size(); j++) {
            
            double result = 0;
            for (size_t k = 0; k < matrix2.size(); k++) {
                result += matrix1[i][k] * matrix2[k][j];
            }
            matrix3[i].push_back(result);
        }
    }
    return matrix3;
}


vector<vector<double> > NeuralNetwork::transpose(const vector<vector<double> >& matrix) {

    vector<vector<double> > t_matrix{matrix[0].size()}; // initializing transpose matrix at size of original matrix's dimension

    // for each row value in matrix, take each value and push them into the new matrix's column
    for (size_t i = 0; i < matrix.size(); i++) {
        // pushing each original row value into each column space for new matrix
        for (size_t j = 0; j < matrix[0].size(); j++) {
            //t_matrix.push_back(emptyvec);
            t_matrix[j].push_back(matrix[i][j]);
        }
    }

    return t_matrix;
}


vector<vector<double> > NeuralNetwork::add_to_matrix(vector<vector<double> >& matrix, vector<double>& vector) {

    // add each vector[i] value to each matrix[j][i] value
    for (size_t j = 0; j < matrix.size(); j++) {
        for (size_t i = 0; i < vector.size(); i++) {
            matrix[j][i] += vector[i];
        }
    }
    return matrix;
}


string NeuralNetwork::matrix_to_string(const vector<vector<double> >& matrix) {
    ostringstream matrixOSS;

    for (vector<double> row : matrix) {
        matrixOSS << doubles_vec_to_string(row) << '\n';
    }

    return matrixOSS.str();
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


string NeuralNetwork::doubles_vec_to_string(vector<double>& v) {

    ostringstream vecOSS;

    vecOSS << '[';
    for (size_t i = 0; i < v.size() - 1; i++) {
        vecOSS << v[i] << ", ";
    }
    vecOSS << v[v.size()-1] << ']'; // adding last value in vector without a comma after it to close vector

    return vecOSS.str();
}