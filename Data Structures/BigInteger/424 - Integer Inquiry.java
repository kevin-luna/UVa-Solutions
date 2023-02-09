import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
        BigInteger sum = BigInteger.ZERO;
        String s;
        while(true){
            s=bfr.readLine();
            if(s.equals("0"))break;
            sum = sum.add(new BigInteger(s));
        }
        pw.println(sum.toString());
        pw.close();
    }
}