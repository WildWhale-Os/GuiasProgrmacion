package e;

public class E {
    
    static int b[]={3,2,1,5,7,3,0,10,5};
    
    public static void main(String[] args) {
        int promedio = 0;
        
        for(int i: b){
            promedio += i;
        }
        
        System.out.println((float)promedio/(float)b.length);
    }
    
}
