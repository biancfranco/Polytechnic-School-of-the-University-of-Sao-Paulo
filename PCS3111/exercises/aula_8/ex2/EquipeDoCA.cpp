#include "EquipeDoCA.h"


EquipeDoCA::EquipeDoCA(string nome, string sigla, Pessoa* presidente, int maxValor) : Equipe(nome, maxValor), CentroAcademico(presidente, sigla)
{

}

EquipeDoCA::~EquipeDoCA()
{
    //dtor
}
