#pragma once


class OutputNeuron
{
public:
	static void set_hidden_num(int);
	float out(float*);
private:
	static int hidden_num;
};
