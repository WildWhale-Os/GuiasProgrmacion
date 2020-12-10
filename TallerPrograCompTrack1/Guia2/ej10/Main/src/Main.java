import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner (System.in);
        while(!scanner.hasNext("#")){
            String aux = scanner.nextLine();
            Stack<Queue<String>> mazo = new Stack<>();
            for (String string : aux.split(" ")) {
                Queue<String> pos =  new LinkedList<>();
                pos.add(string);
                mazo.push(pos);
            }
            aux = scanner.nextLine();
            for (String string : aux.split(" ")) {
                Queue<String> pos =  new LinkedList<>();
                pos.add(string);
                mazo.push(pos);
            }
            Iterator<Queue<String>> i = mazo.iterator();
            while (i.hasNext()) {
                Queue<String> act = mazo.peek();
                if(mazo.get(mazo.size()-4).peek().charAt(0) == act.peek().charAt(0)){
                    mazo.pop();
                    for (String string : act) {
                        mazo.get(mazo.size()-4).add(string);
                    }
                }else if(mazo.get(mazo.size()-4).peek().charAt(1) == act.peek().charAt(1)){
                    mazo.pop();
                    for (String string : act) {
                        mazo.get(mazo.size()-4).add(string);
                    }
                }else if(mazo.get(mazo.size()-2).peek().charAt(0) == act.peek().charAt(0)){
                    mazo.pop();
                    for (String string : act) {
                        mazo.get(mazo.size()-2).add(string);
                    }
                }else if(mazo.get(mazo.size()-2).peek().charAt(1) == act.peek().charAt(1)){
                    mazo.pop();
                    for (String string : act) {
                        mazo.get(mazo.size()-2).add(string);
                    }
                }
                System.out.print(mazo.size()+ " ");
                for (Queue<String> queue : mazo) {
                    System.out.print(queue.size() + " ");
                }
                System.out.print("\n");
            }
        }
        scanner.close();
    }
}