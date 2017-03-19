#pragma once


class HiddenNeuron
{
public:
	HiddenNeuron();
	static void set_input_num(int);
	float out(float*);
private:
	static int input_num;
	void* weights;
	
};


