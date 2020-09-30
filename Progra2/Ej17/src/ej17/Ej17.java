package ej17;

public class Ej17 {
    public static void main(String[] args) {
        SumaResta var = new SumaResta(2f, 4.43f);
        System.out.println(var.suma());
        System.out.println(var.resta());
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
        if (dos > uno) {
            return dos - uno;
        } else {
            return uno - dos;
        }
    }
}
