//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

string arr[1501]1501];

int desi = 0;
int layer_id[41], anal_id[41];
int now_id = 0;

int line=0, ind=0;
int des_line = 0;
vector<string> print;

int main() {_
    string s;
    int ind = -1;
    bool ERR = false;

    do{
        line++;
        getline(cin,s);

        if(s == "end") break;

        int i=0;

        //cout<<s<<"\n";

        while(s[i*2] == ' ' and s[i*2+1] == ' ') i++;
        if((i > ind+1) || (s[i*2] == ' ')){
                ERR = true; break;
        }else if(i == ind+1){
            layer_id[i] = anal_id[i] = now_id;
        }else if(i < ind){
            now_id = layer_id[i+1];
        }

        int j=s.length()-1;
        while(s[j] == ' ') j--;

        string s_trim = s.substr(i*2, j-i*2+1);


        if(s_trim == "safe"){
            string anal = "";
            for(int j=0; j<i; j++) anal+="  ";
            anal += "!!!Analyze(";

            //cout<<anal_id[i]<<"\n";
            //cout<<"cun\n";
            //for(int j=0; j<now_id; j++) cout<<arr[j]<<" ";
            //cout<<"\n";

            for(int j=anal_id[i]; j<now_id; j++) anal+=arr[j]+",";
            if(anal[anal.length()-1] == '(') anal.resize(anal.size()+1);
            anal[anal.size()-1]=')';
            print.push_back(anal);

            anal_id[i] = now_id;

        }else if(s_trim=="emptyline"){
            if(des_line == 0) des_line = line;
            else{
                des_arr[desi++] = ((des_line == line-1)?"emptyline\n":("//Describe("+to_string(des_line+1)+","+to_string(line-1)+")\n"));

                des_line = line;
            }

            print.push_back("");

            now_id = 0;
            ind = -1;

            continue;


        }else{
            print.push_back(s);
            arr[now_id++] = s_trim;
        }

        ind = i;


    }while(s!="end");

    if(ERR){
        cout<<"ERR!\n";
    }else{

        if(des_line != 0){
            des_arr[desi++] = ((des_line == line-1)?"emptyline\n":("//Describe("+to_string(des_line+1)+","+to_string(line-1)+")\n"));
        }

        int parse_id = 0;
        for(int j=0; j<print.size(); j++){
            if(print[j] == "") cout<<des_arr[parse_id++];
            else cout<<print[j]<<"\n";
        }

    }

    return 0;
}
//maybe its multiset not set

/*
emptyline
ln2
ln3
  ln4
  ln5
    ln6
    ln7
    ln8
    safe
    ln10
    safe
    ln12
  ln13
  ln14
  safe
ln16
emptyline
emptyline
ln19
  ln20
safe
end
*/

