package ej8;

public class Ej8 {

    public static void main(String[] args) {
        Bebida var = new Bebida();
        System.out.println(var.beber());
    }
    
}

class Bebida{
    
    public Bebida(){
        
    }
    
    public String beber(){
        return new String("gluglu");
    }
}