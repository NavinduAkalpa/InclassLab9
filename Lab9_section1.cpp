#include <cstring>
#include <string>
#include <iostream>
using namespace std;


struct HashTable{
    int MAX_LENGTH = 4;
    string * password = new string[MAX_LENGTH];

    void intialize_hashtable(){
        for (int i = 0; i < 4; i++){
            password[i].clear();
        }
    }

    bool isFull(){
        bool full = true;
        int count = 0;
        for (int i = 0; i < MAX_LENGTH; i++){
            if(password[i].empty()){
                full = false;
            }
        }
        return full;
    }

    int hashfunc(string user_name){
        int sum = 0;
        int hash = 0;
        for(int i=0;i<user_name.length();i++){
            sum += user_name[i];
        }
        hash = sum % MAX_LENGTH;

        return hash;
    }

    bool is_slot_empty(int hash){
        bool empty = password[hash].empty();
        return empty;
    }

    void insert(string user_name,string user_password){
        int hash;
        bool empty;
        hash = hashfunc(user_name);
        empty = is_slot_empty(hash);
        if(empty){
            password[hash] = user_password;
            cout<<"User inserted\n";
        }
        else{
            cout<<"Hash slot already occupied\n";
        }
    }

    void hash_lookup(string user_name){
        int hash;
        bool empty;
        hash = hashfunc(user_name);
        empty = is_slot_empty(hash);
        if(empty){
            cout<<"User not found\n";
        }
        else{
            cout<<"User password: "<<password[hash]<<"\n";
        }
    }

    void delete_item(string user_name){
        int hash;
        bool empty;
        hash = hashfunc(user_name);
        empty = is_slot_empty(hash);
        if(empty){
            cout<<"User not found\n";
        }
        else{
            password[hash].clear();
            cout<<"User deleted\n";
        }

    }

    void print_hashtable(){
        for(int i=0;i<MAX_LENGTH;i++){
            cout<<"["<<i<<"]-->"<<password[i]<<"\n";
        }
    }

};


int main(){
    HashTable * hashtbl = new HashTable;
    hashtbl->intialize_hashtable();
    cout<< hashtbl->isFull()<<"\n";

    int command=0;
    string user_name;
    string password;
    while (command!=-1){
        /* code */
        cout << "Type command: ";
        cin >> command;
        switch (command){
        case 1:
        
            cout << "Enter user name: ";
            cin >> user_name;
            cout << "Enter password to be saved: ";
            cin >> password;
            hashtbl->insert(user_name,password);
            break;
        case 2:
        
            cout << "Enter item to be deleted: ";
            cin >> user_name;
            hashtbl->delete_item(user_name);
            break;
        case 3:
        
            cout << "Enter user name to look up password:";
            cin >> user_name;
            hashtbl->hash_lookup(user_name);
            break;
        case 4:
            hashtbl->print_hashtable();
            break;
        case -1:
        
            cout << "Exiting...\n";
            break;
        
        }

    
    }
    return 0;
}