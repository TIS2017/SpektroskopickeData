#pragma once
#include "../../Internal/DataAnalysis/EntryPoint.h"

class PK_Functions
{
public:
	PK_Functions(TD1 *DataPARin);

	void run();

private:
	int h = 0;
	TD1 *data;

	void Gauss();
	void Lorentz();
	void Voight();
	void HartmanTran();
};

