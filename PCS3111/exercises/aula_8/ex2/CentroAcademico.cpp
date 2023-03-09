#include "CentroAcademico.h"

CentroAcademico::CentroAcademico(Pessoa* presidente, string sigla){
    this->presidente = presidente;
    this->sigla = sigla;
}

CentroAcademico::~CentroAcademico() {
}

string CentroAcademico::getSigla(){
    return sigla;
}

Pessoa* CentroAcademico::getPresidente(){
    return presidente;
}
