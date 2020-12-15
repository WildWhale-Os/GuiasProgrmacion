public class Main {
    public static void main(String[] args){
        Uno uno = new Uno();
        Tres.tres.set(1234);
        int r = Tres.tres.get();
        System.out.println(r);
    }
}

class Uno{
    private Dos dos;
    private A a;

    public Uno() {
        a = new A();
        dos = new Dos(a);

    }

    public void set(int num) {
        dos.set(num);
    }

    public int get() {
        return dos.get();
    }
}

class Dos{
    private Tres tres;

    public Dos(A a) {
        tres = new Tres(a);
    }

    public void set(int numero) {
        tres.set(numero);
    }

    public int get() {
        return tres.get();
    }
}

class A{
    private B b;

    public A() {
        b = new B();
    }

    public void setInt(int numero) {
        b.setInt(numero);
    }

    public int getInt() {
        return b.getInt();
    }

}

class Tres{
    private A a;
    static Tres tres;
    public Tres(A a) {
        this.a = a;
        tres =  this;
    }

    public void set(int num) {
        a.setInt(num);
    }

    public int get() {
        return a.getInt();
    }
}

class B {
    private int numero;

    public B() {

    }

    public void setInt(int numero) {
        this.numero = numero;
    }

    public int getInt() {
        return numero;
    }
}