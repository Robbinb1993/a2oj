import java.util.*;

class Input {
   private static final Scanner scannerKeyboard = new Scanner(System.in);
   public static int getInt() {
      while (!scannerKeyboard.hasNextInt())
         scannerKeyboard.nextLine();
      return scannerKeyboard.nextInt();
   }//getInt
   public static char getChar() {
      while (!scannerKeyboard.hasNext())
         scannerKeyboard.nextLine();
      return scannerKeyboard.next().charAt(0);
   }//getChar
}//Input

class Solver {
   static final int MAXN = 200000;
   private int[] primeSum = new int[MAXN];
   private long[] fights = new long[MAXN];
   public Solver() {
      Sieve();
   }//constructor
   private void Sieve() {
      boolean[] isPrime = new boolean[MAXN];
      boolean[] flag = new boolean[MAXN];
      for (long i = 2; i < MAXN; i++) {
         if (!flag[(int)i]) {
            isPrime[(int)i] = true;
            for (long j = i * i; j < MAXN; j += i)
               flag[(int)j] = true;
         }//if
      }//for
      for (int i = 3; i < MAXN; i++)
         primeSum[i] = primeSum[i - 1] + (isPrime[i] ? 1 : 0);
      for (int i = 2; i < MAXN / 2; i++)
         fights[i] = fights[i - 1] + primeSum[2 * i - 1] - primeSum[i];
   }//Sieve
   public long solve() {
      int n = Input.getInt();
      return fights[n];
   }//solve
}//Solver

public class Main {
   public static void main(String[] args) {
      Solver solver = new Solver();
      int T = Input.getInt();
      for (int t = 1; t <= T; t++)
         System.out.println("Case " + t + ": " + solver.solve());
   }//main
}//Main

