package expendedor1;

import java.util.ArrayList;

public class Expendedor1 {
    public static void main(String[] args) {
        Expendedor maquina = new Expendedor(2);
        Moneda moneda = new Moneda();
        Bebida bebida = maquina.comprarBebida(moneda,1);
        System.out.println(bebida.getSerie());
        System.out.println(bebida.beber());
        bebida = maquina.comprarBebida(moneda,1);
        System.out.println(bebida.getSerie());
        System.out.println(bebida.beber());
        System.out.println(maquina.comprarBebida(moneda,1));
    }
}

class Expendedor{
    private Deposito coca;
    private Deposito sprite;
    public Expendedor(int cant){
        coca = new Deposito();
        sprite = new Deposito();
        for(int i = 0; i<cant; ++i){
            coca.addBebida(new CocaCola(100+i));
            sprite.addBebida(new Sprite(200+i));
        }
    }

    public Bebida comprarBebida(Moneda moneda,int sabor){
        switch (sabor){
            case 1:
                return coca.getBebida();
            case 2:
                return sprite.getBebida();
            default:
                return null;
        }
    }
}

class Deposito{
    private ArrayList<Bebida>bebidas;
    public Deposito(){
        bebidas = new ArrayList<Bebida>();
    }

    public void addBebida(Bebida bebida){
        bebidas.add(bebida);
    }

    public Bebida getBebida(){
        if(bebidas.size() == 0)
            return null;
        return bebidas.remove(0);
    }
}

 abstract class Bebida{
    private int serie;
    public Bebida(int serie){
        this.serie = serie;
    }

     public int getSerie() {
         return serie;
     }

     public String beber(){
        return "sabor: ";
     }
 }

 class Sprite extends Bebida{
    public Sprite(int serie){
        super(serie);
    }

     @Override
     public String beber() {
         return super.beber() + "sprite";
     }
 }

 class CocaCola extends Bebida{
     public CocaCola(int serie){
         super(serie);
     }

     @Override
     public String beber() {
         return super.beber() + "cocacola";
     }
 }

 class Moneda{

 }