package herencia;

public class Herencia {
    public static void main(String[] args) {
        CuatroOperaciones operaciones = new CuatroOperaciones(50,5);
        System.out.println(operaciones.suma());
        System.out.println(operaciones.resta());
        System.out.println(operaciones.multiplica());
        System.out.println(operaciones.divide());

    }
}

class SumaResta {
    protected float uno;
    protected float dos;

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
}

class CuatroOperaciones extends SumaResta {
    public CuatroOperaciones(float uno, float dos) {
        super(uno, dos);
    }

    public float multiplica() {
        return uno * dos;
    }

    public float divide() {
        return uno / dos;
    }
}