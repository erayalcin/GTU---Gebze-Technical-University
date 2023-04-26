#ifndef GATE_H
#define GATE_H

#include <iostream>
#include <stdlib.h>
#include <string>

class GateList;
class GatePort;
class Gate;
class AndGate;
class OrGate;
class NotGate;
class Flipflop;
class Decoder;

class GateList{
    private:
        int numberOfGates;
        int numberOfPorts;
        Gate ** gateList;
        GatePort ** portList;
    public:
        void executeGates();
        Gate * findGateByName(std::string gateName);
        GatePort * findPortByName(std::string portName);
        void addPort(GatePort * port);
        void addGate(Gate * gate);
        int getNumberOfGates();
        int getNumberOfPorts();
        GatePort * getPortAtIndex(int index);
        Gate * getGateAtIndex(int index);
        GateList();
};

class GatePort{
    private:
        bool value;
        std::string name;
    public:
        int getValue();
        void setValue(bool newValue);
        std::string getName();
        GatePort(bool value, std::string name);
};

class Gate{
    protected:
        GatePort ** input;
        GatePort ** output;
    public:
        virtual void execute() = 0;
        GatePort ** getOutput();
        Gate(GatePort * port1, GatePort * port2, std::string outputName);
        Gate(GatePort * port1, GatePort * port2, std::string outputNames[]);
        Gate(GatePort * port1, std::string outputName);
};

class AndGate : public Gate{
    public:
        void execute();
        AndGate(GatePort * port1, GatePort * port2, std::string outputName) : Gate(port1, port2, outputName){}
};

class OrGate : public Gate{
    public:
        void execute();
        OrGate(GatePort * port1, GatePort * port2, std::string outputName) : Gate(port1, port2, outputName){}
};

class NotGate : public Gate{
    public:
        void execute();
        NotGate(GatePort * port1, std::string outputName) : Gate(port1, outputName){}
};

class Flipflop : public Gate{
    public:
        void execute();
        Flipflop(GatePort * port1, std::string outputName) : Gate(port1, outputName){}
};

class Decoder : public Gate{
    public:
        void execute();
        Decoder(GatePort * port1, GatePort * port2, std::string outputNames[]) : Gate(port1, port2, outputNames){}
};

#endif