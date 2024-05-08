#include "Ciudad.hh"
#include "Producto.hh"
#include "Barco.hh"
#include <vector>

using namespace std;

class Rio {
    private:
        map<string, Ciudad> lista_ciudades; //List of all the cities on the river.
        vector<Producto> lista_productos;   //List of all the products on the river. The indexes of the vector indicate the id of the product.

    public:

        Rio();

        bool existe_ciudad(string id) const;

        bool existe_producto(int id) const;

        Ciudad consultar_ciudad(string id) const;

        Producto consultar_producto(int id) const;

        void leer_inventario(Ciudad& city, Producto& producto, int id_producto, int unidades, int unidades_necesarias);

        void modificar_barco(Barco& barco, int producto_a_comprar, int producto_a_vender, double unidades_a_comprar, double unidades_a_vender);

        void escribir_barco(Barco& barco) const;

        void consultar_num() const;

        void agregar_productos(double peso, double volumen);

        void escribir_producto(int id_producto) const;

        void escribir_ciudad(string id_ciudad) const;

        void poner_producto(Ciudad& city, int id_producto, int unidades, int unidades_necesarias);

        bool existe_producto_ciudad(Ciudad& city, int id) const;
};