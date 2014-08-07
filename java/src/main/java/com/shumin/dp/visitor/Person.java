package com.shumin.dp.visitor;

abstract class Person {
    private String name; 
    private double height; 
    private int age; 
    private char sex; // M/F; 

    Person(String n, double h, int a, char s) {
	name = n; 
	height = h; 
	age = a; 
	sex = s; 
    }

    public void print() {
	System.out.println("Name: " + name +
			   "\nHeight: " + height + 
			   "\nAge: " + age +
			   "\nSex: " + sex); 
    }

    abstract public void printClass(); 
    abstract public void sayHello(); 
}
