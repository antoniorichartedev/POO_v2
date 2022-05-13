//
// Created by antonio on 9/05/22.
//

#include "pedido-articulo.hpp"
#include <utility>

Pedido_Articulo::ItemsPedido& Pedido_Articulo::detalle(Pedido& p1){
    return ped_arti[&p1];
}

Pedido_Articulo::Pedidos Pedido_Articulo::ventas(Articulo &a1) {
    return arti_ped[&a1];
}

void Pedido_Articulo::pedir(Articulo &articulo1, Pedido &pedido1, double precio, unsigned int cant) {
    pedir(pedido1, articulo1, precio, cant);
}

void Pedido_Articulo::pedir(Pedido &pedido1, Articulo &articulo1, double precio, unsigned int cant) {
    arti_ped[&articulo1].insert(std::make_pair(&pedido1 ,LineaPedido(precio, cant)));
    ped_arti[&pedido1].insert(std::make_pair(&articulo1, LineaPedido(precio, cant)));
}

// ------------------------ clase LineaPedido (inicio) --------------------------
LineaPedido::LineaPedido(double pr_venta, unsigned int cant): p_venta(pr_venta), _cantidad(cant){}

//sobrecarga del operador << de la clase LineaPedido
std::ostream& operator <<(std::ostream& os, const LineaPedido& linped){
    os << "" << linped.precio_venta() << " " << "€" << "    " << linped.cantidad();
    return os;
}

// ------------------------ clase LineaPedido (final) --------------------------

std::ostream& Pedido_Articulo::mostrarDetallePedidos(std::ostream& os){

    // inicializamos el valor de precio a 0.
    double precio = 0;

    // utilizando iteradores, vamos a ir mostrando todo el detalle de los pedidos que tengamos.
    for(auto it = ped_arti.begin(); it != ped_arti.end(); it++){
        os << "Pedido num. " << (it->first)->numero() << "\n" << "Cliente: " << (it->first)->tarjeta()->titular() <<
        "\t\t " << "Fecha: " << (it->first)->fecha() << "\n" << "TOTAL VENTAS: " << (it->second);

        // calculamos el total de las ventas
        precio = precio + (it->first)->total();

        // ahora lo mostramos por pantalla
        os << "" << precio;
        return os;
    }
}

std::ostream& Pedido_Articulo::mostrarVentasArticulos(std::ostream &os) {

    // utilizando iteradores, vamos mostrando todo el detalle de las ventas que hayamos realizado.

    for (auto it = arti_ped.begin(); it != arti_ped.end(); it++){
        os << "Ventas de [" << (it->first)->referencia() << " ''" << (it->first)->titulo() << "''" << (it->second);
    }

    return os;
}

std::ostream& operator <<(std::ostream& os, const Pedido_Articulo::ItemsPedido& itped){

    // inicializamos el valor del precio total del pedido, que nos servirá para luego.
    double precioT = 0;

    // mostramos el cuerpo del recibo.
    os << "PVP\tCantidad\t\tArticulo\n" << "==================================================================\n";

    // mediante iteradores, vamos mostrando la info. de los pedidos.
    for (auto it = itped.begin(); it != itped.end(); it++){
        os << "" << (it->first)->precio() << "€ " << (it->first)->stock() << "\t\t[" << (it->first)->referencia() <<
        "] ''" << (it->first)->titulo() << "''\n";
        precioT = precioT + ((it->second).precio_venta() * (it->second).cantidad());
    }

    // una vez que hayamos mostrado todos los articulos del pedido, vamos a terminar de poner bonito el cuerpo del recibo.
    // También, mostraremos el precio total del pedido, calculado anteriormente.
    os << "==================================================================\n" << "Total\t" << precioT;

}

std::ostream& operator <<(std::ostream& os, const Pedido_Articulo::Pedidos& ped){
    // inicializamos una variable numPedidos a 0, para ir contando los pedidos que tenemos en total.
    unsigned numPedidos = 0;

    // tambien inicializamos otra para calcular el precio total de los pedidos.
    double precioT = 0;

    os << "[Pedidos: ";

    // vamos mostrando el recibo, lo hacemos mediante iteradores.
    for (auto it = ped.begin(); it != ped.end(); it++){
        numPedidos += (it->second).cantidad();
        os << "]\n" << numPedidos << "PVP\tCantidad\t\tFecha de Venta\n\n" << " € " << (it->second).precio_venta() <<
        " " << (it->second).cantidad() << "\t\t " << (it->first)->fecha();
        precioT = precioT + ((it->second).precio_venta() * (it->second).cantidad());
    }

    // mostramos el precio total de los pedidos y el número total de pedidos que hay en el recibo.
    os << "" << precioT << " €\t" << numPedidos;
}

// PEDIDO_ARTICULO.cpp TERMINADO