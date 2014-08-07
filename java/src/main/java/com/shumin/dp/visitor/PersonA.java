package com.shumin.dp.visitor; 

public class PersonA implements Visitor {
    @Override
    public void visit(Person person) {
	person.sayHello(); 
	person.print(); 
	person.printClass(); 
    } 
}
