package ej10;

public class Ej10 {

    public static void main(String[] args) {
        Persona ciuda1 = new Persona("pablo",true);
        Persona ciuda2 = new Persona ("Enrique", false);
        System.out.println(ciuda1.elNombre());
        System.out.println(ciuda1.esCasado());
        System.out.println(ciuda2.elNombre());
        System.out.println(ciuda2.esCasado());
        
    }

}

class Persona{
    private String nombre;
    private boolean estado;
    public Persona(String nombre, boolean estado){
        this.nombre = nombre;
        this.estado = estado;
    }
    
    public boolean esCasado(){
        return estado;
    }
    
    public String elNombre(){
        return nombre;
    }
}