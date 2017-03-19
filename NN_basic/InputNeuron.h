#pragma once

class InputNeuron
{
public:
	InputNeuron();
	float out(float);
private:
	float weight;
};