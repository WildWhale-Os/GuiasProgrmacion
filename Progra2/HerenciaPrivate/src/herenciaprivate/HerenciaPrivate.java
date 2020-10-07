package herenciaprivate;

public class HerenciaPrivate {
    public static void main(String[] args) {
        CuatroOperaciones op = new CuatroOperaciones(50 ,5);
        System.out.println(op.suma());
        System.out.println(op.resta());
        System.out.println(op.multiplica());
        System.out.println(op.divide());
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
        return uno + dos;
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

class CuatroOperaciones extends SumaResta {
    public CuatroOperaciones(float uno, float dos) {
        super(uno, dos);
    }

    public float multiplica() {
        return getUno() * getDos();
    }

    public float divide() {
        return getUno() / getDos();
    }
}