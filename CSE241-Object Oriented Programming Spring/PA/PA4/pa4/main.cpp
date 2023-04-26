#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <string>

#include "gates.h"

int main(){
    std::string circuitFile = "circuit.txt";
    std::string inputFile = "input.txt";

    std::ifstream circuitReader(circuitFile);
    std::string circuitLine;

    std::string * inputPorts = new std::string[1];
    std::string * outputPorts = new std::string[1];

    int numOutputs = 0;

    bool hasDecoder = false;

    GateList * gateList = new GateList();

    while(getline(circuitReader, circuitLine)){
        std::string component;
        std::string * components = new std::string[1];
        int numComponents = 0;

        std::stringstream lineReader(circuitLine);

        while(lineReader >> component){
            numComponents++;
            std::string * newComponents = new std::string[numComponents];
            int i=0;
            for(;i < numComponents-1; i++) newComponents[i] = components[i];
            newComponents[i] = component;
            components = newComponents;
        }

        if(!components[0].compare("INPUT")){
            inputPorts = new std::string[numComponents-1];
            int i=1;
            for(; i<numComponents; i++){
                inputPorts[i-1] = components[i];
                GatePort * newPort = new GatePort(false, components[i]);
                gateList->addPort(newPort);
            }
        }

        else if(!components[0].compare("OUTPUT")){
            outputPorts = new std::string[numComponents-1];
            int i=1;
            for(; i<numComponents; i++){
                outputPorts[i-1] = components[i];
                GatePort * newPort = new GatePort(false, components[i]);
                gateList->addPort(newPort);
            }
            numOutputs = numComponents - 1;
        }

        else if(!components[0].compare("AND")){
            GatePort * port1 = gateList->findPortByName(components[2]);
            GatePort * port2 = gateList->findPortByName(components[3]);
            AndGate * andGate = new AndGate(port1, port2, components[1]);

            gateList->addGate(andGate);
        }

        else if(!components[0].compare("OR")){
            GatePort * port1 = gateList->findPortByName(components[2]);
            GatePort * port2 = gateList->findPortByName(components[3]);
            OrGate * orGate = new OrGate(port1, port2, components[1]);

            gateList->addGate(orGate);
        }

        else if(!components[0].compare("NOT")){
            GatePort * port1 = gateList->findPortByName(components[2]);
            NotGate * notGate = new NotGate(port1, components[1]);

            gateList->addGate(notGate);
        }

        else if(!components[0].compare("FLIPFLOP")){
            GatePort * port1 = gateList->findPortByName(components[2]);
            Flipflop * flipflop = new Flipflop(port1, components[1]);

            gateList->addGate(flipflop);
        }

        else if(!components[0].compare("DECODER")){
            GatePort * port1 = gateList->findPortByName(components[5]);
            GatePort * port2 = gateList->findPortByName(components[6]);
            std::string names[4] = {components[1], components[2], components[3], components[4]};
            Decoder * decoder = new Decoder(port1, port2, names);

            gateList->addGate(decoder);

            hasDecoder = true;
        }
    }

    std::ifstream inputReader(inputFile);
    std::string inputLine;
    
    while(getline(inputReader, inputLine)){    
        std::string component;
        int numComponents = 0;

        std::stringstream lineReader(inputLine);

        while(lineReader >> component){
            bool value = stoi(component);
            gateList->findPortByName(inputPorts[numComponents])->setValue(value);
            numComponents++;
        }      
        
        gateList->executeGates();

        int i=0;
        if(!hasDecoder){

            for(; i<numOutputs-1; i++) std::cout << (gateList->findPortByName(outputPorts[i])->getValue()) << " ";
            std::cout << (gateList->findPortByName(outputPorts[i])->getValue()) << std::endl;
        }
        else{
            for(; i<3; i++) std::cout << gateList->getGateAtIndex(gateList->getNumberOfGates() - 1)->getOutput()[i]->getValue() << " ";
            std::cout << gateList->getGateAtIndex(gateList->getNumberOfGates() - 1)->getOutput()[i]->getValue() << std::endl;
        }
    }
}