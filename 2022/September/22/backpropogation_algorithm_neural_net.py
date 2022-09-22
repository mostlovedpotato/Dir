# First init the network with simple creation of lists and layers

import random

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
