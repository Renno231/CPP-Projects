/*
Name: Renno231
Status: Completed
Description: This program tests the functionality of the Stack class object.
    
*/

#include "main.h"

int main(int argc, char **argv) {
    
    srand(time(NULL));
    int i, success, tmpvalue, stacksize;
    try{
        Data emptydata;
        char *sEnd;
        std::string strtemp;

        if (!argv[1]){
            throw std::underflow_error("Underflow error: missing stacksize argument.");
        }
        if (argc > MAX_ARGUMENTS){
            throw std::overflow_error("Overflow error: only one argument will be accepted and it must be an integer that is 2 or larger.");
        }

        std::string isnumber(argv[1]);
        if (!std::all_of(isnumber.begin(), isnumber.end(), ::isdigit)){
            throw "Type error: argument must be an integer.";
        }

        stacksize = std::strtol(argv[1], &sEnd, 10);
        if (stacksize < MIN_STACK_SIZE){
            throw std::overflow_error("Overflow error: stack size must be 2 or larger.");
        }

        Stack stack(stacksize);
        stacksize = stack.getsize();
        cout << "stack size: " << stack.getsize() << endl;

        sEnd = NULL;
        delete sEnd;
        
        cout << "Beginning tests..." << endl << endl << "Testing push, peak, and pop operations." << endl;
        cout << "================================================" << endl;


        cout << endl << "Testing isempty, peek, size, and pop operations on empty stack" << endl;

        try{
            cout << "What is the stack size? " << stack.getsize() << endl;
        }catch(...){
            cout << "Stack getsize() failed." << endl;
        }
        if (stack.isEmpty()) {
            cout << "stack is empty" << endl;
        } else {
            cout << "stack is NOT empty" << endl;
        }

        if(stack.peek(&emptydata)){
            cout << "peeked: " << emptydata.information << endl;
        } else {
            cout << "peek underflow error: stack is empty" << endl;
        }
        
        success = stack.pop(&emptydata);
        if (success){
            cout << "popped: " << emptydata.information << endl;
        } else{
            cout << "pop underflow error: stack is empty" << endl;
        }
        cout << endl;
        
        cout << "Testing full operations." << endl;
        cout << "================================================" << endl;

        cout << "Filling stack..." << endl;
        for (i = 0; i < stacksize*MULTIPLIER; i++) {
            rand_string(&strtemp);
            rand_int(&tmpvalue);
            
            if (stack.push(tmpvalue, &strtemp)) {
                cout << "pushed: " << strtemp << endl;
            } else {
                cout << "overflow error: " << strtemp << " not pushed" << endl;
            }
        }
        cout << endl << "Checking stack fill...";

        if (stack.isEmpty()) {
            cout << "stack is empty" << endl;
        } else {
            cout << "stack is NOT empty" << endl;
        }
        cout << endl;

        if(stack.peek(&emptydata)){
            cout << "peeked: " << emptydata.information << endl;
        } else {
            cout << "peek underflow error: stack is empty" << endl;
        }
        
        if (stack.pop(&emptydata)){
            cout << "popped: " << emptydata.information << endl;
        } else{
            cout << "pop underflow error: stack is empty" << endl;
        }
        cout << endl;

        cout << "Testing peek and pop by emptying stack..." << endl;
        cout << "================================================" << endl;

        for (i = 0; i < MULTIPLIER*stacksize; i++) {
            
            if(stack.peek(&emptydata)){
                cout << "peeked: " << emptydata.information  << endl;
            } else {
                cout << "peek underflow error: stack is empty" << endl;
            }
            
            if (stack.pop(&emptydata)){
                cout << "popped: " << emptydata.information << endl;
            } else  {
                cout << "pop underflow error: stack is empty" << endl;
            }
        }
        cout << endl;

        if (stack.isEmpty()) {
            cout << "stack is empty" << endl;
        } else {
            cout << "stack is NOT empty" << endl;
        }

        if(stack.peek(&emptydata)){
            cout << "peeked: " << emptydata.information << endl;
        } else {
            cout << "peek underflow error: stack is empty" << endl;
        }
        
        if (stack.pop(&emptydata)){
            cout << "popped: " << emptydata.information << endl;
        } else {
            cout << "pop underflow error: stack is empty" << endl;
        }
        cout << endl;
        
        cout << "Filling stack halfway and testing the middle of the stack..." << endl;
        cout << "===================================================================" << endl;
        for (i = 0; i< stacksize/2; i++) {
            rand_string(&strtemp);
            tmpvalue = rand()%2 ? rand() % MAX_INT/2 + 1 : -(rand() % MAX_INT/2 + 1);
            if (stack.push(tmpvalue, &strtemp)) {
                cout << "pushed: " << strtemp << endl;
            } else {
                cout << "overflow error: " << strtemp << " not pushed" << endl;
            }
        }

        for (i = 0; i< stacksize * FUNNEL; i++) {
            if (stack.isEmpty()) {
                cout << "stack is empty" << endl;
            } else {
                cout << "stack is NOT empty" << endl;
            }
            cout << endl;

            if(stack.peek(&emptydata)){
                cout << "peeked: " << emptydata.information << endl;
            } else {
                cout << "peek underflow error: stack is empty" << endl;
            }
        
            try{ 
                tmpvalue = stack.pop(&emptydata);
                cout << "popped: " << emptydata.information << endl;
            } catch(...){
                cout << "pop underflow error: stack is empty" << endl;
            }
            rand_string(&strtemp);
            rand_int(&tmpvalue);
            if (stack.push(tmpvalue, &strtemp)) {
                cout << "pushed: " << strtemp << endl;
            } else {
                cout << "overflow error: " << strtemp << " not pushed" << endl;
            }
        }
        cout << endl;
        
        cout << "Random testing..." << endl;
        cout << "===================================================================" << endl;

        cout << endl << "Clearing stack..." << endl;
        while(!stack.isEmpty()){
            stack.pop(&emptydata);
        }

        for(i=0; i< MULTIPLIER * stacksize; i++){
            rand_string(&strtemp);
            rand_int(&tmpvalue);
            cout << "pushed " << stack.push(tmpvalue, &strtemp) << " str empty? "  << strtemp.empty() << endl;
            cout << "peeked " << stack.peek(&emptydata) << " " << emptydata.id << " " << emptydata.information << endl;
            cout << "popped " << stack.pop(&emptydata) << " " << emptydata.id << " " << emptydata.information << endl;
        }

        cout << endl << "Clearing stack..." << endl;
        while(!stack.isEmpty()){
            stack.pop(&emptydata);
        }
        if (stack.isEmpty()){
            cout << "Stack emptied!" << endl << endl;
        }

        for (i = 0; i< stacksize / 2; i++) {
            rand_int(&tmpvalue);
            rand_string(&strtemp);
            if (stack.push(tmpvalue, &strtemp)) {
                cout << "pushed: " << strtemp << endl;
            } else {
                cout << "overflow error: " << strtemp << " not pushed" << endl;
            }
        }
        cout << endl << "Random testing cont..." << endl << endl;
        int choice = rand() % CHOICES + 1;
        for (i = 0; i < stacksize*RANDOM_MULTIPLIER; i++) {
            switch (choice) {
                case 1:
                    rand_int(&tmpvalue);
                    rand_string(&strtemp);
                    if (stack.push(tmpvalue, &strtemp)) {
                        cout << "pushed: " << strtemp << endl;
                    } else {
                        cout << "overflow error: " << strtemp << " not pushed" << endl;
                    }
                    break;
                case 2:
                case 3:
                    if (stack.pop(&emptydata)){
                        cout << "popped: " << emptydata.information << endl;
                    } else {
                        cout << "pop underflow error: stack is empty" << endl;
                    }
                    break;
                case 4:
                    
                case 5:

                    if (stack.isEmpty()) {
                        cout << "stack is empty" << endl;
                    } else {
                        cout << "stack is NOT empty" << endl;
                    }
                    break;
                case 6:
                
                    if(stack.peek(&emptydata)){
                        cout << "peeked: " << emptydata.information << endl;
                    } else {
                        cout << "peek underflow error: stack is empty" << endl;
                    }
                    break;
                case 7:
                    if (stack.pop(&emptydata)){
                        cout << "popped: " << emptydata.information << endl;
                    } else {
                        cout << "pop underflow error: stack is empty" << endl;
                    }
                    break;
            }
            choice = rand() % CHOICES + 1;

        }
        cout << endl;
        
        cout << "Testing complete." << endl;
    }catch(std::exception& e){
        cout << e.what() << endl;
    }catch(const char* catchstring){
        cout << catchstring << endl;
    }catch(...){
        cout << "An unknown error has occurred." << endl;
    }

    return 0;
}
