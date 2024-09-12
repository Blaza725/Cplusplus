
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
public class dia_chi_email {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); 
        int t = sc.nextInt();
        sc.nextLine();
        Map<String, Integer> cnt = new HashMap<>();
        while (t-- > 0) {
            String s = sc.nextLine();
            String nz = normalize(s, cnt);
            System.out.println(nz);
        }
    }

    public static String normalize(String s, Map<String, Integer> cnt) {
        String[] words = s.trim().split("\\s+");
        StringBuilder sb = new StringBuilder();

        String firstname = words[words.length - 1].toLowerCase();
        sb.append(firstname);

        for(int i = 0; i < words.length - 1; i++) {
            String word = words[i].trim();
            if (!word.isEmpty()) {
                sb.append(word.toLowerCase().charAt(0));
            }
        }

        String email = sb.toString() + "@ptit.edu.vn";
        if (cnt.containsKey(email)) {
            int val = cnt.get(email) + 1;
            cnt.put(email, val);
            return email.replace("@ptit.edu.vn", val + "@ptit.edu.vn");
        } else {
            cnt.put(email, 1);
            return email;
        }
    }
}

