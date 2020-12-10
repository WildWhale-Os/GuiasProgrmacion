package prototipogui;
import geometricas.RellenaConPuntos;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;
import javax.swing.JPanel;
public class PanelCentral extends JPanel implements MouseListener {
    private Polygon p;
     public PanelCentral(){
         this.setBackground(Color.cyan);
         p = new Polygon();
         p.addPoint(100, 100);//agrego el primer punto
         RellenaConPuntos.nuevaLinea(100, 100, 250, 250, p);//no agrega los puntos extremos
         p.addPoint(250, 250);
         RellenaConPuntos.nuevaLinea(250, 250, 400, 100, p);//no agrega los puntos extremos
         p.addPoint(400, 100);
         this.addMouseListener(this);
     }
     public void paint(Graphics g){
         super.paint(g);
         g.setColor(Color.BLACK);
         g.drawPolyline(p.xpoints, p.ypoints, p.npoints);
     }

    @Override
    public void mouseClicked(MouseEvent e) {;}


    int xa,ya;
    public void mousePressed(MouseEvent e) {
        p= new Polygon();
        xa=e.getX();ya= e.getY();
        p.addPoint(xa, ya);
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        RellenaConPuntos.nuevaLinea(xa, ya, e.getX(), e.getY(), p);
        p.addPoint(e.getX(), e.getY());
        repaint();
    }

    @Override
    public void mouseEntered(MouseEvent e) {;}

    @Override
    public void mouseExited(MouseEvent e) {;}
}
class Trazo {
    private Polygon p;
    public Trazo(){
        p = new Polygon();
    }    
}

