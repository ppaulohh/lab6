#include <iostream>
#include <fstream>
#include <ostream>
#include "produto.h"

using namespace std;
/**
 *@brief Definição do Construtor padrão da classe base Produto
 */
Produto::Produto() {}
/**
 *@brief Definição do Destrutor padrão da classe base Produto
 */
Produto::~Produto(){}
/**
 *@brief Definição do Construtor parametizado da classe base Produto
 *@param Codigo, Descrição, preço da classe base Produto
 */
Produto::Produto(string codigo, string descricao, double preco):
	m_cod_barras(codigo), m_descricao(descricao), m_preco(preco) {}
/**
 *@brief Defininição do método getCodBarras
 *@return Retorna o atributo m_cod_barras do objeto da classe base Produto
 */
string Produto::getCodBarras()
{
	return m_cod_barras;
}
/**
 *@brief Defininição do método getDescricao
 *@return Retorna o atributo m_descricao do objeto da classe base Produto
 */	
string Produto::getDescricao()
{
	return m_descricao;
}
/**
 *@brief Defininição do método getPreco
 *@return Retorna o atributo m_preco do objeto da classe base Produto
 */
double Produto::getPreco()
{
	return m_preco;
}
/**
 *@brief Definição do método setTeor
 *@details Define o atributo m_cod_barras do objeto da classe base Produto através da passagem de parametro
 *@param  codigo
 */	
void Produto::setCodBarras(string codigo) 
{
	m_cod_barras = codigo;
}
/**
 *@brief Definição do método setDescricao
 *@details Define o atributo m_descricao do objeto da classe base Produto através da passagem de parametro
 *@param  descricao
 */
void Produto::setDescricao(string descricao) 
{
	m_descricao = descricao;
}
/**
 *@brief Definição do método setPreço
 *@details Define o atributo m_preco do objeto da classe base Produto através da passagem de parametro
 *@param  preco
 */
void Produto::setPreco(double preco) 
{
	m_preco = preco;
}

/**
 *@brief Definição do método print da classe Produto
 *@details Realizado através da sobrecarga do parametro <<
 */
ostream& operator<< (ostream &o, Produto const &p) 
{
	return p.print(o);
}



