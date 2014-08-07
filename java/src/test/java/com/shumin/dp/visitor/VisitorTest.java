package com.shumin.dp.visitor;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

/**
 * Unit test for Employee allocation fee applications. 
 */
public class VisitorTest extends TestCase
{
    private double epsilon = 0.00001;

    public VisitorTest( String testName ) {
        super( testName );
    }

    public static Test suite() {
        return new TestSuite( VisitorTest.class );
    }

    public void testVisitor() {
	
	PersonA pa = new PersonA(); 
	PersonB pb = new PersonB("Simon", 176.7, 31, 'M'); 
	pa.visit(pb); 
    }
}
