//
// Created by antonio on 5/05/22.
//

#ifndef P3_PEDIDO_ARTICULO_HPP
#define P3_PEDIDO_ARTICULO_HPP
#include "../P2/articulo.hpp"
#include "pedido.hpp"
#include <iostream>
#include <map>

struct OrdenaArticulos: public std::binary_function <Articulo*, Articulo*, bool>{
    bool operator()(const Articulo* articulo1, const Articulo* articulo2) const {return articulo1->referencia() < articulo2->referencia();}
};

struct OrdenaPedidos: public std::binary_function <Pedido*, Pedido*, bool>{
    bool operator()(const Pedido* pedido1, const Pedido* pedido2) const {return pedido1->numero() < pedido2->numero();}
};


class LineaPedido{
public:
    explicit LineaPedido(double p_venta, unsigned cant = 1);
    double precio_venta() const {return p_venta;};
    unsigned cantidad() const {return _cantidad;};

private:
    double p_venta;
    unsigned _cantidad;
};

class Pedido_Articulo{
public:
    typedef std::map<Articulo*, LineaPedido, OrdenaArticulos> ItemsPedido;
    typedef std::map<Pedido*, LineaPedido, OrdenaPedidos> Pedidos;
    void pedir(Articulo& articulo1, Pedido& pedido1, double precio, unsigned cant = 1);
    void pedir(Pedido& pedido1, Articulo& articulo1, double precio, unsigned cant = 1);
    ItemsPedido& detalle(Pedido& pedido1);
    Pedidos ventas(Articulo& articulo1);
    std::ostream& mostrarDetallePedidos(std::ostream& os);
    std::ostream& mostrarVentasArticulos(std::ostream& os);
private:
    std::map<Articulo*, Pedidos, OrdenaArticulos> arti_ped;
    std::map<Pedido*, ItemsPedido, OrdenaPedidos> ped_arti;
};

//Sobrecarga del operador << para la clase Pedido_Articulo
std::ostream& operator <<(std::ostream& os, const Pedido_Articulo::ItemsPedido& itemped);
std::ostream& operator <<(std::ostream& os, const Pedido_Articulo::Pedidos& ped);

//Sobrecarga del operador << para la clase LineaPedido
std::ostream& operator <<(std::ostream& os, const LineaPedido& lp);
#endif //P3_PEDIDO_ARTICULO_HPP
