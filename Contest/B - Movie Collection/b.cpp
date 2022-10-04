#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

const int MAXN = 200000;

int BIT[MAXN], posiciones[MAXN];

void add(int index, int n) {
	for (int i = index; i < MAXN; i += i & -i) {
		BIT[i] += n;
	}
}

int sum(int index) {
	int quitarPelicula = 0;
	for (int i = index; i; i -= i & -i) {
		quitarPelicula += BIT[i];
	}
	return quitarPelicula;
}

int main() {
    input;
	int operaciones;
    cin>>operaciones;
	while (operaciones --) {
		int peliculasTotales, peliculasPorQuitar;
        cin>>peliculasTotales>>peliculasPorQuitar;
		fill(BIT + 1, BIT + 1 + peliculasTotales + peliculasPorQuitar, 0);
		for (int i = 1; i <= peliculasTotales; ++ i) {
			posiciones[i] = peliculasTotales - i + 1;
			add(i, 1);
		}
		int contador = peliculasTotales;
		for (int i = 0; i < peliculasPorQuitar; ++ i) {
			int pelicula;
            cin>>pelicula;
			int quitarPelicula = sum(posiciones[pelicula]);
            if(i == peliculasPorQuitar-1){
                cout<<peliculasTotales - quitarPelicula;
            } else{
                cout<<peliculasTotales - quitarPelicula<<" ";
            }
			
			add(posiciones[pelicula], -1);
			posiciones[pelicula] = ++ contador;
			add(posiciones[pelicula], 1);
		}
        cout<<""<<endl;
	}
	return 0;
}