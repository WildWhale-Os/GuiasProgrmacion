public class Main {
    public static void main(String[] args) {
        Uno uno = new Uno();
    }
}

class Comun {
    protected Comun otro;
}

class Uno extends Comun{
    public Uno(){
        this.otro = new Dos(this);
    }

    public String yama(){
        Dos aux = (Dos)otro;
        return aux.yama();
    }

    public String vuelta(){
        
        return new String("logrado");
    }
}

class Dos extends Comun{
    public Dos(Uno uno){
        this.otro = uno;
    }

    public String yama(){
        Uno aux = (Uno) otro;
        return aux.vuelta();
    }
}