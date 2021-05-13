#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i<n;i++)
typedef pair<string,string> P;
vector <string> solution(string s);
vector<ll> find_all(string,string);

int main() {
    string s,origin;
    cout << "Input please:";
    cin >> s;
    origin=s;
    sort(s.begin(),s.end());
    vector <string> ans = solution(s);


    if(ans.size()==1 || ans.size()==2)
        cout << "This word doesn't have anagram!" << endl;
    else{
        cout << "Anagram:";
        rep(i,ans.size()){
            cout << (ans.at(i)==origin?"":ans.at(i)+' ');
        }
        cout << endl;
    }
}


vector <string> solution(string s){
    string filename("new_dictionary.txt");
    vector<string> sorted_str;
    vector<vector<string>> origin_str_vec;
    string line;

    ifstream input_file(filename);
    //cout << 123 << endl;
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return {""};
    }

    while (getline(input_file, line)){
        vector<ll> separator = find_all(line," ");
        separator.push_back(line.size());
        sorted_str.push_back(line.substr(0,separator.at(0)));
        origin_str_vec.push_back({});
        // cout << b.at((ll)a.size()-1).size() << endl;
        rep(i,(ll)separator.size()-1){
            origin_str_vec.at((ll)sorted_str.size()-1).push_back(line.substr(separator.at(i)+1,separator.at(i+1)-separator.at(i)-1));
        }
        

    }

    // ファイルってクローズしないとどうなるの？
    // cout << lower_bound(dict_pair.begin(),dict_pair.end(),s)-dict_pair.begin() << endl;
    input_file.close();
    if(!binary_search(sorted_str.begin(),sorted_str.end(),s)){
        return {"This word doesn't have anagram!"};
    }


    
    return origin_str_vec.at(lower_bound(sorted_str.begin(),sorted_str.end(),s)-sorted_str.begin());
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