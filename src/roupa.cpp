/**
 *@file roupa.cpp
 *@brief Definição dos métodos particulares da classe roupa do programa Q1
 *@details Demais metódos serão herdados da classe base Produto
 *@author Andrécio Costa Bezerra
 *@since 10/05/2018
 *@date 15/05/2018
 */
#include <iomanip>
#include <string>
#include <fstream>

#include "roupa.h"

using namespace std;
/**
 *@brief Definição do Construtor padrão da classe Roupa
 */
Roupa::Roupa(){}
/**
 *@brief Definição do Construtor parametizado da classe Roupa
 *@param Codigo, Descrição, preço e teor da classe base Produto e sexo e tamamnho da classe Roupa
 */
Roupa::Roupa(string codigo, string descricao, double preco, string sexo, string tamanho):
			Produto(codigo, descricao, preco), m_sexo(sexo), m_tamanho(tamanho){}
/**
 *@brief Definição do Construtor padrão da classe Roupa
 */
Roupa::~Roupa(){}
/**
 *@brief Defininição do método getSexo
 *@return Retorna o atributo m_sexo do objeto da classe Roupa
 */
string Roupa::getSexo(){
	return m_sexo;
}
/**
 *@brief Defininição do método getTamanho
 *@return Retorna o atributo m_tamanho do objeto da classe Roupa
 */
string Roupa::getTamanho(){
	return m_tamanho;
}
/**
 *@brief Definição do método setSexo
 *@details Define o atributo m_sexo do objeto da classe Roupa através da passagem de parametro
 *@param  sexo
 */
void Roupa::setSexo(string sexo){
	m_sexo=sexo;
}/**
 *@brief Definição do método setTamanho
 *@details Define o atributo m_tamanho do objeto da classe Roupa através da passagem de parametro
 *@param  tamanho
 */
void Roupa::setTamanho(string tamanho){
	m_tamanho=tamanho;
}
/**
 *@brief Definição do método print da classe Bebida
 *@details Realizado através da sobrecarga do parametro <<
 */
ostream& Roupa::print(ostream &o) const{
	o   << setfill (' ') << setw (10) << m_cod_barras << " | " 
		<< setfill ('.') << setw (20) << m_descricao << " | " 
		<< setfill (' ') << setw (5)  << m_preco << " | "
		<< setfill (' ') << setw (4)  << m_sexo << " | "
		<< setfill (' ') << setw (2)  << m_tamanho;
	return o;
}
/**
 *@brief Definição do método Leitura da classe Roupa
 *@details Realiza leitura do arquivo roupas.dat recebendo o parametro pos
 *@param Pos referente a posição de leitura no arquivo
 *@return Última posição de leitura no arquivo
 */
int Roupa::Leitura(int pos){
		fstream No_Arquivo("roupas.dat");		
		int aux=pos;
		string cod,desc,tam,sex;
		double price;
		No_Arquivo.seekg(aux);
		getline(No_Arquivo,cod,',');
		getline(No_Arquivo,desc,',');
		No_Arquivo>>price;
		aux=No_Arquivo.tellg();	
		No_Arquivo.seekg(aux+1);
		getline(No_Arquivo,sex,',');
		getline(No_Arquivo,tam, ',');
		aux=No_Arquivo.tellg();					
		
		Roupa::setCodBarras(cod);
		Roupa::setDescricao(desc);
		Roupa::setPreco(price);		
		Roupa::setSexo(sex);
		Roupa::setTamanho(tam);	

	return aux;
}