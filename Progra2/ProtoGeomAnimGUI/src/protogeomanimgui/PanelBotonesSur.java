package protogeomanimgui;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
public class PanelBotonesSur extends JPanel{
    public PanelBotonesSur(PanelCentral pc){
        //usamos layout por defecto: flowlayout: no se hace nada
        this.setBackground(Color.yellow);
        this.add(new BotonIzq("izquierda",pc));
        this.add(new BotonDer("derecha",pc));
    }
}
class BotonIzq extends JButton implements ActionListener {
      private PanelCentral pc;
      public BotonIzq(String s,PanelCentral pc ){
          super(s);
          this.pc=pc;
          this.addActionListener(this);
      }
    public void actionPerformed(ActionEvent e) {
        pc.repaint();
    }
}
class BotonDer extends JTextField implements ActionListener {
      private PanelCentral pc;
      public BotonDer(String s,PanelCentral pc ){
          super(s,30);
          this.pc=pc;
          this.addActionListener(this);
      }
    public void actionPerformed(ActionEvent e) {
        System.out.println(this.getText());
        this.setText("");
        pc.repaint();
    }
}
