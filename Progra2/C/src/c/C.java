package c;

public class C {

    public static void main(String[] args) {
        int acumulador = 0;
        for (int i = 0; i < 100; i++) {
            acumulador += (2 * i) + 1;
        }
        System.out.println("La suma es: " + acumulador);
    }
    
}
