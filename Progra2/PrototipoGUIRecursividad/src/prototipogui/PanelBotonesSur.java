package prototipogui;
import java.awt.Color;
import javax.swing.*;
public class PanelBotonesSur extends JPanel{
    public PanelBotonesSur(){
        //usamos layout por defecto: flowlayout: no se hace nada
        this.setBackground(Color.yellow);
        this.add(new BotonSur("1"));
        this.add(new BotonSur("2"));
        this.add(new BotonSur("3"));
    }
}
class BotonSur extends JButton {
      public BotonSur(String s){
          super(s);
      }
}