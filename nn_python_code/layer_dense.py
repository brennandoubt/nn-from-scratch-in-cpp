import numpy

numpy.random.seed(0)

X = [
    [1, 2, 3, 2.5],
    [2.0, 5.0, -1.0, 2.0],
    [-1.5, 2.7, 3.3, -0.8]
]

class Layer_Dense:
    def __init__(self, n_inputs, n_neurons):
        # randomly initializing layer's weights (trying for range -0.1, +0.1)
        self.weights = 0.10 * numpy.random.randn(n_inputs, n_neurons) # returns array of shape (n_inputs, n_neurons) for the weights array
        self.biases = numpy.zeros((1, n_neurons)) # returns array of shape (1, n_neurons) filled with zeros for the biases array
    def forward(self, inputs):
        self.output = numpy.dot(inputs, self.weights) + self.biases

class Activation_ReLU:
    def forward(self, inputs):
        self.output = numpy.maximum(0, inputs)


# trying to get weights to initialize to random values between -0.1, +0.1
#print(0.10 * numpy.random.randn(4, 3))

# 4 inputs, 5 neurons
layer1 = Layer_Dense(4, 5)
print(layer1.weights)

# then 5 inputs, 2 neurons
layer2 = Layer_Dense(5, 2)
print(layer2.weights)


layer1.forward(X)
print(layer1.output)

# neurons' outputs in layer 1 become inputs for layer 2
layer2.forward(layer1.output)
print(layer2.output)    
