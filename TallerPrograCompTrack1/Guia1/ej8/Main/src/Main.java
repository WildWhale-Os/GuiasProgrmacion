/*
Autor: Tomas Bravo
Solucion: Propia
*/

import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

class Main {
    public static void main(String[] args) {
        final Scanner scanner = new Scanner(System.in);
        final int cases = scanner.nextInt();
        scanner.nextLine();
        Map<String, Integer> conquests = new TreeMap<>();
        for (int i = 0; i < cases; i++) {
            String name = scanner.nextLine();
            String[] parts = name.split(" ");
            if (!conquests.containsKey(parts[0])) {
                conquests.put(parts[0], 1);
            } else {
                conquests.put(parts[0], conquests.get(parts[0]) + 1);
            }
        }

        for (Map.Entry<String, Integer> entry : conquests.entrySet()) {
            System.out.println(entry.getKey() + " " + entry.getValue());
        }

        scanner.close();
    }
}