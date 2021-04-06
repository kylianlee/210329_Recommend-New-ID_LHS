//
// Created by Kylian Lee on 2021/03/29.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id);

int main() {
    string new_id;
    string answer;

    cin >> new_id;

//    cout << new_id << endl;

    answer = solution(new_id);

    cout << answer << endl;

    return 0;
}

string solution(string new_id){
    string answer;

    int length = new_id.length();

    for(int i = 0; i < length; i++) {
        char tmp = new_id[i];
//        cout << "new_id[" << i << "] = " << new_id[i] << endl;
        new_id[i] = tolower(tmp);
//        cout << "new_id[" << i << "] = " << new_id[i] << endl;

        tmp = new_id[i];

        if((tmp < 'a' || tmp > 'z') && (tmp < '0' || tmp > '9') && (tmp != '-' && tmp != '_' && tmp != '.')){
            new_id.erase(i, 1);
            i--, length--;
        }
    }

    length = new_id.length();

    for(int i = 0; i < length; i++){
        if(new_id[i] == '.'){
            int j = i + 1;
            while(new_id[j] == '.')
                j++;

            if(j - i > 1)
                new_id.erase(i, j - i - 1);
            length -= j - i;

        }
//        cout << new_id << endl;
    }

    if(new_id[0] == '.')
        new_id.erase(0, 1);
    if(new_id[new_id.length() - 1] == '.')
        new_id.pop_back();

    if(new_id.empty())
        new_id.push_back('a');

    if(new_id.length() > 15)
        new_id.erase(15, new_id.length() - 15);
    if(new_id[new_id.length() - 1] == '.')
        new_id.pop_back();

    if(new_id.length() <3)
        while(new_id.length() != 3)
            new_id.push_back(new_id[new_id.length() - 1]);

    answer = new_id;

    return answer;
}
