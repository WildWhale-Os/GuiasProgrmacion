package d;

public class D {

    public static void main(String[] args) {
        int R[]={3,2,1,5,7,3,0,10};
        int mayor = -100000000;
        
        for(int i: R){
            if(i > mayor){
                mayor = i;
            }
        }
        
        System.out.println(mayor);
    }
    
}
