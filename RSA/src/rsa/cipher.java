/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rsa;
import java.math.BigInteger;
import java.security.SecureRandom;

/**
 *
 * @author Adrian
 */
public class cipher {
   SecureRandom random = new SecureRandom();
   BigInteger one=new BigInteger("1");
   BigInteger d;
   BigInteger e;
   BigInteger n;
      cipher() {
      BigInteger p = new BigInteger("1009");
      BigInteger q = new BigInteger("1171");
      n    = p.multiply(q); 
      BigInteger phi = (p.subtract(one)).multiply(q.subtract(one));
       e=e.probablePrime((phi.bitLength()-4), random);
       
      d = e.modInverse(phi);
   }
     String encrypt(String message) {
         String s=new String();
        for(int i=0;i<message.length();i+=3){
            if(i+3>message.length()){
               BigInteger x=new BigInteger(message.substring(i, message.length())); 
               x=x.modPow(e, n);
               s=s+x+" ";
            }
            else{
              BigInteger x=new BigInteger(message.substring(i, i+3)); 
               x=x.modPow(e, n);
              s=s+x+" ";
            }
        }    
      return s;
   }
   String decrypt(String encrypted) {  
 String[] parts = encrypted.split(" ");
 encrypted="";
 for(String s:parts){
     BigInteger x=new BigInteger(s);
     x=x.modPow(d, n);
     encrypted=encrypted+x;
 }
      return encrypted;
   }

}
