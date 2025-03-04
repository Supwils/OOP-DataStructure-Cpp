//
//  main.cpp
//  cis554hw8
//
//  Created by 尚华豪 on 4/21/22.
//
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <unordered_map>
using namespace std;
class Circuit{
public:
    string* name;
    int inputNum;
    int outputNum;
    vector<string> inputAndoutput;
    vector<vector<int>> truthtable;
    int sum;
    
    
};
class myFunctorClass{
public:
    size_t operator()(const Circuit& C)const{
//        int sum;
//        sum = C.inputNum +C.outputNum;
//        int sum = 0;
//        for(int i = 0; i<C.inputNum+1;i++){
//            for (int j = 0; j<C.outputNum+1; j++){
//                sum += (C.truthtable[i][j])*(j+1);
//            }
//        }
        return hash<int>{}(C.sum);
    }
    bool operator()(const Circuit& C1, const Circuit& C2)const{
        return C1.inputNum == C2.inputNum && C1.outputNum == C2.outputNum;
    }
};
void Add(unordered_map<Circuit, string*, myFunctorClass, myFunctorClass> &DB, const Circuit& C);
void Find(unordered_map<Circuit, string*,myFunctorClass, myFunctorClass> &DB, const Circuit& C);
void Delete(unordered_map<Circuit, string*,myFunctorClass, myFunctorClass> &DB, const Circuit& C);
ostream& operator<<(ostream& str, unordered_map<Circuit, string*, myFunctorClass, myFunctorClass> &DB);
ostream& operator<<(ostream& str, Circuit& C);
ostream& operator<<(ostream& str, unordered_map<Circuit, string*, myFunctorClass, myFunctorClass> &DB){
    cout<<endl;
    cout<<"Print the Database"<<endl;
    for (auto it = DB.begin(); it != DB.end(); it++){
        auto cir = it->first;
        cout<<*cir.name<<endl;
        cout<<cir.inputNum<<endl;
        cout<<cir.outputNum<<endl;
        for (int i = 0; i < cir.inputAndoutput.size();i++){
            cout<<cir.inputAndoutput[i]<<endl;
        }
        cout<<endl;
        
//        for (auto& level:it->first.truthtable){
//            for (auto& level2:level){
//                cout<<level2;
//            }
//            cout<<" ";
//        }
    }
    return str;
}
ostream& operator<<(ostream& str, const Circuit& C){
    cout<<*C.name<<endl;
    cout<<C.inputNum<<endl;
    cout<<C.outputNum<<endl;
    //int num = pow(2,C.inputNum);
    for (int i = 0; i<C.inputAndoutput.size(); i++){
        cout<<C.inputAndoutput[i]<<endl;
    }
    return str;
}


void Add(unordered_map<Circuit, string*, myFunctorClass, myFunctorClass> &DB, const Circuit& C){
//    if (DB.size() == 0) {
//        pair<Circuit,   string*> theC = {C,C.name};
//        DB.insert({C,C.name});
//    }
    for(auto& circuit:DB){
        if (C.sum == circuit.first.sum && C.inputNum == circuit.first.inputNum && C.outputNum == circuit.first.outputNum){
            cout<<*C.name<<" "<<"is not added, there is a re-useable circuit "<< *circuit.second<<" and shown below"<<endl;
            cout<<circuit.first<<endl;
            return;
            //cout<<circuit<<endl;
            
        }
    }
    DB.insert({C,C.name});
    cout<<*C.name<<" is added to the database."<<endl;
    
}


void Find(unordered_map<Circuit, string*, myFunctorClass, myFunctorClass>& DB, const Circuit& C){
    for (auto& circuit:DB){
        if (circuit.first.sum == C.sum && circuit.first.inputNum == C.inputNum && circuit.first.outputNum == C.outputNum){
            cout<<*C.name<<" has a re-useable circuit, "<<*circuit.second<<", whose truth table is shown below."<<endl;
            cout<<circuit.first<<endl;
            return;
        }
    }
    cout<<*C.name<<" does not have any reusable circuit in the database."<<endl;
}

void Delete(unordered_map<Circuit, string*,myFunctorClass, myFunctorClass> &DB, const Circuit& C){
    for (auto& circuit:DB){
        if (circuit.first.sum == C.sum && circuit.first.inputNum == C.inputNum && circuit.first.outputNum == C.outputNum){
            delete circuit.second;
            //DB.erase(hash<int>{}(circuit.first.sum));
            cout<<*C.name<<" has a re-useable circuit, "<<*circuit.second<<", in the database, whose truth table is shown below and "<<*circuit.second<<" deleted from the database"<<endl;
            cout<<circuit.first<<endl;
            DB.erase(circuit.first);
            return;
        }
    }
    cout<<*C.name<<"dose not have any re-useable circuit in the database"<<endl;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<string>> data;
    unordered_map<Circuit,string*,myFunctorClass, myFunctorClass> DB;
    ifstream Input;
    Input.open("input.txt", ios::in);
    string l1;
    getline(Input, l1);
    int operationNum = stoi(l1);
    for (int i = 0; i<operationNum;i++){
        string operation,name,inputNum, outputNum;
        getline(Input, operation);
        getline(Input, name);
        getline(Input, inputNum);
        getline(Input, outputNum);
        vector<string> aCircuit;
        aCircuit.push_back(operation);
        aCircuit.push_back(name);
        aCircuit.push_back(inputNum);
        aCircuit.push_back(outputNum);
        int inputNumInt = stoi(aCircuit[2]);
        int tableSize = pow(2,inputNumInt);
        for (int i = 0; i < tableSize; i++){
            string inputAndOutput;
            getline(Input, inputAndOutput);
            aCircuit.push_back(inputAndOutput);
        }
        data.push_back(aCircuit);
    }
    Input.close();
    for (int i  = 0; i < operationNum; i++){
        Circuit C;
        C.name = new string {data[i][1]};
        C.inputNum = stoi(data[i][2]);
        C.outputNum = stoi(data[i][3]);
        vector<string> inAndout;
        for (int j = 4; j<data[i].size(); j++){
            inAndout.push_back(data[i][j]);
        }
        C.inputAndoutput = inAndout;
        vector<vector<int>> TB;
        for (int k = 0; k<C.inputNum+1;k++){
            vector<int> item(C.outputNum+1,0);
            TB.push_back(item);
        }
        for (int m = 0; m<inAndout.size(); m++){
            string tb = inAndout[m];
            string input = tb.substr(0,C.inputNum);
            string output = tb.substr(C.inputNum,C.outputNum);
            int inputIndex = 0, outputIndex = 0;
            for (auto& achar1:input) {
                if (achar1 == '1') inputIndex++;
            }
            for (auto& achar2:output){
                if (achar2 == '1') outputIndex++;
            }
            TB[inputIndex][outputIndex]++;
        }
        C.truthtable = TB;
        int sum = 0;
        for(int i = 0; i<C.inputNum+1;i++){
            for (int j = 0; j<C.outputNum+1; j++){
                sum += (C.truthtable[i][j])*(j+1);
            }
        }
        C.sum = sum;
        string Operation = data[i][0];
        if (Operation == "Add") {
            Add(DB, C);
            
           // break;
        }
        if (Operation == "Find"){
            Find(DB,C);
        }
        if(Operation == "Delete"){
            Delete(DB,C);
        }
    }
    cout<<DB;
        
    
//
//    cout<<data[1][1]<<endl;
//    string a = "122";
//    int ab = stoi(a);
//    cout<<ab<<endl;
    
    return 0;
}
