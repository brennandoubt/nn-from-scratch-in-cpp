#include "Dense.h"


std::random_device rd; // getting random value from hardware
//std::mt19937 gen(0); // random seed generation
std::default_random_engine generator(0);
std::normal_distribution<double> norm_distr(0.0, 1.0);
double gen_rand_norm() {
    return norm_distr(generator);
};

// matrix of weights generated from numpy.randn() command in python program example
Tensor gen_python_example_weights45() {
    return Tensor({
        {0.17640523, 0.04001572, 0.0978738, 0.22408932, 0.1867558},
        {-0.09772779, 0.09500884, -0.01513572, -0.01032189, 0.04105985},
        {0.01440436, 0.14542735, 0.07610377, 0.0121675, 0.04438632},
        {0.03336743, 0.14940791, -0.02051583, 0.03130677, -0.08540957}
    });
};

Tensor gen_python_example_weights52() {
    return Tensor({
        {-0.25529898, 0.06536186},
        {0.08644362, -0.0742165},
        {0.22697546, -0.14543657},
        {0.00457585, -0.01871839},
        {0.15327792, 0.14693588}
    });
};

// constructor (n_inputs, n_neurons)
Dense::Dense(unsigned int n_inputs, unsigned int n_neurons) {
    // example weights from numpy.randn() call in python example
    //Tensor ex_weights = gen_python_example_weights();


    vector<vector<double> > tmp{n_inputs};
    for (size_t i = 0; i < n_inputs; i++) {
        tmp[i].resize(n_neurons);
        //cout << "Row size: " << tmp[i].size() << endl;
        for (size_t j = 0; j < n_neurons; j++) {
            tmp[i][j] = 0.10 * gen_rand_norm();
            //cout << tmp[i][j] << endl;
            //cout << ex_weights.shape() << " , " << Tensor(tmp).shape() << i << ',' << j << endl;
            //cout << Tensor(tmp).to_string() << endl;
            //cout << tmp[i][j];
            //tmp[i][j] = ex_weights.array[i][j];
        }
    }
    this->weights = Tensor(tmp);
    /* if (n_inputs == 4 && n_neurons == 5) {
        this->weights = gen_python_example_weights45(); // needs to only generate example weights in correct shape (n_inputs, n_neurons)
    }
    else if (n_inputs == 5 && n_neurons == 2) {
        this->weights = gen_python_example_weights52();
    } */
};

Tensor Dense::forward(Tensor& inputs) {
    this->output = (inputs * this->weights) + biases;
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
    Dense layer2 = Dense(5, 2);

    Tensor layer1_outputs = layer1.forward(X);
    cout << layer1_outputs.to_string() << endl;
    
    Tensor layer2_outputs = layer2.forward(layer1_outputs);
    cout << layer2.output.to_string() << endl;

    return 0;
}