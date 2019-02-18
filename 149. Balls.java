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
   private ArrayList<ArrayList<Integer>> lists;
   private int p, n;
   private static final Map<Character, Integer> getIndex;
   private static final Map<Integer, String> getColour;
   static {
      Hashtable<Character, Integer> tmp = new Hashtable<Character, Integer>();
      tmp.put('R', 0);
      tmp.put('G', 1);
      tmp.put('B', 2);
      getIndex = Collections.unmodifiableMap(tmp);
      Hashtable<Integer, String> tmp2 = new Hashtable<Integer, String>();
      tmp2.put(0, "Red balls");
      tmp2.put(1, "Green balls");
      tmp2.put(2, "Blue balls");
      getColour = Collections.unmodifiableMap(tmp2);
   }//initializing static finals
   public Solver() {
      lists = new ArrayList<ArrayList<Integer>>();
      for (int i = 0; i < 3; i++)
         lists.add(new ArrayList<Integer>());
   }//constructor
   public void solve() {
      p = Input.getInt();
      n = Input.getInt();
      while (n-- > 0) {
         char ch = Input.getChar();
         int cost = Input.getInt();
         lists.get(getIndex.get(ch)).add(cost);
      }//while
      for (int i = 0; i < 3; i++) {
         Collections.sort(lists.get(i));
         int rem = p;
         int idx = 0;
         int counter = 0;
         while (idx < lists.get(i).size() && lists.get(i).get(idx) <= rem) {
            rem -= lists.get(i).get(idx);
            counter++;
            idx++;
         }//while
         System.out.println(getColour.get(i) + " = " + counter);
      }//for
   }//solve
}//Solver

public class Main {
   public static void main(String[] args) {
      int T = Input.getInt();
      while (T-- > 0) {
         Solver solver = new Solver();
         solver.solve();
         System.out.println("");
      }//while
   }//main
}//Main
