/* 
 * your comment header here
 */

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    bool success;
    std::string placeholderstring;
    int idholder;
    cout << "Creating the Hash Table...";
    HashTable hashtable;
    cout << "Done." << endl << endl;

    cout << "Checking table size...\n";
    cout << "\tThere are " << hashtable.getCount() << " indexes." << endl;
    hashtable.printTable();
    cout << endl;
    // try and put ALL the test data into the table and show what happens

    // continue using and testing your table, add and remove data,
    // do whatever it takes to full test your object and prove it
    // is robust and can handle all use cases.

    
    // CONT FROM HERE

    //adding all the test data to the hashtable 

    cout << "Populating HashTable..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        success = hashtable.insertEntry(ids[i], &strs[i]);
        if (success) {
            cout << "successfully added " << ids[i] << " : " << strs[i] << endl;
        } else {
            cout << "failed to add " << ids[i] << " : " << strs[i] << endl;
        }
    }

    cout << endl;

    cout << "Checking table size...\n";
    cout << "\tThere are " << hashtable.getCount() << " indexes." << endl;
    hashtable.printTable();
    cout << endl;

    cout << "Random batch id verification part 1..." << endl;
    for (int i = 0; i < HASHTABLESIZE/2; i++) {
        idholder = ids[rand() % testdatasize];
        placeholderstring = hashtable.getData(idholder);
        cout << "Checking for " << idholder << "... ";
        if (placeholderstring.empty()) {
            cout << "failed to find " << idholder << endl;
        } else {
            cout << "found " <<  placeholderstring << endl;
        }
    }

    idholder = MAXID + MAXID;
    cout << "Checking a random id " << idholder << "... ";
    placeholderstring = hashtable.getData(idholder);
    if (placeholderstring.empty()) {
        cout << "failed to find " << idholder << endl;
    } else {
        cout << "found " << idholder << " : " << placeholderstring << endl;
    }
    cout << endl;

    cout << "Random batch id verification part 2..." << endl;
    for (int i = 0; i < HASHTABLESIZE/2; i++) {
        idholder = ids[rand() % testdatasize];
        placeholderstring = hashtable.getData(idholder);
        cout << "Checking for " << idholder << "... ";
        if (placeholderstring.empty()) {
            cout << "failed to find " << idholder << endl;
        } else {
            cout << "found " <<  placeholderstring << endl;
        }
    }
    cout << endl;
    
    
    cout << endl << "Random id removal..." << endl;
    for (int i = 0; i < HASHTABLESIZE/2; i++) {
        idholder = ids[rand() % testdatasize];
        placeholderstring = hashtable.getData(idholder);
        cout << "Checking for " << idholder << "... ";
        if (placeholderstring.empty()) {
            cout << "failed to find " << idholder << endl;
        } else {
            cout << "found " <<  placeholderstring << endl;
            success = hashtable.removeEntry(idholder);
            if (success){
                cout << "removed " << idholder << " and " << placeholderstring << endl;
            }else{
                cout << "failed to remove  " << idholder << endl;
            }
        }
    }
    cout << endl <<  "Finished removing random ids" << endl;
    
    cout << "Checking hashtable...\n";
    cout << "\tThere are " << hashtable.getCount() << " nodes." << endl;
    hashtable.printTable();
    cout << endl;

    cout << "Depopulating HashTable..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        success = hashtable.removeEntry(ids[i]);
        if (success) {
            cout << "successfully removed " << ids[i] << " : " << strs[i] << endl;
        } else {
            cout << "failed to remove " << ids[i] << " : " << strs[i] << endl;
        }
    }
    cout << "Done." << endl << endl;

    cout << "Checking hashtable...\n";
    cout << "\tThere are " << hashtable.getCount() << " nodes." << endl;
    hashtable.printTable();
    cout << endl << "Testing concluded.";

    return 0;
}
