/**
 *@file fruta.cpp
 *@brief Definição dos métodos particulares da classe fruta do programa Q1
 *@details Demais metódos serão herdados da classe base Produto
 *@author Andrécio Costa Bezerra
 *@since 10/05/2018
 *@date 15/05/2018
 */
#include <iomanip>
#include <string>
#include <fstream>
#include "fruta.h"

using namespace std;
/**
 *@brief Definição do Construtor padrão da classe Fruta
 */
Fruta::Fruta() {}
/**
 *@brief Definição do Construtor parametizado da classe Fruta
 *@param Codigo, Descrição, preço e teor da classe base Produto e data e validade da classe Fruta
 */
Fruta::Fruta(string codigo, string descricao, double preco,string data, short validade):
			Produto(codigo, descricao, preco), m_data_lote(data), m_validade(validade) {}
/**
 *@brief Definição do Destrutor padrãoda classe Fruta
 */
Fruta::~Fruta() {}
/**
 *@brief Defininição do método getDataLote
 *@return Retorna o atributo m_data_lote do objeto da classe Fruta
 */
string 
Fruta::getDataLote() {
	return m_data_lote;
}
/**
 *@brief Defininição do método getValidade
 *@return Retorna o atributo m_validade do objeto da classe Fruta
 */
short Fruta::getValidade() {
	return m_validade;
}
/**
 *@brief Definição do método setDataLote
 *@details Define o atributo m_data_lote do objeto da classe Fruta através da passagem de parametro
 *@param  data
 */
void Fruta::setDataLote(string data) {
	m_data_lote = data;
}
/**
 *@brief Definição do método setValidade
 *@details Define o atributo m_validade do objeto da classe Fruta através da passagem de parametro
 *@param  validade
 */
void Fruta::setValidade(short validade) {
	m_validade = validade;
}
/**
 *@brief Definição do método print da classe Fruta
 *@details Realizado através da sobrecarga do parametro <<
 */ 
std::ostream& Fruta::print(std::ostream &o) const {
	o   << std::setfill (' ') << std::setw (10) << m_cod_barras << " | " 
		<< std::setfill ('.') << std::setw (20) << m_descricao << " | " 
		<< std::setfill (' ') << std::setw (5) << m_preco << " | "
		<< std::setfill (' ') << std::setw (10) << m_data_lote << " | " 
		<< std::setfill (' ') << std::setw (3) << m_validade;
	return o;
}
/**
 *@brief Definição do método Leitura da classe Fruta
 *@details Realiza leitura do arquivo Frutas.dat recebendo o parametro pos
 *@param Pos referente a posição de leitura no arquivo
 *@return Última posição de leitura no arquivo
 */
int Fruta::Leitura(int pos){
		fstream In_File("frutas.dat");		
		int aux=pos;
		string cod, desc,date;
		double price;
		short val;
		In_File.seekg(aux);
		getline(In_File,cod,',');
		getline(In_File,desc,',');
		In_File>>price;
		aux=In_File.tellg();	
		In_File.seekg(aux+1);
		getline(In_File,date, ',');
		In_File>>val;
		aux=In_File.tellg();					
		Fruta::setCodBarras(cod);
		Fruta::setDescricao(desc);
		Fruta::setPreco(price);		
		Fruta::setDataLote(date);
		Fruta::setValidade(val);	

	return aux;
}

