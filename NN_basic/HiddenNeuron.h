#pragma once


class HiddenNeuron
{
public:
	HiddenNeuron();
	static void set_input_num(int);
	double out(double*);
	void set_weights(double*);
	double* get_weights();
	double get_last();
private:
	static int input_num;
	double* weights;
	double last;
};


