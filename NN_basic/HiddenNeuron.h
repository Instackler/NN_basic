#pragma once


class HiddenNeuron
{
public:
	HiddenNeuron();
	static void set_input_num(int);
	double out(double*);
private:
	static int input_num;
	double* weights;
	
};


