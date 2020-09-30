package demostracionesclases;

public class DemostracionesClases {

    public static void main(String[] args) {
        Botella botella1 = new Botella(1000);
        System.out.println(botella1.getVol());
    }
    
}

class Botella{
    private int vol;
    public Botella(int vol){
        this.vol = vol;
    }
    
    public int getVol(){
        return this.vol;
    }
}