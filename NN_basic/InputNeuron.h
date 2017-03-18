#pragma once

class InputNeuron
{
public:
	InputNeuron();
	float out(int);
private:
	float weight;
};