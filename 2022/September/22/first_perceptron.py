
import numpy,random,os
lr =1
bias = 1
weights = [random.random(),random.random(),random.random()]

def Perceptron(input1,input2,output):
    outputp = input1*weights[0]+input2*weights[1]+bias*weights[2]
    if outputp>0 : 
        outputp=1
    else:
        outputp = 0
    error = output - outputp 
    weights[0]+=error*input1*lr 
    weights[1]+=error*input2*lr 
    weights[2]+=error*bias*lr

# Learning 
for i in range(50) :
   Perceptron(1,1,1) #True or true
   Perceptron(1,0,1) #True or false
   Perceptron(0,1,1) #False or true
   Perceptron(0,0,0) #False or false


x = int(input())
y = int(input())
outputp = x*weights[0] + y*weights[1] + bias*weights[2]
if outputp > 0 : #activation function
   outputp = 1
else :
   outputp = 0
print(x, "or", y, "is : ", outputp)
outputP = (1/(1+numpy.exp(-outputp)))