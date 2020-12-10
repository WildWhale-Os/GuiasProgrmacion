import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int cases = scanner.nextInt();
        for (int i = 0; i < cases; i++) {
            int size = scanner.nextInt();
            int pos = scanner.nextInt();
            int time = 0;
            Queue<Integer> fila = new ArrayDeque<>(size);
            for (int j = 0; j < size; j++) {
                Integer aux = scanner.nextInt();
                fila.add(aux);
            }

            boolean flag = true;
            while(flag){
                Integer aux = fila.poll();
                if(pos == 0){
                    for (Integer integer : fila) {
                        if(aux < integer){
                            fila.add(aux);
                            pos = fila.size() -1;
                            break;
                        }
                    }
                    if(pos == 0){
                        time ++;
                        flag = false;
                    }
                } else{
                    int dpos = 0;
                    for (Integer integer : fila) {
                        if(aux < integer){
                            fila.add(aux);
                            dpos = fila.size();
                            break;
                        }
                    }
                    if(dpos == 0)   time ++;
                    pos--;
                }
            }
            System.out.println(time);
        }
        scanner.close();
    }    
}
