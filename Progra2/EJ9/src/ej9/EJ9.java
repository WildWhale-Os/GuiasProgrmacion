package ej9;

public class EJ9 {

    public static void main(String[] args) {
        OtraClase var = new OtraClase(9);
        System.out.println(var.sacaDato());
    }
    
}

class OtraClase{
    private int numero;
    public OtraClase(int num){
        this.numero = num;
    }
    
    public int sacaDato(){
        return numero;
    }
}