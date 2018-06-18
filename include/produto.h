/**
 *@file produto.h
 *@brief Definição da classe basse abstrata Produto do programa Q1
 *@author Andrécio Costa Bezerra
 *@since 10/05/2018
 *@date 15/05/2018
 */
#ifndef _PRODUTO_H_
#define _PRODUTO_H_

#include <iostream>
#include <string>
#include <ostream>
#include <vector>
#include <memory>


class Produto
{
private:
	std::vector<std::shared_ptr<Produto>> lista;
protected:
	std::string m_cod_barras;
	std::string m_descricao;
	double m_preco;		
public:
	Produto(std::string codigo,std::string descricao, double preco);
	Produto();
	~Produto();
	// getters
	std::string getCodBarras();
	std::string getDescricao();
	double getPreco();
	// setters
	void setCodBarras(std::string codigo);
	void setDescricao(std::string descricao);
	void setPreco(double preco);
	//sobrecaga somar
	
	friend std::ostream& operator<< (std::ostream &o, Produto const &t); 
private:
	 virtual std::ostream& print(std::ostream&) const=0; 
};
 
#endif
