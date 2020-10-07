package depositobebida1;

import java.util.ArrayList;

public class DepositoBebida1 {
    public static void main(String[] args) {
        Deposito deposito = new Deposito();
        deposito.addBebida(new Fanta(1));
        deposito.addBebida(new Kem(2));
        deposito.addBebida(new Sprite(3));
        deposito.addBebida(new CocaCola(4));
        Bebida bebida = deposito.getBebida();
        System.out.println(bebida.getSerie());
        System.out.println(bebida.beber());
    }
}

class Deposito {
    private ArrayList<Bebida>deposito;
    public Deposito(){
        deposito = new ArrayList<Bebida>();
    }
    public void addBebida(Bebida bebida){
        deposito.add(bebida);
    }

    public Bebida getBebida(){
        if(deposito.size() == 0)
            return null;
        return deposito.remove(0);
    }
}

abstract class Bebida {
    private int serie;

    public Bebida(int numSerie) {
        serie = numSerie;
    }

    public int getSerie() {
        return serie;
    }

    abstract String beber();
}

class Sprite extends Bebida {
    public Sprite(int serie) {
        super(serie);
    }

    @Override
    public String beber() {
        return "sprite";
    }
}

class Fanta extends Bebida {
    public Fanta(int serie) {
        super(serie);
    }

    @Override
    public String beber() {
        return "fanta";
    }
}

class Kem extends Bebida {
    public Kem(int serie) {
        super(serie);
    }

    @Override
    public String beber() {
        return "kem";
    }
}

class CocaCola extends Bebida {
    public CocaCola(int serie) {
        super(serie);
    }

    @Override
    public String beber() {
        return "cocacola";
    }
}