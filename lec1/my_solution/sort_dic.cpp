#include <bits/stdc++.h>
#include <fstream>
#include <iostream>

using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i<n;i++)
typedef pair<string,vector<string>> P;


int main() {
    // 単語数は84093



    string filename("../anagram/words.txt");
    vector<string> lines;
    string line;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    while (getline(input_file, line)){
        lines.push_back(line);
    }

    

    input_file.close();


    vector <P> new_dictionary;

    ofstream fout("new_dictionary.txt");

    map  <string,vector <string>> dict_map;




    rep(i,lines.size()){
        string tmp = lines.at(i);
        sort(lines.at(i).begin(),lines.at(i).end());
        
        dict_map[lines.at(i)].push_back(tmp);
     
    }


    for(auto v:dict_map){

        new_dictionary.push_back(make_pair(v.first,v.second));
    }

    sort(new_dictionary.begin(),new_dictionary.end());
    ll new_dictionary_size = new_dictionary.size();



    rep(i,new_dictionary_size){
        fout << new_dictionary.at(i).first << ' ';


        rep(j,new_dictionary.at(i).second.size()){
            fout  << new_dictionary.at(i).second.at(j) <<  ' ';
        }
        fout << endl;
    }

    fout.close();
    return 0;
}

