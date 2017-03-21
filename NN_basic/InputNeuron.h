#pragma once

class InputNeuron
{
public:
	InputNeuron();
	double out(double);
private:
	double weight;
};