#include "sequence.h"
#include "produce.h"
#include <iostream>
#include <string>


using namespace std;

int main() {

    //Test 1: The given example

    //sets the example values
    int start1=2;

    int start2=1;

    int length1=3;

    int length2=4;

    int repeat=4;

    Sequence<int,string> list;
    //creates the firs object and insert the example values
    list.insert_end(1,"one");
    list.insert_end(2,"two");
    list.insert_end(3,"three");
    list.insert_end(4,"four");
    list.insert_end(5,"five");
    list.insert_end(6,"six");
    list.insert_end(7,"seven");
    list.insert_end(8,"eight");
    list.insert_end(9,"nine");
    list.insert_end(0,"zero");

    //checks if the insertation is correct
    cout<<"The firt linked list:"<<endl;
    list.print_All();

    //same thing for the second one
    Sequence<int,string> list2;

    list2.insert_end(10, "ten");
    list2.insert_end(20, "twenty");
    list2.insert_end(30, "thirty");
    list2.insert_end(40, "forty");
    list2.insert_end(50, "fifty");
    list2.insert_end(60, "sixty");
    list2.insert_end(70, "seventy");
    list2.insert_end(80, "eighty");
    list2.insert_end(90, "ninety");
    list2.insert_end(11, "eleven");
    list2.insert_end(12, "twelve");


    //checks if the insertation is correct
    cout<<"\n"<<"The second linked list:"<<endl;
    list2.print_All();
    cout<<"\n\n";

    Sequence<int,string> seqres;
    //creates the seqres objects
    seqres.remove_all();
    //just makeing sure 
    seqres = produce(list, start1, length1, list2, start2, length2, repeat);
    //aplication of the produce function
    seqres.print_All();
    //prints the result linked list 

    //Test 2: the condition where second linked list is bigger than the first one (oppiste of the Test 1)
    seqres.remove_all();

    // List and List 2 are in different places

    seqres = produce(list2, start1, length1, list, start2, length2, repeat);

    seqres.print_All();

    //Test 3: if any of the inputs are 0 or wrong 
       
       //Test 3.1 if any other input is 0  except start1 and start2 

                seqres.remove_all();

                seqres = produce(list, start1, 0, list2, start2, length2, repeat);

                seqres.print_All();

        //Test 3.2 if input linked list or liked lists are empty  

                list2.remove_all();
                //one of the lists are empthy
                seqres.remove_all();

                seqres = produce(list, start1, length1, list2, start2, length2, repeat);

                seqres.print_All();

 
    //Test 4: if start1 or start 2 is 0 (will it start from the 1st '0' element)ü
            
            //refills the list 2 (we cleanse it in 3.2)
        list2.insert_end(10, "ten");
        list2.insert_end(20, "twenty");
        list2.insert_end(30, "thirty");
        list2.insert_end(40, "forty");
        list2.insert_end(50, "fifty");
        list2.insert_end(60, "sixty");
        list2.insert_end(70, "seventy");
        list2.insert_end(80, "eighty");
        list2.insert_end(90, "ninety");
        list2.insert_end(11, "eleven");
        list2.insert_end(12, "twelve");

            //lets check if everything is inserted correctly
            list2.print_All();
            //yes

                seqres.remove_all();

                seqres = produce(list, 0, length1, list2, start2, length2, repeat);

                seqres.print_All();
                
            //test 4.1 same thing for both

                seqres.remove_all();

                 seqres = produce(list, 0, length1, list2, 0, length2, repeat);

                seqres.print_All();


    return 0;
}