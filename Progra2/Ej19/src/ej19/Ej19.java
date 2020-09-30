package ej19;

public class Ej19 {
    public static void main(String[] args) {
        Bebida bebida = new Bebida(1234);
        bebida.llenar(bebida.VOLUMEN);
        System.out.println(bebida.getSerie());
        System.out.println(bebida.beber(100));
        System.out.println(bebida.beber(100));
        System.out.println(bebida.beber(500));
        Bebida bebida1 = new Bebida(2345);
        bebida1.llenar(200);
        System.out.println(bebida1.beber(1000));

    }
}

class Bebida{
    public static final int VOLUMEN = 500;
    private int contenido;
    private int serie;
    public Bebida(int serie){
        this.serie = serie;
        contenido = 0;
    }

    public int getSerie(){
        return serie;
    }

    public void llenar(int ml){
        contenido += ml;
        if(contenido >= Bebida.VOLUMEN){
            contenido = Bebida.VOLUMEN;
        }
    }

    public int beber(int ml){
        if(ml > contenido){
            int salida = contenido;
            contenido = 0;
            return salida;
        }else {
            contenido -= ml;
            return ml;
        }
    }

}

