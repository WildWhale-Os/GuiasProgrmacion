package aproxy;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class BotonSur extends JButton implements ActionListener{
    protected MiPanel mp;
    public BotonSur(String s, MiPanel mp){
        super(s);
        this.mp = mp;
        this.addActionListener(this);
    }
    public void actionPerformed(ActionEvent ae){
        System.out.println("botonsur");
    }        
}
