#include <iostream>

using namespace std;

int main() {
    int height, width;

    while(cin >> height >> width) {                                 //El programa ha de funcionar mentre que s'introdueixin les dades de base i altura.

    int hash = width/2;                                             //Hash es refereix al hashtag, és a dir, el símbol que fa el ziga zaga. Per trobar el seu nombre, divieixo la base per 2,
    int count = 0;                                                  //donat que la base és un nombre parell.
    int star = 0;                                                   //Star, es refereix al nombre d'estrelles que hi hauran davant del símbol hashtag, i opp, les que hi hauran al darrere.
    int opp = hash;                                                 //Com que el hashtag comença a l'esquerre sense padding, aleshores seran el mateix nombre que el hashtag, donat que sumats han de donar la base.
    bool same = false;                                              //Aquests booleans em permeten veure si el nombre d'estrelles que es troben a l'esquerre és el mateix que el nombre de hashtags. Per a mi, això
    bool different = true;                                          //significa que ja ha arribat a la dreta. Segur que hi ha una manera més fàcil, com la que ens has ensenyat avui, però en el moment estava invertit
                                                                    //en fer que els booleans funcionessin. Aleshores, different, de la mateixa manera que same però contrari, indica si el nombre d'estrelles a la
    while(count < height) {                                         //banda esquerre dels hashtags són el mateix. Així que en el moment en què un sigui igual, això ens indica que els hashtags han d'anar en direcció
                                                                    //contraria.
        while(different and count < height){

            for(int j = 0; j < star; ++j) {
                cout << '*';
            }
            for(int j = 0; j < hash; ++j) {
                cout << '#';
            }
            for(int j = 0; j < opp; ++j) {
                cout << '*';
            }
            cout << endl;
            ++star;
            --opp;
            ++count;
            if(star == hash+1) {
                same = true;
                different = false;
            }
        }      

        while(same and count < height){
            
            for(int j = 0; j < star-2; ++j) {                       //Com que durant el primer loop s'han modificat les dades, aleshores, he fet uns calculs per estalviar re-declarar les variables.
                cout << '*';                                        //Al final del programa faig el mateix que he fet al primer loop però invertit, ja que un loop fa referència a un ziga i l'altre al zaga.
            }
            for(int j = 0; j < hash; ++j) {
                cout << '#';
            }
            for(int j = 0; j < opp+2; ++j) {
                cout << '*';
            }
            cout << endl;
            --star;
            ++opp;
            ++count;
            if(opp == hash-1){
                star = 1;
                opp = hash-1;
                same = false;
                different = true;
            }
        }
    }
    cout << endl;
}
}