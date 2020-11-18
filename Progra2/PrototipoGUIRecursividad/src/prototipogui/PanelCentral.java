package prototipogui;
import geometricas.Angular;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import javax.swing.JPanel;
import javax.swing.Timer;
public class PanelCentral extends JPanel implements ActionListener{
     private Rama rama;
     private Timer timer;
     public PanelCentral(){
         this.setBackground(Color.cyan);
         rama = new Rama(500,600,0.5);
         timer = new Timer(500,this);
         timer.start();
         
     }
     @Override
     public void paint(Graphics g){
         super.paint(g);
         if(rama!=null)rama.paint(g);         
     }
     
    @Override
    public void actionPerformed(ActionEvent e) {
            System.out.println("Crecer");
            if(rama != null)rama.crecer();
            repaint();
    }
}
class Rama {
    private int x,y,dx,dy,edad;
    private double larg, angulo;
    private Rama r1,r2;
    public Rama(int x, int y, double angulo){
        this.x = x;
        this.y = y; 
        dx = x;
        dy = y;
        larg = 0;
        this.angulo=angulo;
        edad = 0;
    }
    public void paint(Graphics g){
        g.setColor(Color.BLACK);
        //g.drawPolyline(pol.xpoints, pol.ypoints, pol.npoints);
        g.drawLine(100, 600, 800, 600);
        g.drawLine(x, y, dx, dy);
        if(r1!= null)r1.paint(g);
        if(r2!=null)r2.paint(g);
    }   
    
    public void crecer(){
        larg+=5;
        edad+=5;
        if(edad == 40)
            r1 = new Rama(dx,dy,angulo - 0.25);
        if(edad == 60)
            r2 = new Rama(dx,dy,angulo + 0.25);
        Point aux = Angular.generaPunto(new Point(x,y), larg, angulo);
        dx = aux.x;
        dy = aux.y;
        if(r1!= null)r1.crecer();
        if(r2!=null)r2.crecer();
    }
}
