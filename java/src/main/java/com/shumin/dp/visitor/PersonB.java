package com.shumin.dp.visitor;

public class PersonB extends Person implements Subject {
    PersonB(String n, double h, int a, char s) {
	super(n, h, a, s);
    }

    @Override
    public void accept(Visitor visitor) {
	visitor.visit(this); 
    }
    
    @Override
    public void sayHello() {
	System.out.println("hello there!!"); 
    }

    @Override
    public void printClass() {
	System.out.println(this.getClass()); 
    }

}
