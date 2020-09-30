package ej11;

public class Ej11 {

    public static void main(String[] args) {
       Bebida drink = new Bebida(true);
        System.out.println(drink.beber());
        System.out.println(drink.beber());
    }
    
}

class Bebida{
    private boolean llena;
    public Bebida(boolean isLlena){
        this.llena = isLlena;
    }
    
    public String beber(){
        if(llena){
            llena = !llena;
            return new String("gluglu");
        }else{
            return null;
        }
    }
}