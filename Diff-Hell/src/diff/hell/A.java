/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package diff.hell;

import java.math.BigInteger;
import java.security.SecureRandom;
/**
 *
 * @author Adrian
 */
public class A {
    BigInteger n;
    BigInteger g;
    BigInteger secret;
    BigInteger X;
    BigInteger key;
    A(BigInteger N, BigInteger G){
        n=N;
        g=G;
        secret=secret.probablePrime(5,new SecureRandom());
    }
        void calcX(){
        X=g.pow(secret.intValue());
        X=X.mod(n);
    }
      void calcK(BigInteger R){
        key=R.pow(secret.intValue());
        key=key.mod(n);
    }
}
