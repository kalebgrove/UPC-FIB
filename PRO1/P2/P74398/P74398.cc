#include <iostream>
using namespace std;

int main(){
    int k;
    cin >> k;

    double i = 2.0; // Empieza la lista de bases que van a estar en la salida.
    int j = 1;      // j es el numero de veces que se divide por 2, parecido a una potencia. Es la potencia de 2 mas grande que cabe dentro de k. 
                    // Por lo tanto, será el numero de cifras que aparecerán en el vector de digitos.

    while (i <= 16)
    {
        double cociente = k/i;
        
        while(cociente >= i){
            cociente /= i;
            ++j;
        }

        if ((cociente < 1)) /* En dividir k por i, nos da el cociente. El while loop siempre funciona mientras que cociente sea mayor o igual a i, pero en caso 
                            de que sea menor, significa que ya no se pueden hacer mas divisiones enteras, asi pues, el cociente sera menor que i, rompiendo el 
                            loop. De esta manera, se ve que se necesita j*/
        {
           cout << "Base " << i << ": " << j << " cifras." << endl;
        } else
        {
            cout << "Base " << i << ": " << j+1 << " cifras." << endl;
        }

        ++i;
        j = 1;

    }
    

}