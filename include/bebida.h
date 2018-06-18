/**
 *@file bebida.h
 *@brief Definição da classe bebida do programa Q1
 *@author Andrécio Costa Bezerra
 *@since 10/05/2018
 *@date 15/05/2018
 */
#ifndef _BEBIDA_H_
#define _BEBIDA_H_

#include "produto.h"
#include <string>


class Bebida : public Produto
{
private:
	float m_teor;
	
public:
	Bebida(std::string codigo, std::string descricao,double preco, float teor);
	Bebida();
	~Bebida();
	//getter
	float getTeor();
	//setter
	void setTeor(float teor);
	//Leitura
	int Leitura(int pos);
private:
	std::ostream& print(std::ostream &o) const;
};
#endif