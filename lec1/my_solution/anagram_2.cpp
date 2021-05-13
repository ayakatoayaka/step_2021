#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i<n;i++)
typedef pair<int,int> P;
string solution(map<char,ll>);
vector<ll> find_all(string str,string subStr);

int main(int argc,char* argv[]) {


    if(argc!=2){
        cout << "Please input correct form." << endl;
    }


    string filename("../anagram/"+(string)argv[1]);
    vector<string> ans_vec;
    string line;


    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    while (getline(input_file, line)){
        map<char,ll> tmp_map;
        rep(i,line.size()){
            tmp_map[line.at(i)]++;
        }

        string ans=solution(tmp_map);
        ans_vec.push_back(ans);
        
    }

    input_file.close();


    ofstream fout("answer_"+(string)argv[1]);

    rep(i,ans_vec.size()){
        fout << ans_vec.at(i) << endl;
    }


    fout.close();
    return 0;

}

string solution(map<char,ll> s_map){

    string filename("new_dictionary_2.txt");

    string line;

    ifstream input_file(filename);

    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return "Error!";
    }

    while (getline(input_file, line)){
        
        vector<ll> separator = find_all(line,",");
        map<char,ll> tmp_map;

        string tmp_str=line.substr(separator.at(1)+1,(ll)line.size()-separator.at(1));
        

        rep(i,(ll)tmp_str.size()/4){
            tmp_map[tmp_str.at(i*4)]=tmp_str.at(i*4+2)-'0';
        }

        bool torf=true;
        for(auto v:tmp_map){
            if(s_map[v.first]<v.second)
                torf=false;
        }

        if(torf){
            input_file.close();
            return line.substr(separator.at(0)+1,separator.at(1)-separator.at(0)-1);
        }

        
    }

    input_file.close();
    return "This word doesn't have anagram!";
}

vector<ll> find_all(string str,string subStr) {
    vector<ll> result;
 
    int subStrSize = subStr.size();
    int pos = str.find(subStr);
 
    while (pos !=-1) {
        result.push_back(pos);
        pos = str.find(subStr, pos + subStrSize);
    }
 
    return result;
}