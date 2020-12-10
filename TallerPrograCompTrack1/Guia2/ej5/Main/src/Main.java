import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int cases = scanner.nextInt();

        for (int i = 0; i < cases; i++) {
            Map<Integer, Participante> board = new TreeMap<>();
            int participante, problema, tiempo, resultado;
            while (scanner.hasNextInt()) {
                participante = scanner.nextInt();
                problema = scanner.nextInt();
                tiempo = scanner.nextInt();
                resultado = scanner.next().charAt(0);
                if (board.containsKey(participante))
                    board.get(participante).actuilizarTime(problema, resultado, tiempo);
                else {
                    Participante aux = new Participante();
                    aux.actuilizarTime(problema, resultado, tiempo);
                    board.put(participante, aux);
                }
            }
            for (Integer j : board.keySet())
                board.get(j).actualizarResuelto();

            Integer keys[] = ordenarKeys(board);
            for (Integer key : keys)
                System.out.format("%d %d %d\n", key, board.get(key).resuelto, board.get(key).time);

        }
        scanner.close();
    }

    static Integer[] ordenarKeys(Map<Integer, Participante> board) {
        Set<Integer> key = board.keySet();
        Integer keys[] = key.toArray(new Integer[0]);
        for (int i = 0; i < keys.length - 1; ++i) {
            for (int j = i + 1; j < keys.length; j++) {
                if (board.get(keys[i]).resuelto < board.get(keys[j]).resuelto) {
                    Integer aux = keys[i];
                    keys[i] = keys[j];
                    keys[j] = aux;
                } else if (board.get(keys[i]).time > board.get(keys[j]).time
                        && board.get(keys[i]).resuelto == board.get(keys[j]).resuelto) {
                    Integer aux = keys[i];
                    keys[i] = keys[j];
                    keys[j] = aux;
                }
            }
        }
        return keys;
    }

}

class Participante {
    static int C = 67, I = 73, R = 82, U = 85, E = 69;
    int problems[] = new int[9];
    int time;
    int resuelto;

    Participante() {
        for (int i = 0; i < problems.length; ++i)
            problems[i] = 0;
        time = 0;
        resuelto = 0;
    }

    void actualizarResuelto() {
        for (int i : problems) {
            if (i == 1)
                resuelto++;
        }
    }

    void actuilizarTime(int problem, int result, int time) {
        if (problems[problem - 1] == 0 && result == I) {
            this.time += 20;
        }
        if (problems[problem - 1] == 0 && result == C) {
            this.time += time;
            problems[problem - 1] = 1;
        }
    }
}