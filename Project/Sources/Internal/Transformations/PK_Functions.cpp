#include "stdafx.h"
#include "PK_Functions.h"

PK_Functions::PK_Functions(TD1 *DataPARin){
	*data = *DataPARin;
}

void PK_Functions::run(){
	switch (h) {
	case 0:
		Gauss();
		break;
	case 1:
		Lorentz();
		break;
	case 2:
		Voight();
		break;
	case 3:
		HartmanTran();
		break;
	}
}

void PK_Functions::Gauss(){
}

void PK_Functions::Lorentz(){
}

void PK_Functions::Voight(){
}

void PK_Functions::HartmanTran(){
}
