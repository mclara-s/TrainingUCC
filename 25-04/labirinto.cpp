#include <iostream>
#include <list>
#include <string>

using namespace std;

typedef struct{
	int l;
	int c;
}ponto;

list<ponto> path;

bool equal(ponto p1, ponto p2){
	if (p1.l == p2.l && p1.c == p2.c)
		return true;
	else
		return false;
}

bool temCaminho(int m, int n, char matriz[m][n], ponto saida){
	string ponto;
	
	if (m == saida.l && n == saida.c){
		return true;
	}
	if (matriz[m][n] == '.'){
		
		ponto = to_string(m) + to_string(n);
		path.push(ponto);
	}
	if (matriz[m][n+1] == '.'){
		temCaminho(m, n+1, matriz);
	}
	if (matriz[m][n-1] == '.' ){
		temCaminho(m, n-1, matriz);
	}
	if (matriz[m+1][n] == '.'){
		temCaminho(m+1, n, matriz);
	}
	if (matriz[m-1][n] == '.'){
		temCaminho(m-1, n, matriz);
	}
}

bool acharExtremidade(int m, int n, char matriz, ponto &point){
	int i, j;
	for (i = 0; i < m; i++){
		if (i == 0 || i == m-1){
			for (j = 0; j < n; j++){
				if (matriz[i][j] == '.'){
					point.l = i;
					point.j = c;
					return true;
				}
			}
		}
		else{
			if (matriz[i][0] == '.'){
				point.l = i;
				point.c = 0;
				return true;
			}
			else if(matriz[i][m-1] == '.'){
				point.l = i;
				point.c = m-1;
				return true; 
			}
		}
	}
	return false;
}

int main(){
	int testes, m, n;
	char labirinto[30][30];
	ponto point, entrada, saida;
	cin >> testes;

	for (int i = 0; i < testes; ++i)
	{
		cin >> m >> n;
		//DESENHAR LABIRINTO
		for (int j = 0; j < m; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				cin >> matriz[j][k];				
			}
		}

		//ACHAR ENTRADA
		if (!acharExtremidade(m, n, labirinto, entrada))
			cout << "invalid" << endl;
		else{
			//ACHAR SAIDA
			acharExtremidade(m, n, labirinto, saida);
			if (equal(entrada, saida)){
				cout << "invalid" << endl;
			}
			else{
				if (temCaminho(entrada.l, entrada.c, labirinto, saida))
			}
		}
	}

	return 0;
}