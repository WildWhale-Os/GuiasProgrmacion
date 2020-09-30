package ej16;

public class Ej16 {
    public static void main(String[] args) {
        Dos dos = new Dos(1234);
        Uno uno = new Uno(dos);
        System.out.println(uno.getPropiedad());
    }
}

class Uno{
    private Dos dos;
    public Uno(Dos dos){
        this.dos = dos;
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
