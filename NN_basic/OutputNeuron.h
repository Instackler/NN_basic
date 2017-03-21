#pragma once


class OutputNeuron
{
public:
	OutputNeuron();
	static void set_hidden_num(int);
	double out(double*);
	void set_weights(double*);
	double* get_weights();
private:
	static int hidden_num;
	double* weights;
	double last;
};
