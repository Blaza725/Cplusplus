/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */

import java.io.FileNotFoundException;
import java.io.File;
import java.util.*;

/**
 *
 * @author Bla
 */
public class DaotuApplication {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); 
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0) {
            String s = sc.nextLine();
            String result = normalize(s);
            System.out.println(result);
        }
    }

    public static String normalize(String s) {
        String[] words = s.trim().split("\\s+");
        StringBuilder sb = new StringBuilder();
        String str = "";
        for (String w : words) {
            sb.append(w);
            sb.reverse();
            str += sb.toString() + " ";
            sb.delete(0, sb.length());
        }
        return str.trim();
    }
}

