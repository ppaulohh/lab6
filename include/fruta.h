/**
 *@file fruta.h
 *@brief Definição da classe fruta do programa Q1
 *@author Andrécio Costa Bezerra
 *@since 10/05/2018
 *@date 15/05/2018
 */
#ifndef _FRUTA_H_
#define _FRUTA_H_

#include <string>
#include "produto.h"


class Fruta : public Produto
{
private:
	std::string m_data_lote;
	short m_validade;
public:
	Fruta(std::string codigo, std::string descricao, double preco, std::string data, short validade);
	Fruta();
	~Fruta();
	// getters
	std::string getDataLote();
	short getValidade();
	// setters
	void setDataLote(std::string data);
	void setValidade(short validade);
	
	int Leitura(int pos);	
private:
	std::ostream& print(std::ostream &o) const;
};

#endif