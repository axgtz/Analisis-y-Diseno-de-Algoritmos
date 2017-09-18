//Roberto Alejandro Gutierrez Guillen		A01019608
#include <iostream>
#include <vector>

using namespace std;
vector<int> vec;

void Mochila(Elementos e; int n; float M; Mochila sol)
{
	float peso_en_curso; int i;
	for (i = 1; i < maxElem; ++i) { sol[i] = 0.0; }
	peso_en_curso = 0.0; i = 1;
	while ((peso_en_curso < M) && (i <= n))
	{
		if (e[i].peso + peso_en_curso) <= M) { sol[i] = 1.0; }
		else { sol[i] = (M - peso_en_curso) / e[i].peso; }

		peso_en_curso = peso_en_curso + (sol[i] * e[i].peso);
		++i;
	}
}

int main() {

}