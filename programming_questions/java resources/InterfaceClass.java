import java.io.*;
// '''
// 1. by default methods are abstract from java 8 and above most of the features are supported
// 2. variables/constants declared in interface are "public, static and final" modifiers
// 3. scope of methods and var in interface is very important
// '''
interface Operations {
    /*
    In Interface:
        1. default and static method must have body
        2. default methods in interface can be overrided by implementaion class
    */
    static void operation(){
        System.out.println("interface");
    }

    default void diagnosis(){
        System.out.println("diagnosis");
    }

    void sampleCollection(){
        System.out.println("collect blood samples");
    }
}

class Add implements Operations {

    public void oper(){
        Operations.operation();
    }

    public void diagnosis(){
        System.out.println("add class overrides diagnosis");
    }
}

public class MultipleInheritanceExample implements InterfaceA, InterfaceB { 
    /*
    if class does a multiple inheritance of interfaces and those interfaces have same defult methods with same signature, then 
    class must resolve the conflict by calling specific method as below using super keyword
    */
    @Override
    public void show() { 
        // Call a specific interface's default method 
        InterfaceA.super.show();
        InterfaceB.super.show();
        System.out.println("Overridden method in MultipleInheritanceExample");
    } 
}
       
class InterfaceClass{
    public static void main(String[] args){
        Add add = new Add();
        add.oper();
        add.diagnosis();
    }
}