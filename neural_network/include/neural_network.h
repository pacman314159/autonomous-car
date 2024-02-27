#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "matrix.h"
#include <vector>
#include <cstdlib>
#include <cmath>

namespace sp
{
    //simple activation function
    inline float Sigmoid(float x)
    {
        return 1.0f / (1 + exp(-x));
    }

    // calss representing a simple densely connected neural network
    // i.e. every neuron  is connected to every neuron of next layer
    class SimpleNeuralNetwork
    {
        public:
            std::vector<uint32_t> _topology;
            std::vector<Matrix2D<float>> _weightMatrices;
            std::vector<Matrix2D<float>> _valueMatrices;
            std::vector<Matrix2D<float>> _biasMatrices;
        public:
            
            // topology defines the no.of neurons for each layer
            // learning rate defines how much modification should be done in each backwords propagation i.e. training
            SimpleNeuralNetwork(std::vector<uint32_t> topology)
                :_topology(topology),
                _weightMatrices({}),
                _valueMatrices({}),
                _biasMatrices({})
            {
                // initializing weight and bias matrices with random weights
                for(uint32_t i = 0; i < topology.size() - 1; i++)
                {
                    Matrix2D<float> weightMatrix(topology[i + 1], topology[i]); 
                    weightMatrix = weightMatrix.applyFunction([](const float &val){
                        return (float)rand() / RAND_MAX;
                    });
                    _weightMatrices.push_back(weightMatrix);
                    
                    Matrix2D<float> biasMatrix(topology[i + 1], 1);
                    biasMatrix = biasMatrix.applyFunction([](const float &val){
                        return (float)rand() / RAND_MAX;
                    });
                    _biasMatrices.push_back(biasMatrix);
   
                }
                _valueMatrices.resize(topology.size());
            }

            // function to generate output from given input vector
            bool feedForward(std::vector<float> input)
            {
                if(input.size() != _topology[0])
                    return false;
                // creating input matrix 
                Matrix2D<float> values(input.size(), 1);
                for(uint32_t i = 0; i < input.size(); i++)
                    values._vals[i] = input[i];
                
                //forwording inputs to next layers
                for(uint32_t i = 0; i < _weightMatrices.size(); i++)
                {
                    // y = activationFunc( x1 * w1 + x2 * w2 + ... + b)  
                    _valueMatrices[i] = values;
                    values = values.multiply(_weightMatrices[i]);
                    values = values.add(_biasMatrices[i]);
                    values = values.applyFunction(Sigmoid);
                }
                _valueMatrices[_weightMatrices.size()] = values;
                return true;
            }

            // function to retrive final output
            std::vector<float> getPredictions()
            {
                return _valueMatrices.back()._vals;
            }

    }; // class SimpleNeuralNetwork


}

#endif
