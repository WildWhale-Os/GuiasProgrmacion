package prototipogui;
import java.awt.BorderLayout;
import javax.swing.*;
public class VentanaGUI extends JFrame {
    private PanelCentral pc;
    private PanelBotonesSur pbs;
    public VentanaGUI(){
        this.setLayout(new BorderLayout());
        pc = new PanelCentral();//se debe cambiar nombre de acuerdo al tema del proyecto
        this.add(pc, BorderLayout.CENTER);
        pbs = new PanelBotonesSur();
        this.add(pbs, BorderLayout.SOUTH);
        
        
        
        
        
        
        
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.setSize(1000,800); 
        this.setVisible(true);  
    }
}
