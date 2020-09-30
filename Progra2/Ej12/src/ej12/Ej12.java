package ej12;

public class Ej12 {

    public static void main(String[] args) {
        Promediador a = new Promediador();
        a.agregaNumero(4);
        a.agregaNumero(1);
        a.agregaNumero(7);
        a.agregaNumero(3);
        a.agregaNumero(7);
        System.out.println(a.promedio());
        System.out.println(a.numero());
    }

}

class Promediador {

    private int s;
    private int n;

    public Promediador() {
        this.s = 0;
        this.n = 0;
    }
    
    public void agregaNumero(int num){
        s = s + num;
        n++;
    }
    
    public float promedio(){
        return (float)s/(float)n;
    }
    
    public int numero(){
        return n;
    }
}
