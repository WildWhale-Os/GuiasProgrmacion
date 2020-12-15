import javax.swing.*;

public class DemoSC {
    public static void main(String[] args) {
        
    }
}

class Pizzarra extends JFrame implements MouseListener{

}

class SeccionCritica{
    private int numero;
    public SeccionCritica(){
        numero = 0;
    }
    public void inc(boolean demora){
        int aux = numero;
        aux++;
        if(demora){
            try{
                Thread.sleep(8000);
            }catch(Exception ex){;}
            numero = aux;
        }
    }

    public void imprime(){
        System.out.println(numero);
    }
}