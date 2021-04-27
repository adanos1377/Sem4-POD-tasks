/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rsa;

import java.math.BigInteger;

/**
 *
 * @author Adrian
 */
public class RSA {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
      //int N = Integer.parseInt(args[0]);
      cipher key = new cipher();

 
      // create random message, encrypt and decrypt
      //BigInteger message = new BigInteger("420");

      //// create message by converting string to integer
      String s = "12345678951234567890123456789012345678951234567890";

      //byte[] bytes = s.getBytes();
      //BigInteger message = new BigInteger(s);
     String encrypt = key.encrypt(s);
     String decrypt = key.decrypt(encrypt);
      System.out.println("message   = " + s);
      System.out.println("encrypted = " + encrypt);
      System.out.println("decrypted = " + decrypt);
    }
    
}
