/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aproxy;
import java.awt.*;
import java.awt.event.*;
import javax.swing.JPanel;

public class MiPanel extends JPanel implements MouseListener {
    
    public MiPanel(){
        super();
        this.setBackground(Color.cyan);
        this.addMouseListener(this);
        
    }
    public void paint(Graphics g){
        super.paint(g);
    }

    public void mouseClicked(MouseEvent me) {;}
    public void mousePressed(MouseEvent me) {
        this.repaint();
    }
    public void mouseReleased(MouseEvent me) {;}
    public void mouseEntered(MouseEvent me) {;}
    public void mouseExited(MouseEvent me) {;}
}
