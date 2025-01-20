#include<iostream>
#include<vector>

void solve(const std::vector<int>& conjunto, std::vector<int>& subConjuntos, int valorAlvo, int begin, 
int valorParcial) {
	if(valorParcial == valorAlvo){
		std::cout << "[ ";
		for(int i: subConjuntos) std::cout << i << " ";
		std::cout << "]" <<std::endl;
		return;
	}
	if(valorParcial > valorAlvo || begin >= conjunto.size()) return;

	subConjuntos.push_back(conjunto[begin]);
	solve(conjunto, subConjuntos, valorAlvo, begin, valorParcial + conjunto[begin]);

	subConjuntos.pop_back();
	solve(conjunto, subConjuntos, valorAlvo, begin+1, valorParcial);


}
	
int main(){
	std::vector<int> conjunto{2, 3, 6, 7};
	std::vector<int> subConjuntos; //subcojunto temporario
	int valorAlvo = 30;

	std::cout << "Subconjuntos que somam " << valorAlvo << ":" << std::endl;
    solve(conjunto, subConjuntos, valorAlvo, 0, 0);
	return 0;
}