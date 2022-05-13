//
// Created by antonio on 5/05/22.
//

#ifndef P3_LINEAPEDIDO_HPP
#define P3_LINEAPEDIDO_HPP
#include "../P2/articulo.hpp"
#include "pedido.hpp"
#include <iostream>
class LineaPedido{
public:
    LineaPedido(const int p_venta, const unsigned cant = 1);
    int precio_venta() const {return p_venta;};
    unsigned cantidad() const {return _cantidad;};

private:
    int p_venta;
    unsigned _cantidad;
};


std::ostream& operator <<(std::ostream& os, const LineaPedido& lp);
#endif //P3_LINEAPEDIDO_HPP
