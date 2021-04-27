/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package diff.hell;

import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author Adrian
 */
public class DiffHell {

    /**
     * @param args the command line arguments
     */
 public static void main(String args[])
 {
 BigInteger N=new BigInteger("1113");
 BigInteger G=new BigInteger("1009");
     A a=new A(N,G);
     B b=new B(N,G);
     a.calcX();
     b.calcY();
   System.out.println("A: wartość X="+a.X+", "+"A: wartość klucza prywatnego="+a.secret);
   System.out.println("B: wartość Y="+b.Y+", "+"B: wartość klucza prywatnego="+b.secret);
   System.out.println("Przesłanie wyznaczonych X i Y");
     a.calcK(b.Y);
     b.calcK(a.X);
   System.out.println("A: obliczony klucz sesji="+a.key);
   System.out.println("B: obliczony klucz sesji="+b.key);
 } 
    
}
