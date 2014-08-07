import java.lang.Math; 
import java.util.Random;

class MinkowskiDistance {
    public static double distance (double order, double []p, double []q) throws Exception {
	if(null == p || null == q) 
	    throw new Exception ("Points can't be null.");

	if(order <= 0) {
	    throw new Exception ("Order should be greater than 0."); 
	}

	int size = p.length; 
	double sum = 0.0; 
	for(int i = 0; i < size; i++) {
	    sum += Math.pow(Math.abs(p[i] - q[i]), order); 
	}
	return Math.pow(sum, 1.0/order); 
    }
    
    public static void main(String [] args) {
	final int size = 10; 
	double order = 1.25; 
	Random rnd = new Random(); 
	double [] p = new double[size];
	double [] q = new double[size]; 
	for(int i = 0; i < size; i++) {
	    p[i] = rnd.nextDouble() * 10; 
	    q[i] = rnd.nextDouble() * 10; 
	}
	
	try {
	    System.out.println(distance(order, p, q)); 
	} catch (Exception e) {
	    System.err.println(e.getMessage()); 
	}
    }
}
