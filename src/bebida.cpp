/**
 *@file bebida.cpp
 *@brief Definição dos métodos particulares da classe bebida do programa Q1
 *@details Demais metódos serão herdados da classe base Produto
 *@author Andrécio Costa Bezerra
 *@since 10/05/2018
 *@date 15/05/2018
 */
#include <iomanip>
#include <string>
#include <fstream>
#include "bebida.h"

using namespace std;
/**
 *@brief Definição do Construtor parametizado da classe Bebida
 *@param Codigo, Descrição, preço da classe base Produto e teor da classe Bebida
 */
Bebida::Bebida(string codigo, string descricao, double preco, 
	float teor):Produto(codigo, descricao, preco), m_teor(teor){}
/**
 *@brief Definição do Construtor padrão da classe Bebida
 */
Bebida::Bebida(){}
/**
 *@brief Definição do Destrutor padrão da classe Bebida
 */
Bebida::~Bebida(){}
/**
 *@brief Defininição do método getTeor
 *@return Retorna o atributo m_teor do objeto da classe Bebida
 */
float Bebida::getTeor(){
	return m_teor;
}
/**
 *@brief Definição do método setTeor
 *@details Define o atributo m_teor do objeto da classe Bebida através da passagem de parametro
 *@param  Teor
 */
void Bebida::setTeor(float teor){
	m_teor=teor;
}
/**
 *@brief Definição do método print da classe Bebida
 *@details Realizado através da sobrecarga do parametro <<
 */
ostream& Bebida::print(ostream &o) const{
	o   << setfill (' ') << setw (10) << m_cod_barras << " | " 
		<< setfill ('.') << setw (20) << m_descricao << " | " 
		<< setfill (' ') << setw (5)  << m_preco << " | "
		<< setfill (' ') << setw (3)  << m_teor;
	return o;	
}
/**
 *@brief Definição do método Leitura da classe Bebida
 *@details Realiza leitura do arquivo bebidas.dat recebendo o parametro pos
 *@param Pos referente a posição de leitura no arquivo
 *@return Última posição de leitura no arquivo
 */
int Bebida::Leitura(int pos){
		fstream File("bebidas.dat");		
		int aux=pos;
		string cod, desc;
		double price;
		float grad;
		File.seekg(aux);
		getline(File,cod,',');
		getline(File,desc,',');
		File>>price;
		aux=File.tellg();	
		File.seekg(aux-2);
		File>>grad;
		aux=File.tellg();					
		Bebida::setCodBarras(cod);
		Bebida::setDescricao(desc);
		Bebida::setPreco(price);		
		Bebida::setTeor(grad);	

	return aux;
}