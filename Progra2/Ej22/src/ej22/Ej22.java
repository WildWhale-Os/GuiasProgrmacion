package ej22;

import java.util.ArrayList;

public class Ej22 {
    public static void main(String[] args) {
        Expendedor expendedor = new Expendedor(20);
        Moneda moneda = new Moneda();
        Bebida b = expendedor.comprarBebida(moneda);
        System.out.println(b.beber());
        System.out.println(b.getSerie());
    }
}

class Expendedor {
    private Deposito deposito;
    public Expendedor(int num) {
        deposito = new Deposito(num);
        for(int i = 0; i < num; i++){
            deposito.addBebida(new Bebida(i));
        }
    }
    public Bebida comprarBebida(Moneda moneda){
        return deposito.getBebida();
    }
}

class Deposito {
    private ArrayList<Bebida> almacen;
    private int numero;
    public Deposito(int numero) {
        almacen = new ArrayList<Bebida>();
        this.numero = numero;
    }

    public void addBebida(Bebida bebida) {
        almacen.add(bebida);
    }

    public Bebida getBebida() {

        if (almacen.size() == 0) {
            return null;
        } else {
            Bebida salida = almacen.get(0);
            almacen.remove(0);
            return salida;
        }
    }

}

class Bebida {
    private int serie;

    public Bebida(int serie) {
        this.serie = serie;
    }

    public int getSerie() {
        return serie;
    }


    public String beber() {
        return new String("gluglu");
    }

}

class Moneda{
    public Moneda(){

    }
}

