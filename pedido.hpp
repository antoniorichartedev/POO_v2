//
// Created by antonio on 5/05/22.
//

#ifndef P3_PEDIDO_HPP
#define P3_PEDIDO_HPP
#include "../P2/tarjeta.hpp"
#include "../P1/fecha.hpp"
#include "../P2/usuario.hpp"

class Pedido{
public:
    Pedido(Usuario& user, const Tarjeta& tarj, const Fecha& fech = Fecha());
    int numero() const {return _numeropedido;};
    const Tarjeta* tarjeta() const {return _tarjeta;};
    unsigned total() const {return _importetotal;};
    Fecha fecha() const {return f;};

    class Vacio{
    public:
        Vacio(Usuario& user): _user(&user){}
        Usuario& usuario() const {return *_user;};
    private:
        Usuario* _user;
    };

    class Impostor{
    public:
        Impostor(Usuario& user): _user(&user){}
        Usuario& usuario() const {return *_user;};
    private:
        Usuario* _user;
    };

    class SinStock{
    public:
        SinStock(Articulo& art): _art(&art){}
        Articulo& articulo() const {return *_art;};
    private:
        Articulo* _art;
    };

private:
    int _numeropedido;
    const Tarjeta *_tarjeta;
    Fecha f;
    unsigned _importetotal;
    int cantidad_pedidos;
};
#endif //P3_PEDIDO_HPP
