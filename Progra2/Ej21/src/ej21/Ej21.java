package ej21;

public class Ej21 {
    public static void main(String[] args) {
        Expendedor expendedor = new Expendedor();
        Moneda moneda = new Moneda();
        System.out.println(expendedor.comprarBebida(moneda).beber());
    }
}

class Expendedor{
    public Expendedor(){

    }

    public Bebida comprarBebida(Moneda moneda){
        return  new Bebida();
    }
}

class Bebida{
    public Bebida(){

    }

    public String beber(){
        return new String("gluglu");
    }
}

class Moneda{
    public Moneda(){

    }
}