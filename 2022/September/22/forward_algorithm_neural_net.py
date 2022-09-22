# First init the network with simple creation of lists and layers

import random,math

def init_network(inputs,hidden,outputs):
    network = list()
    hidden_layer = [{'weights':[random.random() for i in range(inputs+1)]} for i in range(hidden)]
    network.append(hidden_layer)
    output_layer = [{'weights':[random.random() for i in range(hidden+1)]} for i in range(outputs)]
    network.append(output_layer)
    return network

out = init_network(2,3,2)
print(out,'\n')

for layer in out:
    print(layer,'\n')
    for x in layer:
        print(x,'\n New Line : ')
        y = x.keys()
        lst = list(x.values())
        print(y,"    ")
        for z in lst:
            print(z," ")

# Forward propogation in neural network

## Neuron Activation
#### activation = sum(weight_i*input_i)+bias

def activate(weights,inputs):
    activation = weights[-1]
    for i in range(len(weights)-1):
        activation += weights[i]*inputs[i]
    return activation

## Neuron transfer
#### We can use sigmoid or hyperboli tanget
#### output = 1/(1+e^(-activation))
def transfer(activation):
    return 1.0/(1.0+math.exp(-activation))

def forward_propogate(network,row):
    inputs = row 
    for layer in network:
        new_inputs = [] 
        for neuron in layer:
            activation = activate(neuron['weights'],inputs)
            neuron['output'] = transfer(activation)
            new_inputs.append(neuron['output'])
        inputs = new_inputs
    return inputs 