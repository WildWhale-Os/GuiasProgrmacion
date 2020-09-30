package ej14;

public class Ej14 {
    public static void main(String[] args) {
        Uno uno = new Uno(1234);
        System.out.println(uno.getDos().getPropiedad());
    }
}

class Uno{
    private Dos dos;
    public Uno(int propiedad){
        dos = new Dos(propiedad);
    }

    public Dos getDos(){
        return dos;
    }
}

class Dos{
    private int propiedad;
    public Dos(int propiedad){
        this.propiedad = propiedad;
    }

    public int getPropiedad(){
        return propiedad;
    }
}