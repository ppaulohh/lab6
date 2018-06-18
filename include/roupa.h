/**
 *@file roupa.h
 *@brief Definição da classe roupa do programa Q1
 *@author Andrécio Costa Bezerra
 *@since 10/05/2018
 *@date 15/05/2018
 */
#ifndef _ROUPA_H_
#define _ROUPA_H_

#include <string>
#include "produto.h"

class Roupa : public Produto
{
private:
	std::string m_sexo;
	std::string m_tamanho;
public:
	Roupa(std::string codigo, std::string descricao,double preco, std::string sexo, std::string tamanho);
	Roupa();
	~Roupa();
	//getters
	std::string getSexo();
	std::string getTamanho();
	//setters
	void setSexo(std::string sexo);
	void setTamanho(std::string tamanho);
	//leitura
	int Leitura(int pos);	
private:
	std::ostream& print(std::ostream &o) const;
};
#endif