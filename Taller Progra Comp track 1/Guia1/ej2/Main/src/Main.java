import java.math.BigInteger;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        System.out.println("The 1500'th ugly number is " + BiggestUgly(1500)+ ".");
    }

    static long BiggestUgly(int cant) {
        int cont = 0;
        long num = 0;
        while (cont < cant) {
            num++;
            if (isUgly(num)) {
                cont++;
            }

        }
        return num;
    }

    static boolean isUgly(long num) {
        if (num == 1) {
            return true;
        }
        if(isPrime(num) && num > 5){
            return false;
        } else if (isPrime(num) && num <= 5){
            return true;
        }
        ArrayList<Long> lista = PrimeDescomp(num);
        return lista.get(lista.size() - 1) <= 5;
    }

    static ArrayList<Long> PrimeDescomp(long num) {
        ArrayList<Long> primos = new ArrayList<>();
        while (num % 2 == 0) {
            if (!primos.contains((long)2)) {
                primos.add((long)2);
            }
            num /= 2;
        }

        for (long i = 3; i <= Math.sqrt(num); i += 2) {
            if (isPrime(i)) {
                while (num % i == 0) {
                    if (!primos.contains(i)) {
                        primos.add(i);
                    }
                    num /= i;
                }
            }
        }

        if (num > 2) {
            if (!primos.contains(num)) {
                primos.add(num);
            }
        }

        return primos;
    }

    static boolean isPrime(long num) {
        int cont = 0;
        int div = 0;
        while (cont != 2) {
            div++;
            if (num % div == 0) {
                cont++;
            }

        }
        return div == num;
    }


}
