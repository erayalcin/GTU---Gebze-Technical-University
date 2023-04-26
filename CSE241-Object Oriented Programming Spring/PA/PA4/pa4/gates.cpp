#include <iostream>
#include <stdlib.h>
#include <string>
#include "gates.h"

void GateList::executeGates(){
    int i=0;
    for(; i<this->numberOfGates; i++) this->gateList[i]->execute();
}

Gate * GateList::findGateByName(std::string gateName){
    int i=0;
    for(;i < this->numberOfGates; i++) if(!this->gateList[i]->getOutput()[0]->getName().compare(gateName)) return this->gateList[i];
    return NULL;
}

GatePort * GateList::findPortByName(std::string portName){
    int i=0;
    for(;i < this->numberOfPorts; i++) if(!this->portList[i]->getName().compare(portName)) return this->portList[i];
    return NULL;
}

void GateList::addPort(GatePort * port){
    int i=0;
    bool exists = false;
    for(; i<this->numberOfPorts; i++) if(!port->getName().compare(this->portList[i]->getName())){
        this->portList[i] = port;
        exists = true;
    };
    if(!exists){
        GatePort ** newPortList = new GatePort * [this->numberOfPorts + 1];
        for(i=0; i<this->numberOfPorts; i++) newPortList[i] = this->portList[i];
        newPortList[i] = port;
        delete(this->portList);
        this->portList = newPortList;
        this->numberOfPorts++;
    }    
}

void GateList::addGate(Gate * gate){
    Gate ** newGateList = new Gate * [this->numberOfGates + 1];
    int i=0;
    for(; i<this->numberOfGates; i++) newGateList[i] = this->gateList[i];
    newGateList[i] = gate;
    delete(this->gateList);
    this->gateList = newGateList;
    this->numberOfGates++;
    this->addPort(gate->getOutput()[0]);
}

int GateList::getNumberOfGates(){
    return this->numberOfGates;
}

int GateList::getNumberOfPorts(){
    return this->numberOfPorts;
}

GatePort * GateList::getPortAtIndex(int index){
    return this->portList[index];
}

Gate * GateList::getGateAtIndex(int index){
    return this->gateList[index];
}

GateList::GateList(){
    this->numberOfGates = 0;
    this->numberOfPorts = 0;
    this->gateList = new Gate * [1];
    this->portList = new GatePort * [1];
}

GatePort::GatePort(bool value, std::string name){
    this->value = value;
    this->name = name;
}

int GatePort::getValue(){
    return this->value;
}

void GatePort::setValue(bool newValue){
    this->value = newValue;
}

std::string GatePort::getName(){
    return this->name;
}

Gate::Gate(GatePort * port1, GatePort * port2, std::string outputName){
    this->input = new GatePort * [2];
    this->input[0] = port1;
    this->input[1] = port2;

    this->output = new GatePort * [1];
    this->output[0] = new GatePort(false, outputName);
}

Gate::Gate(GatePort * port1, GatePort * port2, std::string outputNames[]){
    this->input = new GatePort * [2];
    this->input[0] = port1;
    this->input[1] = port2;

    this->output = new GatePort * [4];
    this->output[0] = new GatePort(false, outputNames[0]);
    this->output[1] = new GatePort(false, outputNames[1]);
    this->output[2] = new GatePort(false, outputNames[2]);
    this->output[3] = new GatePort(false, outputNames[3]);
}

Gate::Gate(GatePort * port1, std::string outputName){
    this->input = new GatePort * [1];
    this->input[0] = port1;

    this->output = new GatePort * [1];
    this->output[0] = new GatePort(false, outputName);
}

GatePort ** Gate::getOutput(){
    return this->output;
}

void AndGate::execute(){
    this->output[0]->setValue(this->input[0]->getValue() & this->input[1]->getValue());
}

void OrGate::execute(){
    this->output[0]->setValue(this->input[0]->getValue() | this->input[1]->getValue());
}

void NotGate::execute(){
    this->output[0]->setValue(!this->input[0]->getValue());
}

void Flipflop::execute(){
    this->output[0]->setValue(this->input[0]->getValue() != this->output[0]->getValue());
}

void Decoder::execute(){
    this->output[0]->setValue(!this->input[0]->getValue() & !this->input[1]->getValue());
    this->output[1]->setValue(!this->input[0]->getValue() & this->input[1]->getValue());
    this->output[2]->setValue(this->input[0]->getValue() & !this->input[1]->getValue());
    this->output[3]->setValue(this->input[0]->getValue() & this->input[1]->getValue());
}