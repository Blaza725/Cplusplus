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
public class chuan_hoa2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); 
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0) {
            String s = sc.nextLine();
            String nz = normalize(s);
            System.out.println(nz);
        }
    }

    public static String normalize(String s) {
        String[] words = s.trim().split("\\s+");
        StringBuilder sb = new StringBuilder();
        String lastName = words[0].toUpperCase(); // Họ luôn là từ đầu tiên
        
        for (int i = 1; i < words.length; i++) {
            String word = words[i].trim();
            if (!word.isEmpty()) {
                sb.append(capitalize(word)).append(" ");
            }
        }

        return sb.toString().trim() + ", " + lastName;
    }
    
    public static String capitalize(String s) {
        if (s.length() == 0) {
            return "";
        }
        return s.substring(0, 1).toUpperCase() + s.substring(1).toLowerCase();
    }
}


