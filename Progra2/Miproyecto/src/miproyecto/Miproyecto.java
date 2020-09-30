package miproyecto;

public class Miproyecto {

    public static void main(String[] args) {
        PrimeraClase p = new PrimeraClase("blabla");
        System.out.println(p.getString());
    }
    
}


class PrimeraClase{
    private String cadena;
    public PrimeraClase(String cadena){
        this.cadena = cadena;
    }
    
    public String getString(){
        return cadena;
    }
}