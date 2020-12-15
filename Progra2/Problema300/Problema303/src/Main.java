public class Main {
    public static void main(String[] args) {
        ProxyGeometricas pxyA = ProxyGeometricas.getInstancia();
        ProxyGeometricas pxyB = ProxyGeometricas.getInstancia();
        ProxyGeometricas pxyC = ProxyGeometricas.getInstancia();
        Geometrica rect = new Rectangulo(1.0, 1.0);
        Geometrica tri = new Triangulo(1.0, 1.0);

        System.out.println(pxyA == pxyB);
        System.out.println(pxyA==pxyC);

        pxyA.setGeometrica(rect);
        
        System.out.println(pxyB.perimetro());
        System.out.println(pxyC.perimetro());
        System.out.println(rect.perimetro());
        System.out.println(pxyB.area());
        System.out.println(pxyC.area());
        System.out.println(rect.area());

        pxyA.setGeometrica(tri);

        System.out.println(pxyB.perimetro());
        System.out.println(pxyC.perimetro());
        System.out.println(tri.perimetro());
        System.out.println(pxyB.area());
        System.out.println(pxyC.area());
        System.out.println(tri.area());
    }
}

interface Proxy {
    public void setGeometrica(Geometrica fig);
}

class ProxyGeometricas implements Proxy {
    private static ProxyGeometricas proxy;
    private Geometrica geometry;

    private ProxyGeometricas() {
        proxy = null;
        geometry = null;
    }

    public static ProxyGeometricas getInstancia() {
        if (proxy == null) {
            proxy = new ProxyGeometricas();
        }
        return proxy;
    }

    public float perimetro() {
        return geometry.perimetro();
    }

    public float area() {
        return geometry.area();
    }

    @Override
    public void setGeometrica(Geometrica fig) {
        geometry = fig;
    }

}

abstract class Geometrica {
    protected float ancho;
    protected float alto;

    public Geometrica(double ancho, double alto) {
        this.ancho = (float) ancho;
        this.alto = (float) alto;
    }

    public abstract float area();

    public abstract float perimetro();
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
        return (float) (ancho + alto + Math.sqrt(Math.pow(ancho, 2) + Math.pow(alto, 2)));
    }

}