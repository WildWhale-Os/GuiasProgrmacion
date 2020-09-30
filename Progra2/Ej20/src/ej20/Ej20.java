package ej20;

import java.util.ArrayList;

public class Ej20 {
    public static void main(String[] args) {
        Deposito almacen = new Deposito();
        Bebida bebida1 = new Bebida(1234);
        Bebida bebida2 = new Bebida(4567);
        almacen.addBebida(bebida1);
        almacen.addBebida(bebida2);
        System.out.println(almacen.getBebida().getSerie());
        System.out.println(almacen.getBebida().getSerie());
        System.out.println(almacen.getBebida());
    }
}

class Deposito {
    private ArrayList<Bebida> almacen;

    public Deposito() {
        almacen = new ArrayList<Bebida>();
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


    public int beber() {
        return 0;
    }

}