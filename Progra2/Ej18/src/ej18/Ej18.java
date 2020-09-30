package ej18;

public class Ej18 {
    public static void main(String[] args) {
        CuatroOperaciones var = new CuatroOperaciones(2.43f, 4.50f);
        System.out.println(var.multiplica());
        System.out.println(var.divide());
        System.out.println(var.suma());
        System.out.println(var.resta());
    }
}

class CuatroOperaciones {
    private SumaResta var;

    public CuatroOperaciones(float uno, float dos) {
        var = new SumaResta(uno, dos);
    }

    public float multiplica() {
        return var.getDos() * var.getUno();
    }

    public float divide() {
        return var.getUno() / var.getDos();

    }

    public float suma() {
        return var.suma();
    }

    public float resta() {
        return var.resta();
    }
}

class SumaResta {
    private float uno;
    private float dos;

    public SumaResta(float uno, float dos) {
        this.uno = uno;
        this.dos = dos;
    }

    public float suma() {
        return dos + uno;
    }

    public float resta() {
        return uno - dos;
    }

    public float getUno() {
        return uno;
    }

    public float getDos() {
        return dos;
    }
}
