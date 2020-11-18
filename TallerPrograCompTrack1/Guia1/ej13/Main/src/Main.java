import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int cases = in.nextInt();
        for(int i =0 ; i < cases; i++){
            String [] datos= in.nextLine().split(" ");
            int lenght =  datos.length;
            int num1 = Integer.parseInt(datos[0]);
            double resultado = 0;
            switch (lenght) {
                case 4:
                int num2 = Integer.parseInt(datos[2]);
                resultado += num2 * 0.05;
            
                default:
                    resultado += num1 * 0.5;
                    break;
            }
            System.out.println("Case "+(i+1)+": "+Impresion(resultado));
        }
        in.close();
    }

    public static String Impresion(double num)
{
    if(num == (long) num)
        return String.format("%d",(long)num);
    else
        return String.format("%s",num);
}
}