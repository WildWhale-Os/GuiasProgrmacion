#include <stdio.h>

int buscar(int n, int *v, int e){
	if(n -1 >= 0){
		if (v[n -1] == e) return n-1;
		else return buscar(n-1,v,e);
	}

	return -1;
}

int busquedaBinario(int limInf, int limSup, int *v, int e){
	if(limSup > limInf){
		int medio = (limInf + limSup)/2;
		if(e == v [medio] ) return medio;
		else if(e == v[limInf]) return limInf;
		else if (e == v[limSup]) return limSup;
		else if(e < v[medio]) return busquedaBinario(limInf, medio-1,v,e);
		else if(e > v[medio]) return busquedaBinario(medio + 1, limSup,v,e);	
	}
	return -1;
}