package f;

public class F {
    
    static int R[]={3,2,1,5,7,3,0,10,5};
    
    public static void main(String[] args) {
        for(int i = 0,j = R.length -1; i < j;i++,j--){
            int aux = R[i];
            R[i] = R[j];
            R[j] = aux;
        }
        
        for(int i = 0; i < R.length; i++){
            if(i == 0)
                System.out.print(R[i]);
            else
                System.out.print(","+R[i]);
        }
        System.out.print("\n");
    }
    
}
