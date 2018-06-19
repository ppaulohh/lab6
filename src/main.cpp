#include <string>
#include "produto.h"
#include "fruta.h"
#include "roupa.h"
#include "bebida.h"
#include "movimentacao.h"
#include "conta.h"
#include "corrente.h"
#include "poupanca.h"
#include "banco.h"

using namespace std;

int main(int argc, char const *argv[])
{
Banco banco;
int pos=0;
vector<shared_ptr<Produto>> lista;	
string valor;
fstream In_File("frutas.dat");
Fruta f;
	
	while (In_File>>valor)
	{
		f.Leitura(pos);
		lista.push_back(make_shared<Fruta>(f.getCodBarras(),f.getDescricao(),f.getPreco(),f.getDataLote(),f.getValidade()));
		pos=f.Leitura(pos);
	}

	fstream No_Arquivo("roupas.dat");
	Roupa r;
	pos=0;
	while (No_Arquivo>>valor)
	{
		r.Leitura(pos);
		lista.push_back(make_shared<Roupa>(r.getCodBarras(),r.getDescricao(),r.getPreco(),r.getSexo(),r.getTamanho()));
		pos=r.Leitura(pos);
	}

	pos=0;
	fstream File("bebidas.dat");
	Bebida b;
	while (File>>valor)
	{
		b.Leitura(pos);
		lista.push_back(make_shared<Bebida>(b.getCodBarras(),b.getDescricao(),b.getPreco(),b.getTeor()));
		pos=b.Leitura(pos);
	}

	for (auto i = lista.begin(); i != lista.end(); ++i)
	{
			cout << (**i) << endl;	
	}



  	banco.abrir();

  	return 0;
}