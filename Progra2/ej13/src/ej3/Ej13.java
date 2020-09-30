package ej3;

public class Ej13 {
    public static void main(String[] args) {
        Uno uno = new Uno(1234);
        System.out.println(uno.dos.getPropiedad());
    }

}

class Uno {
    public Dos dos;

    public Uno(int propiedad) {
        dos = new Dos(propiedad);
    }
}

class Dos {
    private int propiedad;

    public Dos(int propiedad) {
        this.propiedad = propiedad;
    }

    public int getPropiedad() {
        return propiedad;
    }
}