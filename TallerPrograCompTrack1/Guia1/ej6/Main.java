import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(final String[] args) {
        final Scanner entrada = new Scanner(System.in);
        Integer num = entrada.nextInt();
        while (num != 0) {

            System.out.print(num + " =");
            ArrayList<Integer> results = DescomposicionPrima(num);
            for (int i = 0; i < results.size(); i++) {
                if (i == 0) {
                    System.out.print(" " + results.get(i));
                } else {
                    System.out.print(" x " + results.get(i));
                }
            }
            System.out.println("");
            num = entrada.nextInt();
        }
        entrada.close();
    }

    public static ArrayList<Integer> DescomposicionPrima(Integer num) {
        ArrayList<Integer> salida = new ArrayList<Integer>();
        if (num >= 0) {
            while (num % 2 == 0) {
                salida.add(2);
                num /= 2;
            }

            for (int i = 3; i <= Math.sqrt(num); i += 2) {
                while (num % i == 0) {

                    num /= i;
                }
            }

            if (num > 2)
                salida.add(num);

        } else {
            salida.add(-1);
            num *= -1;
            while (num % 2 == 0) {
                salida.add(2);
                num /= 2;
            }

            for (int i = 3; i <= Math.sqrt(num); i += 2) {
                while (num % i == 0) {
                    salida.add(i);
                    num /= i;
                }
            }

            if (num > 2)
                salida.add(num);
        }

        return salida;
    }
}
