package aproxy;
import java.awt.Color;
import javax.swing.ButtonGroup;
import javax.swing.JPanel;

public class PanelSur extends JPanel{
    public PanelSur(MiPanel mp){
        super();
        this.setBackground(Color.yellow);
        BotonSur bs1 = new BotonSur("b1",mp);
        this.add(bs1);
        BotonSur bs2 = new BotonSur("b2",mp);
        this.add(bs2);
    }   
}
