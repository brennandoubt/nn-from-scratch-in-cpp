#include "Dense.h"


std::random_device rd;
std::mt19937 gen(rd());
std::normal_distribution<double> distr(-0.1, 0.1);
double gen_rand_norm() {
    return distr(gen);
};

// constructor (n_inputs, n_neurons)
Dense::Dense(unsigned int n_inputs, unsigned int n_neurons) {
    vector<vector<double> > tmp{n_inputs};
    for (size_t i = 0; i < n_inputs; i++) {
        tmp[i].resize(n_neurons);
        for (size_t j = 0; j < n_neurons; j++) {
            tmp[i][j] = gen_rand_norm();
        }
    }
    this->weights = Tensor(tmp);
};

Tensor Dense::forward(Tensor& inputs) {
    Tensor output = (inputs * this->weights) + biases;
    return output;
}

string Dense::to_string() {
    ostringstream layerOSS;
    layerOSS << this->weights.to_string();
    layerOSS << "Shape: " << this->weights.shape() << endl;

    return layerOSS.str();
}


int main() {

    vector<vector<double> > inputs = {
        {1, 2, 3, 2.5},
        {2.0, 5.0, -1.0, 2.0},
        {-1.5, 2.7, 3.3, -0.8}
    };
    Tensor X = Tensor(inputs);

    Dense layer1 = Dense(4, 5);
    cout << layer1.to_string();

    Tensor layer1_outputs = layer1.forward(X);
    cout << layer1_outputs.to_string() << endl;

    Dense layer2 = Dense(5, 2);
    cout << layer2.forward(layer1_outputs).to_string() << endl;

    return 0;
}