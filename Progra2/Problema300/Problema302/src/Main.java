public class Main {
    public static void main(String[] args) {
        Geometrica rect = new Rectangulo(1.0, 1.0);
        Geometrica tri = new Triangulo(1.0, 1.0);
        System.out.println(rect.area());
        System.out.println(tri.area());
        System.out.println(rect.perimetro());
        System.out.println(tri.perimetro());

    }
}

abstract class Geometrica {
    protected float ancho;
    protected float alto;

    public Geometrica(double ancho, double alto) {
        this.ancho = (float)ancho;
        this.alto = (float)alto;
    }

    public abstract  float area();

    public abstract  float perimetro();
}

class Rectangulo extends Geometrica {

    public Rectangulo(double ancho, double alto) {
        super(ancho, alto);
    }

    @Override
    public float area() {
        return (ancho * alto);
    }

    @Override
    public float perimetro() {
        return (2 * ancho + 2 * alto);
    }

}

class Triangulo extends Geometrica {

    public Triangulo(double ancho, double alto) {
        super(ancho, alto);
    }

    @Override
    public float area() {

        return ((alto * ancho) / 2);
    }

    @Override
    public float perimetro() {
        return (float)(ancho + alto + Math.sqrt(Math.pow(ancho, 2) + Math.pow(alto, 2)));
    }

}