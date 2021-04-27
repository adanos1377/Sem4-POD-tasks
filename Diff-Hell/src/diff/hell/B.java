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
public class B {
    BigInteger n;
    BigInteger g;
    BigInteger secret;
    BigInteger Y;
    BigInteger key;
    B(BigInteger N, BigInteger G){
        n=N;
        g=G;
        secret=secret.probablePrime(5,new SecureRandom());
    }
    void calcY(){
        Y=g.pow(secret.intValue());
        Y=Y.mod(n);
    }
    void calcK(BigInteger R){
        key=R.pow(secret.intValue());
        key=key.mod(n);
    }
}
