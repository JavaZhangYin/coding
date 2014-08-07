import java.util.PriorityQueue; 
import java.util.Random; 

import java.io.PrintWriter; 
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.FileNotFoundException; 


class TopTen {
    public static void getTopTen (String filename) {
	PriorityQueue<Integer> queue = new PriorityQueue<Integer>();

	BufferedReader br = null; 
	int offset = 0; 
	int len = 1024 * 8; // read 8kb each read.
	char [] buffer = new char[len+1]; 
	int size; 
	try {
 
	    String sCurrentLine;
 
	    br = new BufferedReader(new FileReader(filename));
 
	    while(br.ready()) {
		size = 0; 
		try {
		    size = br.read(buffer, offset, len); 
		    if(size <= 0) break; 

		} catch (Exception e) { break; }
		
		while (buffer[size] != '\n') size--; 
		offset += size; 

		String [] lines = new String(buffer, 0, size).split("\n"); 
		for(String line: lines) {

		    int val = Integer.parseInt(line.trim()); 
		    if(queue.size() < 10) {
			queue.add(val); 
		    } else {
			if(val > queue.peek()) {
			    queue.poll(); 
			    queue.add(val); 
			}
		    }
		}
	    }

	    // print result. 
	    while(queue.size() > 0) {
		System.out.println(queue.poll()); 
	    }
	    
	} catch (IOException e) {
	    e.printStackTrace();
	} finally {
	    try {
		if (br != null)br.close();
	    } catch (IOException ex) {
		ex.printStackTrace();
	    }
	}
    }

    public static void main(String [] args) throws FileNotFoundException {
	int size = 1024 * 1024 * 16; 
	Random rnd = new Random(); 
	String file = "dat.txt"; 
	PrintWriter writer = new PrintWriter(file); 
	for(int i = 0; i < size; i++) {
	    writer.println(rnd.nextInt() % 1000); 
	}

	writer.close(); 

	getTopTen(file); 
    }
}
