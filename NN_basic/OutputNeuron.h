#pragma once


class OutputNeuron
{
public:
	OutputNeuron();
	static void set_hidden_num(int);
	double out(double*);
private:
	static int hidden_num;
	double* weights;
};
