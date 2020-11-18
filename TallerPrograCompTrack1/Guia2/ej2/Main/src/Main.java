import java.io.EOFException;
import java.util.NoSuchElementException;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int p, q, r, s, t, u;
        while (true) {
            try {
                p = in.nextInt();
                q = in.nextInt();
                r = in.nextInt();
                s = in.nextInt();
                t = in.nextInt();
                u = in.nextInt();
                float result = partision(0,1,p,q,r,s,t,u);
            } catch (NoSuchElementException e) {
                break;
            }
        }
    }

    static float partision(float init, float end, int p, int q, int r, int s, int t, int u){
        Float x = (init+end)/2;
        if((end-init)/2 < Math.pow(10, -6)){
            if(Math.abs(equation(init, p, q, r, s, t, u)) < Math.pow(10, -6)) return init;
            if(Math.abs(equation(end, p, q, r, s, t, u)) < Math.pow(10, -6)) return end;
            Float result = equation(x, p, q, r, s, t, u);
            if(result.equals(0)) return x;
            else if(result < 0){
                if(result < equation(x+(end-init)/2, p, q, r, s, t, u))
                    return partision(x, end, p, q, r, s, t, u);
                return partision(init, x, p, q, r, s, t, u);
            }
            else {
                if(result > equation(x+(end-init)/2, p, q, r, s, t, u))
                    return partision(x, end, p, q, r, s, t, u);
                return partision(init, x, p, q, r, s, t, u);
            }
        }else return -1.0f;
    }

    static float equation(float x, int p, int q, int r, int s, int t, int u) {
        return (float) (p * Math.exp(-1 * x) + q * Math.sin(x) + r * Math.cos(x) + s * Math.tan(x) + t * Math.pow(x, 2)
                + u);
    }
}
