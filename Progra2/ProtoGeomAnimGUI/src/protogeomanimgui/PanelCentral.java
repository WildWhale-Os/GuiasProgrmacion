package protogeomanimgui;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import javax.swing.*;
public class PanelCentral extends JPanel implements ActionListener {
     private Timer t;
     private Movil m;
     public PanelCentral(){
         this.setBackground(Color.cyan);
         t = new Timer(100,null);
         m = new Movil(300,400);
         t.addActionListener(this);
         t.start();
     }
     public void paint(Graphics g){
         super.paint(g);
         if(m != null) m.paint(g);
     }
    public void actionPerformed(ActionEvent e) {
        m.mover();
        repaint();
    }
}
