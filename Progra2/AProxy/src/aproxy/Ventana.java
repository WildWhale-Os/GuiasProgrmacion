/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aproxy;
import java.awt.*;
import javax.swing.*;
import static javax.swing.JFrame.EXIT_ON_CLOSE;

public class Ventana extends JFrame {
    public Ventana(){
        super();
        this.setTitle("laVentana");
        this.setLayout(new BorderLayout());
        
        this.add(new JButton("norte"), BorderLayout.NORTH);
        MiPanel mp = new MiPanel();
        this.add(mp, BorderLayout.CENTER);
        
        this.add(new JButton("este"), BorderLayout.EAST);
        this.add(new JButton("oeste"), BorderLayout.WEST);
        PanelSur jp = new PanelSur(mp);
        this.add(jp, BorderLayout.SOUTH);
       
        this.setSize(800,600);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.setVisible(true);
    }

    
}

