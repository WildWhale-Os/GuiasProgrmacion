package ej15;

public class Ej15 {
    public static void main(String[] args) {
        Uno uno = new Uno(1234);
        System.out.println(uno.getPropiedad());
    }
}

class Uno{
    private Dos dos;
    public Uno(int propiedad){
        dos = new Dos(propiedad);
    }

    public int getPropiedad(){
        return dos.getPropiedad();
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
