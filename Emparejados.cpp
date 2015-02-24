#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int Resp, Alength, Blength;
	vector< char* > Pareados;
	do {
		cout << "# Columna \"A\": ";
		cin >> Alength;
		cout << "# Columna \"B\": ";
		cin >> Blength;
		char** A = new char*[Alength];
		for (int i = 0; i < Alength; ++i) {
			A[i] = new char[20];
		}
		char** B = new char*[Blength];
		for (int i = 0; i < Blength; ++i) {
			B[i] = new char[20];
		}
		cout << "Palabras Columna A" << endl;
		for (int i = 0; i < Alength; ++i) {
			cout << i + 1 << " ";
			cin >> A[i];
		}
		cout << "Palabras Columna B" << endl;
		for (int i = 0; i < Blength; ++i) {
			cout << i + 1 << " ";
			cin >> B[i];
		}
		char* Coord = new char[3];
		char Res;
		cout << "Ingrese los Terminos Pareados Correctos de la Manera[1-3].\nSiendo 1 el Elemento de la Columna \"A\"\nSiendo 3 el Elemento de la Columna \"B\"" << endl;
		while (true) {
			cout << "A-B" << endl;
			cin >> Coord;
			Coord[0] -= 1;
			Coord[2] -= 1;
			Pareados.push_back(Coord);
			cout << "s/n ";
			cin >> Res;
			if (Res == 's' || Resp == 'S') {
				continue;
			} else {
				break;
			}
		}
		cout << "Columna \"A\"" << endl;
		for (int i = 0; i < Alength; ++i) cout << i + 1 << ". " << A[i] << endl;
		cout << "Columna \"B\"" << endl;
		for (int i = 0; i < Blength; ++i) cout << i + 1 << ". " << B[i] << endl;
		float Prom, Intentos = 0.0, IntentosAcertados = 0.0;
		while (true) {
			cout << "s/n";
			cin >> Res;
			if (Res == 's' || Res == 'S') {
				cout << "Ingrese los Terminos Pareados que Usted Considera Correctos de la Manera[1-3].\nSiendo 1 el Elemento de la Columna \"A\"\nSiendo 3 el Elemento de la Columna \"B\"" << endl;
				cin >> Coord;
				Coord[0] -= 1;
				Coord[2] -= 1;
				Intentos += 1;
				for (int i = 0; i < Pareados.size(); ++i) {
					if (Coord[0] == Pareados[i][0] && Coord[2] == Pareados[i][2]) {
						IntentosAcertados += 1;
						cout << "Correto" << endl;
						break;
					}
				}
			} else {
				break;
			}
		}
		Prom = IntentosAcertados / Intentos;
		Prom = Prom * 100;
		cout << Prom << '%' << endl;
		for (int i = 0; i < Alength; ++i) {
			delete[] A[i];
		}
		delete[] A;
		for (int i = 0; i < Blength; ++i) {
			delete[] B[i];
		}
		delete[] B;
		for (int i = 0; i < Pareados.size(); ++i) {
			Pareados.pop_back();
		}
		cout << "Desea Continuar [s/n]: ";
		cin >> Res;
		if (Res == 's' || Res == 'S') {
			cout << "Bienvenido" << endl;
		} else {
			break;
		}
	} while (true);
	return 0;
}
