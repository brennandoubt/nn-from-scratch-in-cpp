
#include <vector>
#include <iostream>

#include "NeuralNetwork.h"

using namespace std;


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

    return 0;

}